/*
 * Entity.cpp
 * 
 * */

#include "Entity.hpp"


Entity::Entity(){
	_position = new Vector3();
}

Entity::Entity(double x, double y, double z) : Entity(){
	this->setPosition(x, y, z);
}

Entity::~Entity(){
	delete _position;
}

Vector3* Entity::getPosition(){
	return _position;
}

Vector3* Entity::setPosition(double x, double y, double z){
	_position->set(x, y, z);
	return _position;
}

Vector3* Entity::setPosition(Vector3 *p){
	// copia as coordenadas
	_position = p;
	return _position;
}

