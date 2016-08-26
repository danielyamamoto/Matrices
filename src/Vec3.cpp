#include "Vec3.h"

Vec3::Vec3() {
	vec3[0] = 0;
	vec3[1] = 0;
	vec3[2] = 1;
}

Vec3::Vec3(const float & dx, const float & dy, const float & dz) {
	vec3[0] = dx;
	vec3[1] = dy;
	vec3[2] = dz;
}

Vec3 Vec3::operator+(Vec3 rhs) {
	return Vec3(vec3[0] + rhs.vec3[0], vec3[1] + rhs.vec3[1]);
}

Vec3 Vec3::operator-(Vec3 rhs) {
	return Vec3(vec3[0] - rhs.vec3[0], vec3[1] - rhs.vec3[1]);
}

Vec3 Vec3::operator*(Vec3 rhs) {
	return Vec3(vec3[0] * rhs.vec3[0], vec3[1] * rhs.vec3[1]);
}

Vec3 Vec3::operator*(float num) {
	return Vec3(vec3[0] * num, vec3[1] * num);
}

Vec3 Vec3::normalize(Vec3 vec) {
	float norm = sqrt(pow(vec.vec3[0], 2) + pow(vec.vec3[1], 2) + pow(vec.vec3[2], 2));
	return Vec3(vec3[0]/norm, vec3[1] / norm, vec3[2] / norm);
}

Vec3 Vec3::cross(Vec3 vec) {
	Vec3 vecTemp;
	vecTemp.vec3[0] = vec3[1] * vec.vec3[2] - (vec3[2] * vec.vec3[1]);
	vecTemp.vec3[1] = vec3[0] * vec.vec3[2] - (vec3[2] * vec.vec3[0]);
	vecTemp.vec3[2] = vec3[0] * vec.vec3[1] - (vec3[1] * vec.vec3[0]);

	cout << vecTemp.vec3[0] << "," << vecTemp.vec3[1] << "," << vecTemp.vec3[2] << endl;
	return vecTemp;
}

float Vec3::point(Vec3 vec) {
	float p = 0;
	for (int i = 0; i < 3; i++) {
		p += vec3[i] * vec.vec3[i];
	}
	cout << p << endl;
	return p;
}
