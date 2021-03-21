#include "Sphere.h"

Sphere::Sphere(Vector3 center, double radius)
{
	this->center = center;
	this->radius = radius;
}

bool Sphere::hit(const Ray& ray, double t_min, double t_max, hit_result& result) const
{
    Vector3 oc = ray.origin - center;
    double a = ray.direction.LengthSquared();
    double half_b = Vector3::Dot(oc, ray.direction);
    double c = oc.LengthSquared() - radius * radius;

    double hitresult = half_b * half_b - a * c;
    if (hitresult < 0) return false;
    double sqrt_hitresult = sqrt(hitresult);

    double root = (-half_b - sqrt_hitresult) / a;

    if (root < t_min || t_max < root) {
        root = (-half_b + sqrt_hitresult) / a;
        if (root < t_min || t_max < root) {
            return false;
        }
    }

    result.t = root;
    result.point = ray.at(result.t);
    Vector3 normal = (result.point - center) / radius;
    result.set_face_normal(ray, normal);

    return true;

}
