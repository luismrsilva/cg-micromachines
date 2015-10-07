/*
 * DynamicObject.cpp
 *
 * */

#include "DynamicObject.hpp"


DynamicObject::DynamicObject(){
	_speed = new Vector3();
}

DynamicObject::~DynamicObject(){
	delete _speed;
}

void DynamicObject::update(double delta_t){

}

void DynamicObject::setSpeed(const Vector3 speed){

}

void DynamicObject::setSpeed(double x, double y, double z){

}

Vector3 DynamicObject::getSpeed() {
	return *_speed;
}
