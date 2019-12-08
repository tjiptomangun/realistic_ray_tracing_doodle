#include "ONB.h"


#define ONB_EPSILON 0.01f

void ONB::initFromU(const Vector3& u){
	Vector3 n (1.0f, 0.0f, 0.0f);
	Vector3 m (0.0f, 1.0f, 0.0f);
	U = unitVector(u);
	V = cross(U, n);
	if (V.length() < ONB_EPSILON)
		V = cross(U, m);
	W = cross(U, V);
	
}
