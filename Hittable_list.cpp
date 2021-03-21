#include "Hittable_list.h"

Hittable_list::Hittable_list(std::shared_ptr<Hittable> object)
{
    this->add(object);
}

void Hittable_list::clear()
{
    this->objects.clear();
}

void Hittable_list::add(std::shared_ptr<Hittable> object)
{
    this->objects.push_back(object);
}

bool Hittable_list::hit(const Ray& ray, double t_min, double t_max, hit_result& result) const
{
    hit_result temp_result;
    bool hit = false;
    double closest = t_max;

    for (const std::shared_ptr<Hittable> object : this->objects) {

        if (object->hit(ray, t_min, closest, temp_result)) {
            hit = true;
            closest = temp_result.t;
            result = temp_result;
        }

    }

    return hit;

}
