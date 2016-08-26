#pragma once
#include <iostream>

using namespace std;

class Vec3 {
public:
	float vec3[3];

	Vec3();
	Vec3(const float &dx,const float &dy,const float &dz = 1);
	Vec3 operator+(Vec3 rhs); // Suma
	Vec3 operator-(Vec3 rhs); // Resta
	Vec3 operator*(Vec3 rhs); // Multiplicación
	Vec3 operator*(float num); // Multiplicación por un entero
	Vec3 normalize(Vec3 vec); // Normalizar
	Vec3 cross(Vec3 vec); // Producto Cruz
	float point(Vec3 vec); // Producto Punto
};