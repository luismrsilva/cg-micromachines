/*
 * DynamicObject.cpp
 *
 * */

#include "DynamicObject.hpp"


DynamicObject::DynamicObject(){
	_speed = new Vector3();
}

DynamicObject::DynamicObject(double x, double y, double z) : GameObject(x, y, z){
	DynamicObject();
}

DynamicObject::~DynamicObject(){
	delete _speed;
}

void DynamicObject::update(double delta_t){
	//this->setPosition(double x, double y, double z);
}

void DynamicObject::setSpeed(Vector3 speed){
	_speed->set(speed.getX(), speed.getY(), speed.getZ());
}

void DynamicObject::setSpeed(double x, double y, double z){
	_speed->set(x, y, z);

}

Vector3 DynamicObject::getSpeed() {
	return *_speed;
}
