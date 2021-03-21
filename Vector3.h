#ifndef VECTOR3_H
#define VECTOR3_H

#include <iostream>
#include "Math.h"

struct Vector3
{
	double x;
	double y;
	double z;

	Vector3();
	Vector3(double x, double y, double z);
	~Vector3();

	inline Vector3& multiply(Vector3 other);
	inline Vector3& divide(Vector3 other);
	inline Vector3& add(Vector3 other);
	inline Vector3& subtract(Vector3 other);

	inline Vector3& multiply(double other);
	inline Vector3& divide(double other);

	friend Vector3 operator*(Vector3 left, const Vector3& right);
	friend Vector3 operator/(Vector3 left, const Vector3& right);
	friend Vector3 operator+(Vector3 left, const Vector3& right);
	friend Vector3 operator-(Vector3 left, const Vector3& right);

	friend Vector3 operator*(Vector3 left, const double& right);
	friend Vector3 operator/(Vector3 left, const double& right);


	Vector3 operator*=(const Vector3& other);
	Vector3 operator/=(const Vector3& other);
	Vector3 operator+=(const Vector3& other);
	Vector3 operator-=(const Vector3& other);

	Vector3 operator*=(const double other);
	Vector3 operator/=(const double other);

	friend std::ostream & operator<<(std::ostream& stream, const Vector3& vector) {
		return stream << vector.x << "," << vector.y << "," << vector.z;
	}

	double Length() const {
		return sqrt(x * x + y * y + z * z);
	}

	inline double LengthSquared() const {
		return (x * x + y * y + z * z);
	}

	inline Vector3 Normalize() {
		return divide(this->Length());
	}

	static Vector3 Normalize(Vector3 vector) {
		return vector / vector.Length();
	}

	inline static double Dot(const Vector3& vector, const Vector3& vector2) {
		return vector.x * vector2.x + vector.y * vector2.y + vector.z * vector2.z;
	}

	static Vector3 Cross(const Vector3 &vector, const Vector3 &vector2) {
		return Vector3(vector.y * vector2.z - vector.z * vector2.y, vector.z * vector2.x - vector.x * vector2.z, vector.x * vector2.y - vector.y * vector2.x);
	}

	inline static Vector3 Random() {
		return Vector3(Math::random_double(), Math::random_double(), Math::random_double());
	}

	inline static Vector3 Random(double min, double max) {
		return Vector3(Math::random_double(min, max), Math::random_double(min, max), Math::random_double(min, max));
	}

	inline static Vector3 random_unit_in_sphere() {
		while (true) {
			Vector3 x = Vector3::Random(-1, 1);
			if (x.LengthSquared() >= 1) continue;
			return x;
		}
	}

	static Vector3 random_in_hemisphere(const Vector3& normal) {
		Vector3 in_unit_sphere = random_unit_in_sphere();
		if (Vector3::Dot(in_unit_sphere, normal) > 0.0)
			return in_unit_sphere;
		else
			return in_unit_sphere*-1;
	}

	Vector3 toColor();
	Vector3 toColor(int samples);
	static Vector3 toColor(Vector3 target);
	static Vector3 toColor(Vector3 target, int samples);

};

#endif