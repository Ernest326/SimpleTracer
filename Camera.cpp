#include "Camera.h"

Camera::Camera(float aspect_ratio, float viewport_height, float focal_length, Vector3 origin)
{
	this->aspect_ratio = aspect_ratio;
	this->viewport_height = viewport_height;
	this->viewport_width = viewport_height * aspect_ratio;
	this->focal_length = focal_length;
	this->origin = origin;
}

Camera::Camera(Vector3 origin, float focal_length)
{
	this->origin = origin;
	this->focal_length = focal_length;
}

Camera::Camera(Vector3 origin)
{
	this->origin = origin;
}
