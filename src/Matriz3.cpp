#include "Matriz3.h"

Matriz3::Matriz3() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (i == j) {
				matriz[i][j]; // Inicializa la matriz
			}
			else {
				matriz[i][j] = 0;
			}
		}
	}
}

Matriz3::Matriz3(Vec3 & vec1, Vec3 & vec2, Vec3 & vec3) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (i == 0) {
				matriz[i][j] = vec1.vec3[j]; // Inicializa la primera linea de la matriz
			}
			else if (i == 1) {
				matriz[i][j] = vec2.vec3[j]; // Inicializa la segunda linea de la matriz
			}
			else {
				matriz[i][j] = vec3.vec3[j]; // Inicializa la tercera linea de la matriz
			}
		}
	}
}

Matriz3 Matriz3::operator*(const Matriz3 & rhs) {
	Matriz3 mR; // Matriz Resultante
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			mR.matriz[i][j] = 0;
			for (int k = 0; k < 3; k++) {
				mR.matriz[i][j] += matriz[i][k] * rhs.matriz[k][j];
			}
		}
	}
	return mR;
}

Vec3 Matriz3::operator*(Vec3 & rhs) {
	Vec3 vR = Vec3(0, 0, 0); // Vector Resultante
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			vR.vec3[i] += matriz[i][j] * rhs.vec3[j];
		}
	}
	return vR;
}

// mat = Matriz Mamá, la cual sirve para todas las transformaciones

Matriz3 Matriz3::rotate(const float & angle) {
	float r = angle / 180; // angle
	Matriz3 rot = Matriz3(Vec3(cos(r), -sin(r)), Vec3(sin(r), cos(r))); // rot = rotate
	Matriz3 mat = Matriz3(Vec3(matriz[0][0], matriz[0][1], matriz[0][2]),
		Vec3(matriz[1][0], matriz[1][1], matriz[1][2]),
		Vec3(matriz[2][0], matriz[2][1], matriz[2][2]));
	return rot * mat; 
}

Matriz3 Matriz3::translate(const float & x, const float & y) {
	Matriz3 tras = Matriz3(Vec3(1, 0, x), Vec3(0, 1, y)); // tras = traslate
	Matriz3 mat = Matriz3(Vec3(matriz[0][0], matriz[0][1], matriz[0][2]),
		Vec3(matriz[1][0], matriz[1][1], matriz[1][2]),
		Vec3(matriz[2][0], matriz[2][1], matriz[2][2]));
	return tras * mat;
}

//Matriz3 Matriz3::shear(const float & x, const float & y) {
//	return Matriz3();
//}

Matriz3 Matriz3::scale(const float & x, const float & y) {
	Matriz3 scal = Matriz3(Vec3(x, 0, 0), Vec3(0, y, 0)); // scal = scale
	Matriz3 mat = Matriz3(Vec3(matriz[0][0], matriz[0][1], matriz[0][2]),
		Vec3(matriz[1][0], matriz[1][1], matriz[1][2]),
		Vec3(matriz[2][0], matriz[2][1], matriz[2][2]));
	return scal * mat;
}