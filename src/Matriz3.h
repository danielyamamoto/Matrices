#pragma once
#include "Vec3.h"

using namespace std;

class Matriz3 {
public:
	float matriz[3][3];

	Matriz3();
	Matriz3(Vec3 &vec1, Vec3 &vec2, Vec3 &vec3=Vec3(0,0));
	Matriz3 operator*(const Matriz3 &rhs); // Right
	Vec3 operator*(Vec3 &rhs);
	Matriz3 rotate(const float &angle); // Ángulos
	Matriz3 translate(const float &x, const float &y);
	//Matriz3 shear(const float &x, const float &y); // Sorprender a Pedro // No es necesaria // Not today, Pedrito, not today
	Matriz3 scale(const float &x, const float &y);
};