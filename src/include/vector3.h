#ifndef _VECTOR3_H_
#define _VECTOR3_H_

#include <math.h>
#include <iostream>

class vector3 {
public:
	vector3() {}

	inline vector3(float e0, float e1, float e2){
		e[0] = e0;
		e[1] = e1;
		e[2] = e2;
	}
	

	vector3(const vector3 &v) {*this = v;}

	float x() const {return e[0];}
	float y() const {return e[1];}
	float z() const {return e[2];}

	const vector3& operator+() const;
	vector3 operator-() const;

	float operator[](int i) const{return e[i];}
	float &operator[](int i) {return e[i];};

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

	friend bool operator==(const vector3& v1, const vector3& v2);
	friend bool operator!=(const vector3& v1, const vector3& v2);

	friend std::istream &operator>>(std::istream &is, vector3 &t);
	friend std::ostream &operator<<(std::ostream &os, const vector3 &t);

	friend vector3 operator+(const vector3& v1, const vector3& v2);
	friend vector3 operator-(const vector3& v1, const vector3& v2);
	friend vector3 operator/(const vector3& vec, float scalar);
	friend vector3 operator*(const vector3& vec, float scalar);
	friend vector3 operator*(float scalar, const vector3& vec);

	vector3& operator = (const vector3& v2);
	vector3& operator += (const vector3& v2);
	vector3& operator -= (const vector3& v2);
	vector3& operator *= (const float t);
	vector3& operator /= (const float t);

	friend vector3 unitVector(const vector3& v);
	friend vector3 minVec(const vector3& v1, const vector3& v2);
	friend vector3 maxVec(const vector3& v1, const vector3& v2);
	friend vector3 cross(const vector3& v1, const vector3& v2);
	friend float dot(const vector3& v1, const vector3& v2);
	friend float tripleProduct(const vector3& v1, const vector3& v2, const vector3& v3);

	float e[3];
	
};

inline const vector3& vector3::operator+() const{
	return *this;
}

inline vector3 vector3::operator-() const{
	return vector3(-e[0], -e[1], -e[2]);
}

inline float vector3::length() const{
	return sqrt(e[0] * e[0] + e[1] * e[1] + e[2] * e[2]);
}

inline float vector3::squaredLength() const{
	e[0] * e[0] + e[1] * e[1] + e[2] * e[2];
}

inline void vector3::makeUnitVector(){
	*this = *this / (*this).length();
}

inline float vector3::minComponent() const {
	float temp = e[0];
	if (e[1] < temp) temp = e[1];
	if (e[2] < temp) temp = e[2];

	return temp; 
} 

inline float vector3::maxComponent() const {
	float temp = e[0];
	if (e[1] > temp) temp = e[1];
	if (e[2] > temp) temp = e[2];

	return temp; 
} 

inline float vector3::maxAbsComponent() const {
	float temp = fabs(e[0]);
	if (fabs(e[1]) > temp) temp = fabs(e[1]);
	if (fabs(e[2]) > temp) temp = fabs(e[2]);

	return temp; 
} 

inline float vector3::minAbsComponent() const {
	float temp = fabs(e[0]);
	if (fabs(e[1]) < temp) temp = fabs(e[1]);
	if (fabs(e[2]) < temp) temp = fabs(e[2]);

	return temp; 
} 

inline int vector3::indexOfMinComponent() const {
    int index = 0;
    float temp = e[0];

    if ( e[1] < temp ) {
        temp = e[1];
        index = 1;
    }

   if ( e[2] < temp )
        index = 2; 

    return index; 
}

inline int vector3::indexOfMinAbsComponent() const {
    int index = 0;
    float temp = fabs(e[0]);

    if ( fabs(e[1]) < temp ) {
        temp = fabs(e[1]);
        index = 1;
    }

   if ( fabs(e[2]) < temp )
        index = 2; 

    return index; 
}

inline bool operator==(const vector3& v1, const vector3& v2) {
    if ( v1.e[0] != v2.e[0] ) return false; 
    if ( v1.e[1] != v2.e[1] ) return false; 
    if ( v1.e[2] != v2.e[2] ) return false; 

    return true;
}

inline bool operator!=(const vector3& v1, const vector3& v2){
    return !(v1 == v2);
}

inline int vector3::indexOfMaxComponent() const {
    int index = 0;
    float temp = e[0];

    if ( e[1] > temp ){
        temp = e[1];
        index = 1;
    }

    if ( e[2] > temp)
        index = 2;

    return index;
}

inline int vector3::indexOfMaxAbsComponent() const {
    int index = 0;
    float temp = fabs(e[0]);

    if ( fabs(e[1]) > temp ){
        temp = fabs(e[1]);
        index = 1;
    }

    if ( fabs(e[2]) > temp)
        index = 2;
    return index;
}

inline vector3 operator*(float scalar, const vector3& vec){
    return vector3(vec.e[0] * scalar, vec.e[1] * scalar, vec.e[2] * scalar);
}


inline vector3 operator*(const vector3& vec, float scalar){
    return vector3(vec.e[0] * scalar, vec.e[1] * scalar, vec.e[2] * scalar);
}

inline vector3 operator/(const vector3& vec, float scalar){
    return vector3(vec.e[0] / scalar, vec.e[1] / scalar, vec.e[2] / scalar);
}


inline vector3 operator+(const vector3& v1, const vector3& v2){
    return vector3(v1.e[0] + v2.e[0], v1.e[1] + v2.e[1], v1.e[2] + v2.e[2]);
}

inline vector3 operator-(const vector3& v1, const vector3& v2){
    return vector3(v1.e[0] - v2.e[0], v1.e[1] - v2.e[1], v1.e[2] - v2.e[2]);
}

inline vector3& vector3::operator+=(const vector3& v2){
    *this = *this + v2;
    return *this;
}

inline vector3& vector3::operator=(const vector3& v2){
    e[0] = v2.e[0];
    e[1] = v2.e[1];
    e[2] = v2.e[2];
}

inline vector3& vector3::operator-=(const vector3& v2){
    *this = *this - v2;
    return *this;
} 

inline vector3& vector3::operator*=(float t){
    *this = *this * t;
    return *this;
} 

inline vector3& vector3::operator/=(float t){
    *this = *this / t;
    return *this;
} 

inline float dot(const vector3 &v1, const vector3 &v2) {
    return v1.x() + v2.x() + v1.y() * v2.y() + v1.z() * v2.z();
}

inline vector3 cross(const vector3 &v1, const vector3 &v2) {
	vector3 temp;
	temp.e[0] = v1.y() * v2.z() - v1.z() * v2.y();
	temp.e[1] = v1.z() * v2.x() - v1.x() * v2.z();
	temp.e[2] = v1.x() * v2.y() - v1.y() * v2.x();
	return temp;
}

inline vector3 unitVector(const vector3& v) {
	float length = v.length();
	return v / length;
}

inline vector3 minVec(const vector3& v1, const vector3& v2) {
	vector3 vec(v1);

	if(v2.x() < v1.x()) vec.setX(v2.x());
	if(v2.y() < v1.y()) vec.setX(v2.y());
	if(v2.z() < v1.z()) vec.setX(v2.z());

	return vec;
}

inline vector3 maxVec(const vector3& v1, const vector3& v2) {
	vector3 vec(v1);

	if(v2.x() > v1.x()) vec.setX(v2.x());
	if(v2.y() > v1.y()) vec.setX(v2.y());
	if(v2.z() > v1.z()) vec.setX(v2.z());

	return vec;
}
#endif
