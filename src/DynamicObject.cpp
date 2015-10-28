/*
 * DynamicObject.cpp
 *
 * */
#include "debug.hpp"
#include "DynamicObject.hpp"


DynamicObject::DynamicObject() : GameObject(){
	_speed = new Vector3();
}

DynamicObject::DynamicObject(double x, double y, double z) : GameObject(x, y, z){
	_speed = new Vector3();
}

DynamicObject::~DynamicObject(){
	delete _speed;
}

void DynamicObject::update(double delta_t){
	D_TRACE( << " " << delta_t);
	Vector3 v = _speed->operator*(delta_t) + (*getPosition());
	v.println();

	setPosition(v.getX(), v.getY(), v.getZ());
	_speed->println();
}

void DynamicObject::setSpeed(const Vector3 &speed){
	_speed->set(speed.getX(), speed.getY(), speed.getZ());
}

void DynamicObject::setSpeed(double x, double y, double z){
	_speed->set(x, y, z);

}

Vector3 DynamicObject::getSpeed() const{
	return *_speed;
}
