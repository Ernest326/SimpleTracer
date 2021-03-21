#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>

class Utils {

	public:
	
		static std::string lower(std::string input) {

			std::transform(input.begin(), input.end(), input.begin(), [](unsigned char c) {return std::tolower(c); });
			return input;

		}

		static std::vector<std::string> split(std::string line, char chr) {
	
			std::stringstream ss;
			ss << line;
			std::vector<std::string> result;
			std::string segment;
	
			while (std::getline(ss, segment, chr)) {
				result.push_back(segment);
			}
	
			return result;
	
		}
	
		static bool file_exists(const std::string& name) {
			std::ifstream file(name.c_str());
			return file.good();
		}

		static Hittable_list get_map_from_file(const std::string& filename) {

			Hittable_list result;

			if (file_exists(filename)) {

				std::ifstream mapfile(filename);

				std::string line;
				while (std::getline(mapfile, line)) {

					std::vector<std::string> split = Utils::split(line, ';');

					if (Utils::lower(split[0]) == "sphere") {

						std::vector <std::string> parameters = Utils::split(split[1], ',');

						Vector3 pos;
						double radius;

						try {
							double x = std::stod(parameters[0].c_str());
							double y = std::stod(parameters[1].c_str());
							double z = std::stod(parameters[2].c_str());
							
							pos = Vector3(x, y, z);

						} 
						catch(...) {
							pos = Vector3(0, 0, 0);
						}

						try {
							radius = std::stod(parameters[3].c_str());
						}
						catch (...) {
							radius = 1;
						}

						result.add(std::make_shared<Sphere>(pos, radius));

					}

				}

			}
			else {
				std::cout << "Could not find the map with the name: \"" << filename << "\"!" << std::endl;
				system("PAUSE");
				exit(1);
			}

			return result;

		}
};


#endif