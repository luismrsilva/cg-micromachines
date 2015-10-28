/*
 * Vector3.cpp
 *
 * */

#include "debug.hpp"
#include <iostream>
#include "Vector3.hpp"
#define _USE_MATH_DEFINES
#include <math.h>



Vector3::Vector3(){
	_x = _y = _z = 0.;
}

Vector3::Vector3(double x, double y, double z){
	_x = x;
	_y = y;
	_z = z;
}

Vector3::Vector3(double mod, double angleXY_deg){
	_x = mod * cos(angleXY_deg * M_PI/180);
	_y = mod * sin(angleXY_deg * M_PI/180);
	_z = 0;
}

Vector3::~Vector3(){

}

double Vector3::getX() const{
	return _x;
}

double Vector3::getY() const{
	return _y;
}

double Vector3::getZ() const{
	return _z;
}

void Vector3::set(double x, double y, double z){
	_x = x;
	_y = y;
	_z = z;
}

Vector3 Vector3::operator=(const Vector3 &vec){
	_x = vec.getX();
	_y = vec.getY();
	_z = vec.getZ();
	return *this;
}

Vector3 Vector3::operator*(double num) const{
	return Vector3(getX() * num, getY() *num, getZ() * num);
}

Vector3 Vector3::operator+(const Vector3 &vec) const{
	return Vector3(getX() + vec.getX(), getY() + vec.getY(), getZ() + vec.getZ());
}

Vector3 Vector3::operator-(const Vector3 &vec) const{
	return Vector3(getX() - vec.getX(), getY() - vec.getY(), getZ() - vec.getZ());
}

Vector3 Vector3::rotateZ(double deg){
	double mod = getXYModulus();
	double angle = getXYAngle();
	angle += deg;
	_x = mod * cos(angle * M_PI/180);
	_y = mod * sin(angle * M_PI/180);
	return *this;
}

double Vector3::getXYModulus() const{
	return sqrt( pow(_x, 2) + pow (_y, 2) );
}

Vector3 Vector3::increaseMod(double mod_inc){
	double mod = getXYModulus();
	double angle = getXYAngle();
	mod += mod_inc;
	if(mod < 0.)
		mod = 0.;
	_x = mod * cos(angle * M_PI/180);
	_y = mod * sin(angle * M_PI/180);
	return *this;
}

void Vector3::print() const{
	std::cout	<< "Vector3(" << getX() << ", "
				<< getY() << ", " << getZ() << ")";
}

void Vector3::println() const{
	print();
	std::cout << std::endl;
}

double Vector3::getXYAngle() const{
	double angle = atan2(_y, _x) * 180 / M_PI;
	if(angle != angle) // check if NaN
		angle = 0;
	return angle;
}
