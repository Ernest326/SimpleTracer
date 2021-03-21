#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "Vector3.h"
#include "Ray.h"
#include "Hittable_list.h"
#include "Sphere.h"
#include "Math.h"
#include "Camera.h"
#include "Utils.h"

//This is required for creating the png file
#define STBI_MSC_SECURE_CRT
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "include/stb_image_write.h"

//Alpha channels for writing png file (RGB)
#define CHANNEL_NUM 3

//Coloring a point in a ray
Vector3 ray_color(const Ray& ray, const Hittable& world, int bounce) {

    hit_result result;

    if (bounce <= 0)
        return Vector3(0, 0, 0);

    //Check if object is hit
    if (world.hit(ray, 0.001, Math::infinity(), result)) {
        //If we hit an object, choose a random point, pointing out of the sphere and return if we hit something in that direction
        Vector3 target = result.point + Vector3::random_in_hemisphere(result.normal);
        return ray_color(Ray(result.point, target - result.point), world, bounce - 1) * 0.5;
    }

    //Get direction of ray
    Vector3 unitDirection = ray.direction;
    unitDirection = unitDirection.Normalize();

    //Lerp the value between 0 and 1 where 0 = bottom and 1 = top
    float t = 0.5 * (unitDirection.y + 1.0); 
    
    //Add color and multiply it by the blend value t to create a gradient
    return Vector3(1, 1, 1) * (1.0 - t) + Vector3(0.5, 0.7, 1.0) * t;
}

int main()
{   

    //Settings
    const float aspect_ratio = 16.0 / 9.0;
    const int image_width = 600;
    const int image_height = image_width / aspect_ratio;
    const bool show_progress = true;
    const int samples = 100;
    const int maxBounces = 50;

    //Camera Settings
    Camera mainCamera;

    //Data for output
    uint8_t* pixels = new uint8_t[image_width * image_height * CHANNEL_NUM];
    std::vector<std::string> ppm_data;

    //File stream for outputing the ppm file
    std::fstream ppm_file;

    //Add the first 3 settings line for ppm file output
    ppm_data.push_back("P3"); //Tells that the ppm format is in ASCII
    ppm_data.push_back(std::to_string(image_width) + " " + std::to_string(image_height)); //Width and Height of data
    ppm_data.push_back("255"); //Max color value

    //Index for pixels
    int index = 0;

    //Progress
    int progress = 0;
    int progressUpdateDelay = 10;
    int maxprogress = image_width * image_height;

    std::string filename;
    std::cout << "Enter the map filename: ";
    std::cin >> filename;

    //Add objects
    Hittable_list world = Utils::get_map_from_file(filename);

    //world.add(std::make_shared<Sphere>(Vector3(0, -100.5, -1), 100));
    //world.add(std::make_shared<Sphere>(Vector3(0, 0, -1), 0.5));

    std::cout << "Starting rendering..." << std::endl;

    //Start setting data for ppm and png
    for (int y = image_height - 1; y >= 0; --y) {
        for (int x = 0; x < image_width; ++x) {

            Vector3 color(0, 0, 0);

            for (int s = 0; s < samples; ++s) {

                double u = double(x + Math::random_double()) / (image_width - 1);
                double v = double(y + Math::random_double()) / (image_height - 1);

                Ray ray = mainCamera.get_ray(u, v);
                color += ray_color(ray, world, maxBounces);

            }
            
            color = color.toColor(samples);

            //Add pixel data for png in GBR(y,z,x)
            pixels[++index] = color.y;
            pixels[++index] = color.z;
            pixels[++index] = color.x;

            //Add rgb data for ppm
            ppm_data.push_back(std::to_string(color.x) + " " + std::to_string(color.y) + " " + std::to_string(color.z));

            //Progress bar
            progress++;
            if (progress > 0 && show_progress)
                if(progress%progressUpdateDelay==0 || progress>=maxprogress)
                    std::cerr << "\rProgress: " << int((100 / float(maxprogress)) * progress) << "/100" << ' ' << std::flush;

        }
    }

    std::cout << "Rendering has been complete" << std::endl;

    //Save the png file of the render
    stbi_write_png("render.png", image_width, image_height, CHANNEL_NUM, pixels, CHANNEL_NUM * image_width);
    std::cout << "Render image has been saved!" << std::endl;

    //Writing the ppm file
    ppm_file.open("output.ppm", std::ios::out);
    if (!ppm_file) {
        std::cout << "Failed to output the ppm file!" << std::endl;
    }
    else {
        for (std::string line : ppm_data) {
            ppm_file << line + "\n";
        }
        ppm_file.close();
        std::cout << "Successfully created ppm file!" << std::endl;
    }

    system("PAUSE");

    exit(0);

}
