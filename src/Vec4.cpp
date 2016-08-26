#include "Vec4.h"

Vec4::Vec4() {
	vec4[0] = 0;
	vec4[1] = 0;
	vec4[2] = 0;
	vec4[3] = 1;
}

Vec4::Vec4(const float & dx, const float & dy, const float & dz, const float & dw) {
	vec4[0] = dx;
	vec4[1] = dy;
	vec4[2] = dz;
	vec4[3] = dw;
}

Vec4 Vec4::operator+(Vec4 rhs) {
	return Vec4(vec4[0] + rhs.vec4[0], vec4[1] + rhs.vec4[1], vec4[2] + rhs.vec4[2]);
}

Vec4 Vec4::operator-(Vec4 rhs) {
	return Vec4(vec4[0] - rhs.vec4[0], vec4[1] - rhs.vec4[1], vec4[2] - rhs.vec4[2]);
}

Vec4 Vec4::operator*(Vec4 rhs) {
	return Vec4(vec4[0] * rhs.vec4[0], vec4[1] * rhs.vec4[1], vec4[2] * rhs.vec4[2]);
}

Vec4 Vec4::operator*(float num) {
	return Vec4(vec4[0] * num, vec4[1] * num, vec4[2] * num);
}

Vec4 Vec4::normalize(Vec4 vec) {
	float norm = sqrt(pow(vec.vec4[0], 2) + pow(vec.vec4[1], 2) + pow(vec.vec4[2], 2) + pow(vec.vec4[3], 2));
	return Vec4(vec4[0] / norm, vec4[1] / norm, vec4[2] / norm, vec4[3] / norm);
}

Vec4 Vec4::cross(Vec4 vec) {
	Vec4 vecTemp;
	vecTemp.vec4[0] = vec4[1] * vec.vec4[2] - (vec4[2] * vec.vec4[1]);
	vecTemp.vec4[1] = vec4[0] * vec.vec4[2] - (vec4[2] * vec.vec4[0]);
	vecTemp.vec4[2] = vec4[0] * vec.vec4[1] - (vec4[1] * vec.vec4[0]);

	cout << vecTemp.vec4[0] << "," << vecTemp.vec4[1] << "," << vecTemp.vec4[2] << endl;
	return vecTemp;
}

float Vec4::point(Vec4 vec) {
	float p = 0;
	for (int i = 0; i < 3; i++) {
		p += vec4[i] * vec.vec4[i];
	}
	cout << p << endl;
	return p;
}
