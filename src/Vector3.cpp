/*
 * Vector3.cpp
 * 
 * */
 
#include "Vector3.hpp"
#include <math.h>


Vector3::Vector3(){
	_x = _y = _z = 0;
}

Vector3::Vector3(double x, double y, double z){
	_x = x;
	_y = y;
	_z = z;
}

Vector3::~Vector3(){
	
}

double Vector3::getX(){
	return _x;
}

double Vector3::getY(){
	return _y;
}

double Vector3::getZ(){
	return _z;
}

void Vector3::set(double x, double y, double z){
	_x = x;
	_y = y;
	_z = z;
}

Vector3 Vector3::operator=(const Vector3 vec){
	_x = vec._x;
	_y = vec._y;
	_z = vec._z;
	return *this;
}

Vector3 Vector3::operator*(double num){
	_x *= num;
	_y *= num;
	_z *= num;
	return *this;
}

Vector3 Vector3::operator+(const Vector3 vec){
	_x += vec._x;
	_y += vec._y;
	_z += vec._z;
	return *this;
}

Vector3 Vector3::operator-(const Vector3 vec){
	_x -= vec._x;
	_y -= vec._y;
	_z -= vec._z;
	return *this;
}

Vector3 Vector3::rotateZ(double deg){
	double mod = getXYModulus();
	double angle = atan(_y/_x) * 180 / M_PI;
	angle += deg;
	_x = mod * cos(angle);
	_y = mod * sin(angle);
	return *this;
}

double Vector3::getXYModulus(){
	return sqrt( pow(_x, 2) + pow (_y, 2) );
}

Vector3 Vector3::increaseMod(double mod_inc){
	double mod = getXYModulus();
	double angle = atan(_y/_x) * 180 / M_PI;
	mod += mod_inc;
	_x = mod * cos(angle);
	_y = mod * sin(angle);
	return *this;
}

