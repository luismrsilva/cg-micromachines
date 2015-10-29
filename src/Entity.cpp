/*
 * Entity.cpp
 *
 * */

#include "Entity.hpp"
#include <cstdlib>

Entity::Entity(){
	_position = new Vector3();
	_old_position = new Vector3();
}

Entity::Entity(double x, double y, double z) : Entity(){
	this->setPosition(x, y, z);
}

Entity::~Entity(){
	delete _position;
	delete _old_position;
}

Vector3* Entity::getPosition() const{
	return _position;
}

Vector3* Entity::setPosition(double x, double y, double z){
	_position->set(x, y, z);
	return _position;
}

Vector3* Entity::setPosition(const Vector3 &p){
	// copia as coordenadas
	*_position = p;
	return _position;
}


void Entity::moveToRandomPosition() {
	setPosition((double) (rand() % 28 - 14.0) / 10.0f,
				(double) (rand() % 28 - 14.0) / 10.0f,
				(double) 0);
}

Vector3* Entity::setOldPosition(const Vector3 &p){
	// copia as coordenadas
	*_old_position = p;
	return _old_position;
}
void Entity::moveToOldPosition(){
	(*_position) = (*_old_position);
}
