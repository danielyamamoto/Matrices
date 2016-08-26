#pragma once
#include "Vec4.h"

class Matriz4 {
public:
	float matriz[4][4];

	Matriz4();
	Matriz4(Vec4 &vec1, Vec4 &vec2, Vec4 &vec3, Vec4 &vec4 = Vec4(0, 0, 0));
	Vec4 operator*(Vec4 &rhs);
	Matriz4 operator*(const Matriz4 &rhs); // Right
	Matriz4 translate(const float &dx, const float &dy, const float &dz, const float &dw);
	Matriz4 lookAt(Vec4 &eye, Vec4 &target, Vec4 &up); // Camara
	Matriz4 rotateX(const float angle); // Ángulos
	Matriz4 rotateY(const float angle); // Ángulos
	Matriz4 rotateZ(const float angle); // Ángulos
	//Matriz4 shear(const float x, const float y, const float z); // Sorprender a Pedro // No es necesaria // Not today
	Matriz4 scale(const float &x, const float &y, const float &z);
};