#ifndef HITTABLE_LIST_H
#define HITTABLE_LIST_H

#include "Hittable.h"
#include <iostream>
#include <vector>

class Hittable_list : public Hittable {

	public:

		std::vector<std::shared_ptr<Hittable>> objects;

		Hittable_list() {}
		Hittable_list(std::shared_ptr<Hittable> object);

		void clear();
		void add(std::shared_ptr<Hittable> object);

		virtual bool hit(const Ray& ray, double t_min, double t_max, hit_result& result) const;

};

#endif