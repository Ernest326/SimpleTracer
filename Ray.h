#ifndef RAY_H
#define RAY_H

#include "Vector3.h"

struct Ray
{
	Vector3 origin = Vector3(0,0,0);
	Vector3 direction = Vector3(0,0,0);

	Ray() {};
	Ray(const Vector3& origin, const Vector3& direction) {
		this->origin = origin;
		this->direction = direction;
	}

	Vector3 at(float t) const {
		return origin + direction * t;
	}

};

#endif