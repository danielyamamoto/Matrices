#include "Matriz4.h"

Matriz4::Matriz4() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (i == j) {
				matriz[i][j] = 1;
			}
			else {
				matriz[i][j] = 0;
			}
		}
	}
}

Matriz4::Matriz4(Vec4 & vec1, Vec4 & vec2, Vec4 & vec3, Vec4 & vec4) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (i == 0) {
				matriz[i][j] = vec1.vec4[j]; // Inicializa la primera linea de la matriz
			}
			else if (i == 1) {
				matriz[i][j] = vec2.vec4[j]; // Inicializa la segunda linea de la matriz
			}
			else if (i == 2) {
				matriz[i][j] = vec3.vec4[j]; // Inicializa la tercera linea de la matriz
			}
			else {
				matriz[i][j] = vec4.vec4[j]; // Inicializa la cuarta linea de la matriz
			}
		}
	}
}

Vec4 Matriz4::operator*(Vec4 & rhs) {
	Vec4 vR = Vec4(0, 0, 0, 1); // vr = Vector Resultante
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			vR.vec4[i] += matriz[i][j] * rhs.vec4[j];
		}
	}
	return vR;
}

Matriz4 Matriz4::operator*(const Matriz4 & rhs) {
	Matriz4 mR; // mR = Matriz Resultante
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			mR.matriz[i][j] = 0;
			for (int k = 0; k < 4; k++) {
				mR.matriz[i][j] += matriz[i][k] * rhs.matriz[k][j];
			}
		}
	}
	return mR;
}

// mat = Matriz Mamá, la cual sirve para todas las transformaciones

Matriz4 Matriz4::translate(const float & dx, const float & dy, const float & dz, const float & dw) {
	Matriz4 tM = Matriz4(Vec4(1, 0, 0, dx), Vec4(0, 1, 0, dy), Vec4(0, 0, 1, dz)); // tM = translate Matriz
	Matriz4 mat = Matriz4(Vec4(matriz[0][0], matriz[0][1], matriz[0][2], matriz[0][3]),
		Vec4(matriz[1][0], matriz[1][1], matriz[1][2], matriz[1][3]),
		Vec4(matriz[2][0], matriz[2][1], matriz[2][2], matriz[2][3]),
		Vec4(matriz[3][0], matriz[3][1], matriz[3][2], matriz[3][3]));
	return tM * mat;
}

Matriz4 Matriz4::lookAt(Vec4 & eye, Vec4 & target, Vec4 & up) {
	Vec4 w = Vec4(0, 0, 0, 0); // a
	Vec4 u = Vec4(0, 0, 0, 0); // b
	Vec4 v = Vec4(0, 0, 0, 0); // c

	w = w.normalize(target - eye); // a
	u = u.normalize(w.cross(up)); // b
	v = v.normalize(u.cross(w)); // c

	Matriz4 mR = Matriz4(Vec4(u.vec4[0], u.vec4[1], u.vec4[2], 0),
		Vec4(v.vec4[0], v.vec4[1], v.vec4[2], 0),
		Vec4(w.vec4[0], w.vec4[1], w.vec4[2], 0));
	Matriz4 mT = Matriz4(Vec4(1, 0, 0, -eye.vec4[0]),
		Vec4(0, 1, 0, -eye.vec4[1]), 
		Vec4(0, 0, 1, -eye.vec4[2]));
	return mT * mR;
}

Matriz4 Matriz4::rotateX(const float angle) {
	float r = angle / 180; // r = angle
	Matriz4 rX = Matriz4(Vec4(1, 0, 0, 0), Vec4(0, cos(r), -sin(r), 0), Vec4(0, sin(r), cos(r), 0)); // rX = rotateX
	Matriz4 mat = Matriz4(Vec4(matriz[0][0], matriz[0][1], matriz[0][2], matriz[0][3]),
		Vec4(matriz[1][0], matriz[1][1], matriz[1][2], matriz[1][3]),
		Vec4(matriz[2][0], matriz[2][1], matriz[2][2], matriz[2][3]),
		Vec4(matriz[3][0], matriz[3][1], matriz[3][2], matriz[3][3]));
	return rX * mat;
}

Matriz4 Matriz4::rotateY(const float angle) {
	float r = angle / 180; // r = angle
	Matriz4 rY = Matriz4(Vec4(cos(r), 0, sin(r), 0), Vec4(0, 1, 0, 0), Vec4(-sin(r), 0, cos(r), 0)); // rY = rotateY
	Matriz4 mat = Matriz4(Vec4(matriz[0][0], matriz[0][1], matriz[0][2], matriz[0][3]),
		Vec4(matriz[1][0], matriz[1][1], matriz[1][2], matriz[1][3]),
		Vec4(matriz[2][0], matriz[2][1], matriz[2][2], matriz[2][3]),
		Vec4(matriz[3][0], matriz[3][1], matriz[3][2], matriz[3][3]));
	return rY * mat;
}

Matriz4 Matriz4::rotateZ(const float angle) {
	float r = angle / 180; // r = angle
	Matriz4 rZ = Matriz4(Vec4(cos(r), -sin(r), 0, 0), Vec4(sin(r), cos(r), 0, 0), Vec4(0, 0, 1, 0)); // rZ = rotateZ
	Matriz4 mat = Matriz4(Vec4(matriz[0][0], matriz[0][1], matriz[0][2], matriz[0][3]),
		Vec4(matriz[1][0], matriz[1][1], matriz[1][2], matriz[1][3]),
		Vec4(matriz[2][0], matriz[2][1], matriz[2][2], matriz[2][3]),
		Vec4(matriz[3][0], matriz[3][1], matriz[3][2], matriz[3][3]));
	return rZ * mat;
}

//Matriz4 Matriz4::shear(const float x, const float y, const float z) {
//	return Matriz4();
//}

Matriz4 Matriz4::scale(const float & x, const float & y, const float & z) {
	Matriz4 sM = Matriz4(Vec4(x, 0, 0, 0), Vec4(0, y, 0, 0), Vec4(0, 0, z, 0)); // sM = scale Matriz
	Matriz4 mat = Matriz4(Vec4(matriz[0][0], matriz[0][1], matriz[0][2], matriz[0][3]),
		Vec4(matriz[1][0], matriz[1][1], matriz[1][2], matriz[1][3]),
		Vec4(matriz[2][0], matriz[2][1], matriz[2][2], matriz[2][3]),
		Vec4(matriz[3][0], matriz[3][1], matriz[3][2], matriz[3][3]));
	return sM * mat;
}