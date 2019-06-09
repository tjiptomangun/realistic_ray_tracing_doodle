#ifndef _VECTOR3_H_
#define _VECTOR3_H_

#include <math.h>
#include <iostream.h>

class Vector3 {
public:
	Vector3() {}
	Vector3(float e0, float e1, float e2)
	Vector3(const Vector3 &v) {*this = v;}

	float x() const {return e[0];}
	float y() const {return e[1];}
	float z() const {return e[2];}

	const Vector& operator+() const;
	Vector3 operator-() const;

	float operator[](int i) const{return e[i];}
	float &operator[](int i) {return e[i];

	float length() const;
	float squaredLength() const;

	void makeUnitVector();

	void setX(float t) {e[0] = t;}
	void setY(float t) {e[1] = t;}
	void setZ(float t) {e[2] = t;}

	float minComponent() const;	
	float maxComponent() const;	
	float maxAbsComponent() const;	
	float minAbsComponent() const;
	int indexOfMinComponent() const;
	int indexOfMinAbsComponent() const;
	int indexOfMaxComponent() const;
	int indexOfMaxAbsComponent() const;

	friend bool operator==(const Vector3& v1, const Vector3& v2);
	friend bool operator!=(const Vector3& v1, const Vector3& v2);

	friend istream &operator>>(istream &is, Vector3 &t);
	friend ostream &operator<<(ostream &os, const Vector3 &t);

	friend Vector3 operator+(const Vector3 v1, const Vector3& v2);
	friend Vector3 operator-(const Vector3 v1, const Vector3& v2);
	friend Vector3 operator/(const Vector3 vec, float scalar);
	friend Vector3 operator*(const Vector3 vec, float scalar);
	friend Vector3 operator*(float scalar, const Vector3 vec);

	Vector3& operator = (const Vector3& v2);
	Vector3& operator += (const Vector3& v2);
	Vector3& operator -= (const Vector3& v2);
	Vector3& operator *= (const float t);
	Vector3& operator /= (const float t);

	friend Vector3 unitVector(const Vector3& v);
	friend Vector3 minVec(const Vector3& v1, const Vector3& v2);
	friend Vector3 maxVec(const Vector3& v1, const Vector3& v2);
	friend Vector3 cross(const Vector3& v1, const Vector3& v2);
	friend float dot(const Vector3& v1, const Vector3& v2);
	friend float tripleProduct(const Vector3& v1, const Vector3& v2, const Vector3& v3);

	float e[3];
	
};

inline Vector3::Vector3(float e0, float e1, float e2){
	e[0] = e0;
	e[1] = e1;
	e[2] = e2;
}

inline const Vector3& Vector3::operator+() const{
	return *this;
}

inline Vector3& Vector3::operator-() const{
	return Vector3(-e[0], -e[1], -e[2]);
}

inline float Vector3::length() const{
	return sqrt(e[0] * e[0] + e[1] * e[1] + e[2] * e[2]);
}

inline float Vector3::squaredLength() const{
	e[0] * e[0] + e[1] * e[1] + e[2] * e[2];
}

inline void Vector3::makeUnitVector(){
	*this = *this / (*this).length();
}

inline float Vector3::minComponent() const {
	float temp = e[0];
	if (e[1] < temp) temp = e[1];
	if (e[2] < temp) temp = e[2];

	return temp; 
} 

inline float Vector3::maxComponent() const {
	float temp = e[0];
	if (e[1] > temp) temp = e[1];
	if (e[2] > temp) temp = e[2];

	return temp; 
} 
inline float Vector3::maxAbsComponent() const {
	float temp = fabs(e[0]);
	if (fabs(e[1]) > temp) temp = fabs(e[1]);
	if (fabs(e[2]) > temp) temp = fabs(e[2]);

	return temp; 
} 


#endif
