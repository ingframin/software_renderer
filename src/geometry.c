#include "geometry.h"
#include <math.h>

Barycoords barycentric(Vector2 A, Vector2 B, Vector2 C, Vector2 P)
{
	Barycoords bc;
	bc.gamma = ((A.y - B.y) * P.x + (B.x - A.x) * P.y + A.x * B.y - B.x * A.y) /
			   ((A.y - B.y) * C.x + (B.x - A.x) * C.y + A.x * B.y - B.x * A.y);
	bc.beta = ((A.y - C.y) * P.x + (C.x - A.x) * P.y + A.x * C.y - C.x * A.y) /
			  ((A.y - C.y) * B.x + (C.x - A.x) * B.y + A.x * C.y - C.x * A.y);
	bc.alpha = 1 - bc.beta - bc.gamma;

	return bc;
}

Vector2 v2_sum(Vector2 v1, Vector2 v2){
	Vector2 res = {v1.x+v2.x,v1.y+v2.y};
	return res;
}

Vector2 v2_dif(Vector2 v1, Vector2 v2){
	Vector2 res = {v1.x-v2.x,v1.y-v2.y};
	return res;

}

double  v2_dot(Vector2 v1, Vector2 v2){
	return sqrt(v1.x*v2.x+v1.y*v2.y);
}

Vector3 v2_cross(Vector2 v1, Vector2 v2){
	Vector3 res;
	res.z = v1.x*v2.y - v2.x*v1.y;
	return res;
}

Vector2 v2_norm(Vector2 v1){
	Vector2 norm;
	double mod = v2_mod(v1);
	norm.x = v1.x/mod;
	norm.y = v1.y/mod;
	return norm;
}

double  v2_mod(Vector2 v1){
	return sqrt(v1.x*v1.x + v1.y*v1.y);
}

Vector3 v3_sum(Vector3 v1, Vector3 v2){
	Vector3 res = {v1.x+v2.x,v1.y+v2.y,v1.z+v2.z};
	return res;
}

Vector3 v3_dif(Vector3 v1, Vector3 v2){
	Vector3 res = {v1.x-v2.x,v1.y-v2.y,v1.z-v2.z};
	return res;
}

double  v3_dot(Vector3 v1, Vector3 v2){
	return sqrt(v1.x*v2.x+v1.y*v2.y+v1.z*v2.z);
}

Vector3 v3_cross(Vector3 v1, Vector3 v2){
	Vector3 res;
	res.x = v1.y*v2.z - v2.y*v1.z;
	res.y = v1.z*v2.x - v2.z*v1.x;
	res.z = v1.x*v2.y - v2.x*v1.y;
	return res;
}

Vector3 v3_norm(Vector3 v1){
	Vector3 norm;
	double mod = v3_mod(v1);
	norm.x = v1.x/mod;
	norm.y = v1.y/mod;
	norm.z = v1.z/mod;
	return norm;
}

double  v3_mod(Vector3 v1){
	return sqrt(v1.x*v1.x+v1.y*v1.y+v1.z*v1.z);

}