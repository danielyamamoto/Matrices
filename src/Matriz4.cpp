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
	Vec4 vR = Vec4(0, 0, 0, 1); // Vector Resultante
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			vR.vec4[i] += matriz[i][j] * rhs.vec4[j];
		}
	}
	return vR;
}

Matriz4 Matriz4::operator*(const Matriz4 & rhs) {
	Matriz4 mR;
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

Matriz4 Matriz4::translate(const float & dx, const float & dy, const float & dz, const float & dw) {
	Matriz4 tM = Matriz4(Vec4(1, 0, 0, dx), Vec4(0, 1, 0, dy), Vec4(0, 0, 1, dz));
	Matriz4 mat = Matriz4(Vec4(matriz[0][0], matriz[0][1], matriz[0][2], matriz[0][3]),
		Vec4(matriz[1][0], matriz[1][1], matriz[1][2], matriz[1][3]),
		Vec4(matriz[2][0], matriz[2][1], matriz[2][2], matriz[2][3]),
		Vec4(matriz[3][0], matriz[3][1], matriz[3][2], matriz[3][3]));
	return tM * mat;
}

Matriz4 Matriz4::lookAt(Vec4 & eye, Vec4 & target, Vec4 & up) {
	Vec4 w = Vec4(0, 0, 0, 0);
	Vec4 u = Vec4(0, 0, 0, 0);
	Vec4 v = Vec4(0, 0, 0, 0);

	w = w.normalize(target - eye);
	u = u.normalize(w.cross(up));
	v = v.normalize(u.cross(w));

	Matriz4 mR = Matriz4(Vec4(u.vec4[0], u.vec4[1], u.vec4[2], 0),
		Vec4(v.vec4[0], v.vec4[1], v.vec4[2], 0),
		Vec4(w.vec4[0], w.vec4[1], w.vec4[2], 0));
	Matriz4 mT = Matriz4(Vec4(1, 0, 0, -eye.vec4[0]),
		Vec4(0, 1, 0, -eye.vec4[1]), 
		Vec4(0, 0, 1, -eye.vec4[2]));
	return mT * mR;
}

Matriz4 Matriz4::rotateX(const float angle) {
	float r = angle / 180;
	Matriz4 rX = Matriz4(Vec4(1, 0, 0, 0), Vec4(0, cos(r), -sin(r), 0), Vec4(0, sin(r), cos(r), 0));
	Matriz4 mat = Matriz4(Vec4(matriz[0][0], matriz[0][1], matriz[0][2], matriz[0][3]),
		Vec4(matriz[1][0], matriz[1][1], matriz[1][2], matriz[1][3]),
		Vec4(matriz[2][0], matriz[2][1], matriz[2][2], matriz[2][3]),
		Vec4(matriz[3][0], matriz[3][1], matriz[3][2], matriz[3][3]));
	return rX * mat;
}

Matriz4 Matriz4::rotateY(const float angle) {
	float r = angle / 180;
	Matriz4 rY = Matriz4(Vec4(cos(r), 0, sin(r), 0), Vec4(0, 1, 0, 0), Vec4(-sin(r), 0, cos(r), 0));
	Matriz4 mat = Matriz4(Vec4(matriz[0][0], matriz[0][1], matriz[0][2], matriz[0][3]),
		Vec4(matriz[1][0], matriz[1][1], matriz[1][2], matriz[1][3]),
		Vec4(matriz[2][0], matriz[2][1], matriz[2][2], matriz[2][3]),
		Vec4(matriz[3][0], matriz[3][1], matriz[3][2], matriz[3][3]));
	return rY * mat;
}

Matriz4 Matriz4::rotateZ(const float angle) {
	float r = angle / 180;
	Matriz4 rZ = Matriz4(Vec4(cos(r), -sin(r), 0, 0), Vec4(sin(r), cos(r), 0, 0), Vec4(0, 0, 1, 0));
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
	Matriz4 sM = Matriz4(Vec4(x, 0, 0, 0), Vec4(0, y, 0, 0), Vec4(0, 0, z, 0));
	Matriz4 mat = Matriz4(Vec4(matriz[0][0], matriz[0][1], matriz[0][2], matriz[0][3]),
		Vec4(matriz[1][0], matriz[1][1], matriz[1][2], matriz[1][3]),
		Vec4(matriz[2][0], matriz[2][1], matriz[2][2], matriz[2][3]),
		Vec4(matriz[3][0], matriz[3][1], matriz[3][2], matriz[3][3]));
	return sM * mat;
}

Matriz4 Matriz4::perspective(float & angle, float & aspect, float & near, float &far) {
	float d = 1 / (tan(angle / 360));
	Vec4 vec1 = Vec4((d / (aspect)), 0, 0, 0);
	Vec4 vec2 = Vec4(0, d, 0, 0);
	Vec4 vec3 = Vec4(0, 0, (-2 / (near - far)), 0);
	Vec4 vec4 = Vec4(0, 0, -1, 0);
	Matriz4 persp = Matriz4(vec1, vec2, vec3, vec4);
	Matriz4 object = Matriz4(Vec4(matriz[0][0], matriz[0][1], matriz[0][2], matriz[0][3]),
		Vec4(matriz[1][0], matriz[1][1], matriz[1][2], matriz[1][3]),
		Vec4(matriz[2][0], matriz[2][1], matriz[2][2], matriz[2][3]),
		Vec4(matriz[3][0], matriz[3][1], matriz[3][2], matriz[3][3]));
	return persp * object;
}

Matriz4 Matriz4::ortho(float & near, float & far, float & left, float & right, float & top, float & bottom) {
	Vec4 vec1 = Vec4((2 / (right - left)), 0, 0, 0);
	Vec4 vec2 = Vec4(0, (2 / (top - bottom)), 0, 0);
	Vec4 vec3 = Vec4(0, 0, (-2 / (near - far)), 0);
	Matriz4 scale = Matriz4(vec1, vec2, vec3);
	// Se reasignan los vectores
	vec1 = Vec4(1, 0, 0, (-(right + left) / 2));
	vec2 = Vec4(0, 1, 0, (-(top + bottom) / 2));
	vec3 = Vec4(0, 0, 1, (-(near + far) / 2));
	Matriz4 trans = Matriz4(vec1, vec2, vec3);
	scale = scale * trans;

	trans = Matriz4(Vec4(matriz[0][0], matriz[0][1], matriz[0][2], matriz[0][3]),
		Vec4(matriz[1][0], matriz[1][1], matriz[1][2], matriz[1][3]),
		Vec4(matriz[2][0], matriz[2][1], matriz[2][2], matriz[2][3]),
		Vec4(matriz[3][0], matriz[3][1], matriz[3][2], matriz[3][3]));
	return scale * trans;
}