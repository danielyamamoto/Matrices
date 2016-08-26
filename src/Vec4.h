#pragma once
#include <iostream>

using namespace std;

class Vec4 {
public:
	float vec4[4];

	Vec4();
	Vec4(const float &dx,const float &dy,const float &dz,const float &dw = 1);
	Vec4 operator+(Vec4 rhs); // Suma
	Vec4 operator-(Vec4 rhs); // Resta
	Vec4 operator*(Vec4 rhs); // Multiplicación
	Vec4 operator*(float num); // Multiplicación con un entero
	Vec4 normalize(Vec4 vec); // Normalizar
	Vec4 cross(Vec4 vec); // Producto Cruz
	float point(Vec4 vec); // Producto Punto

};