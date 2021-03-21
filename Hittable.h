#ifndef HITTABLE_H
#define HITTABLE_H

#include "Vector3.h"
#include "Ray.h"

struct hit_result {

	Vector3 point;
	Vector3 normal;
	double t;
	bool front_face;

	//Makes normal always point outside the sphere
	inline void set_face_normal(const Ray& ray, const Vector3& outward_normal) {
		front_face = Vector3::Dot(ray.direction, outward_normal) < 0;
		normal = front_face ? outward_normal : outward_normal*-1;
	}

};

class Hittable {

	public:
		virtual bool hit(const Ray& ray, double t_min, double t_max, hit_result& result) const = 0;

};

#endif