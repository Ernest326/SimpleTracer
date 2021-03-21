#ifndef SPHERE_H
#define SPHERE_H

#include "Hittable.h"

class Sphere : public Hittable
{
public:

	Vector3 center;
	double radius;

	Sphere() {};
	Sphere(Vector3 center, double radius);

	virtual bool hit(const Ray& ray, double t_min, double t_max, hit_result& result) const;
};

#endif