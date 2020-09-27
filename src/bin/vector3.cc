#include "vector3.h"
#include <iostream>

std::istream & operator >>(std::istream &is, vector3 &t) {
	float temp;
	is >> temp;
	t.e[0] = temp;
	is >> temp;
	t.e[1] = temp;
	is >> temp;
	t.e[2] = temp;

	return is;
}

std::ostream & operator << (std::ostream &os, const vector3 &t){
	os << '(' << t.e[0] << " " << t.e[1] << " " << t.e[2] << ')';
}

float tripleProduct(const vector3 &v1, const vector3  &v2, const vector3 &v3){
	return dot (cross(v1, v2), v3);
}
