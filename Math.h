#ifndef MATH_H
#define MATH_H

#include <math.h>

struct Math {

	static double degrees_to_radians(double degrees) {
		return degrees * 3.1415926535897932385 / 180;
	}

	static double PI() {
		return 3.1415926535897932385;
	}

	inline static double infinity() {
		return std::numeric_limits<double>::infinity();
	}

	inline static double random_double() {
		return rand() / (RAND_MAX + 1.0);
	}

	inline static double random_double(double min, double max) {
		return min + (max-min)*random_double();
	}

	inline static double clamp(float value, float min, float max) {

		if (value < min) {
			return min;
		}
		if (value > max) {
			return max;
		}
		return value;
	}

};

#endif