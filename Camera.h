#ifndef CAMERA_H
#define CAMERA_H

#include "Vector3.h"
#include "Ray.h"

class Camera {

	private:

		float aspect_ratio = 16.0 / 9.0;
		float viewport_height = 2.0;
		float viewport_width = aspect_ratio * viewport_height;
		float focal_length = 1.0;

		Vector3 origin = Vector3(0,0,0);
		Vector3 horizontal = Vector3(viewport_width, 0, 0);
		Vector3 vertical = Vector3(0, viewport_height, 0);
		Vector3 lower_left_corner = origin - horizontal/2 - vertical/2 - Vector3(0, 0, focal_length);

	public:

		Camera() {};
		Camera(float aspect_ratio, float viewport_height, float focal_length, Vector3 origin);
		Camera(Vector3 origin, float focal_length);
		Camera(Vector3 origin);

		Ray get_ray(double u, double v) const {
			return Ray(origin, lower_left_corner + horizontal * u + vertical * v - origin);
		}

};

#endif