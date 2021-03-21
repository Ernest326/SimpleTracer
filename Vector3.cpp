#include "Vector3.h"

Vector3::Vector3()
{
	this->x = 0;
	this->y = 0;
	this->z = 0;
}

Vector3::Vector3(double x, double y, double z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

Vector3::~Vector3()
{
}

Vector3& Vector3::multiply(Vector3 other)
{
	this->x *= other.x;
	this->y *= other.y;
	this->z *= other.z;

	return *this;
}

Vector3& Vector3::divide(Vector3 other)
{
	this->x /= other.x;
	this->y /= other.y;
	this->z /= other.z;

	return *this;
}

Vector3& Vector3::add(Vector3 other)
{
	this->x += other.x;
	this->y += other.y;
	this->z += other.z;

	return *this;
}

Vector3& Vector3::subtract(Vector3 other)
{
	this->x -= other.x;
	this->y -= other.y;
	this->z -= other.z;
	
	return *this;
}

Vector3& Vector3::multiply(double other)
{
	this->x *= other;
	this->y *= other;
	this->z *= other;

	return *this;
}

Vector3& Vector3::divide(double other)
{
	this->x /= other;
	this->y /= other;
	this->z /= other;

	return *this;
}

Vector3 operator*(Vector3 left, const Vector3& right)
{
	return left.multiply(right);
}

Vector3 operator/(Vector3 left, const Vector3& right)
{
	return left.divide(right);
}

Vector3 operator+(Vector3 left, const Vector3& right)
{
	return left.add(right);
}

Vector3 operator-(Vector3 left, const Vector3& right)
{
	return left.subtract(right);
}

Vector3 operator*(const Vector3& left, double right)
{
	return Vector3();
}

Vector3 operator/(const Vector3& left, double right)
{
	return Vector3();
}

Vector3 operator*(Vector3 left, const double& right)
{
	return left.multiply(right);
}

Vector3 operator/(Vector3 left, const double& right)
{
	return left.divide(right);
}

Vector3 Vector3::operator*=(const Vector3& other)
{
	return this->multiply(other);
}

Vector3 Vector3::operator/=(const Vector3& other)
{
	return this->divide(other);
}

Vector3 Vector3::operator+=(const Vector3& other)
{
	return this->add(other);
}

Vector3 Vector3::operator-=(const Vector3& other)
{
	return this->subtract(other);
}

Vector3 Vector3::operator*=(const double other)
{
	return this->multiply(other);
}

Vector3 Vector3::operator/=(const double other)
{
	return this->divide(other);
}

Vector3 Vector3::toColor()
{
	double r = this->x;
	double g = this->y;
	double b = this->z;

	r = Math::clamp(int(256 * r), 0, 255);
	g = Math::clamp(int(256 * g), 0, 255);
	b = Math::clamp(int(256 * b), 0, 255);

	return Vector3(r, g, b);

}

Vector3 Vector3::toColor(int samples)
{

	double r = this->x;
	double g = this->y;
	double b = this->z;

	double scale = 1.0 / samples;

	r = sqrt(scale * r);
	g = sqrt(scale * g);
	b = sqrt(scale * b);

	r = Math::clamp(int(256 * r), 0, 255);
	g = Math::clamp(int(256 * g), 0, 255);
	b = Math::clamp(int(256 * b), 0, 255); 

	return Vector3(r, g, b);
}

Vector3 Vector3::toColor(Vector3 target)
{
	double r = target.x;
	double g = target.y;
	double b = target.z;

	r = Math::clamp(int(256 * r), 0, 255);
	g = Math::clamp(int(256 * g), 0, 255);
	b = Math::clamp(int(256 * b), 0, 255);

	return Vector3(r, g, b);
}

Vector3 Vector3::toColor(Vector3 target, int samples)
{

	double r = target.x;
	double g = target.y;
	double b = target.z;

	double scale = 1.0 / samples;

	r = sqrt(scale * r);
	g = sqrt(scale * g);
	b = sqrt(scale * b);

	r = Math::clamp(int(256 * r), 0, 255);
	g = Math::clamp(int(256 * g), 0, 255);
	b = Math::clamp(int(256 * b), 0, 255);

	return Vector3(r, g, b);

}
