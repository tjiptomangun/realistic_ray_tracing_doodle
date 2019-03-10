#ifndef _RGB_H_
#define _RGB_H_ 1

#include <iostream>

class rgb{

public:
	rgb() {_r = _g = _b = 0;}
	rgb(double ret, double green ,double blue);
	rgb(const rgb & original){ *this = original; }

	void setRed(double red) { _r = red; }
	void setGreen(double green) { _g = green; }
	void setBlue(double blue) { _b = blue; }

	// these operatos perform no clamping
	rgb& operator= (const rgb & right_op);
	rgb& operator+= (const rgb & right_op);
	rgb& operator*= (const rgb & right_op);
	rgb& operator/= (const rgb & right_op);
	rgb& operator*= (double right_op);
	rgb& operator/= (double right_op);

	//A function becomes const when const keyword is used in function’s declaration. 
	//The idea of const functions is not allow them to modify the object on which 
	//they are called. 
	//It is recommended practice to make as many functions const as possible so 
	//that accidental changes to objects are avoided.

	rgb operator+() const {return *this;}
	rgb operator-() const {return rgb(-_r, -_g, -_b);}

	double r() const { return _r; }
	double g() const { return _g; }
	double b() const { return _b; }

	void clamp();

	friend std::ostream& operator<<(std::ostream &out, const rgb &the_rgb);
	friend rgb operator*(const rgb& c, double f);
	friend rgb operator*(double f, const rgb& c);
	friend rgb operator/(const rgb &c, double f);
	friend rgb operator*(const rgb &c1, const rgb& c2);
	friend rgb operator/(const rgb &c1, const rgb& c2);
	friend rgb operator+(const rgb &c1, const rgb& c2);
	

	double _r;
	double _g;
	double _b;
	
};

inline rgb::rgb(double red, double green, double blue): _r(red), _g(green), _b(blue) {}

inline rgb& rgb::operator+= (const rgb & right_op){
	*this = *this + right_op;
	return *this;
}

inline rgb& rgb::operator*= (double right_op) {
	*this = *this * right_op;
	return *this;
}

inline rgb& rgb::operator/= (double right_op) {
	*this = *this / right_op;
	return *this;
}

inline rgb& rgb::operator*= (const rgb & right_op) {
	*this = *this * right_op;
	return *this;
}

inline rgb& rgb::operator/= (const rgb & right_op) {
	*this = *this / right_op;
	return *this;
}

inline rgb & rgb::operator= (const rgb & right_op) {
	_r = right_op._r;
	_g = right_op._g;
	_b = right_op._b;
	return *this;
}

inline void rgb::clamp() {
	if (_r > 1.0f) _r = 1.0f;
	if (_g > 1.0f) _g = 1.0f;
	if (_b > 1.0f) _b = 1.0f;

	if (_r < 0.0f) _r = 0.0f;
	if (_g < 0.0f) _g = 0.0f;
	if (_b < 0.0f) _b = 0.0f;
}

inline std::ostream& operator<<(std::ostream & out, const rgb & the_rgb){
	out << the_rgb._r << ' '
		<< the_rgb._g << ' '
		<< the_rgb._b << ' ';
	return out;
}

inline rgb operator* (const rgb& c, float f){
	return rgb(c._r*f, c._g*f, c._b*f);
}

inline rgb operator* (float f, const rgb& c){
	return rgb(c._r*f, c._g*f, c._b*f);
}

inline rgb operator/ (const rgb& c, float f){
	return rgb(c._r/f, c._g/f, c._b/f);
}

inline rgb operator* (const rgb& c1, const rgb& c2){
	return rgb(c1._r*c2._r, c1._g*c2._g, c1._b*c2._b);
} 

inline rgb operator/ (const rgb& c1, const rgb& c2){
	return rgb(c1._r/c2._r, c1._g/c2._g, c1._b/c2._b);
}

inline rgb operator+ (const rgb& c1, const rgb& c2){
	return rgb(c1._r+c2._r, c1._g+c2._g, c1._b+c2._b);
}

#endif //_RGB_H_
