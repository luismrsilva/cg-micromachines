/*
 * GameObject.cpp
 *
 * */

#include "GameObject.hpp"
#include "debug.hpp"
#include "game_config.hpp"
#include "Box.hpp"
#include <iostream>
#include <cmath>


using namespace std;

GameObject::GameObject() : Entity() {
	_isBoxMode = false;
	_material = new Material();
}

GameObject::GameObject(double x, double y, double z) : Entity(x, y, z){
	_isBoxMode = false;
	_material = new Material();
}

GameObject::~GameObject(){
	delete _material;
}

bool GameObject::isColidingWith(const GameObject &obj){
	return _box.isIntersecting(obj._box);
}

bool GameObject::isOutOfBounds(){
	return (abs(getPosition()->getX()) >= GAME_TABLE_LIMIT ||
			abs(getPosition()->getY()) >= GAME_TABLE_LIMIT);
}

bool GameObject::processCollisionWith(GameObject &obj){
	D_TRACE();
	return isColidingWith(obj);
}

void GameObject::draw(){
	D_TRACE();
	if (_isBoxMode)
		_box.draw();
}

void GameObject::update(double delta_t){
	D_TRACE();
}

void GameObject::toggleBox(){
	_isBoxMode = !_isBoxMode;
}

void GameObject::setColor(GLfloat r, GLfloat g, GLfloat b){
	_material->setMaterial(r, g, b);
	_material->draw();
}

void GameObject::setColor(GLfloat r, GLfloat g, GLfloat b, GLfloat a){
	_material->setMaterial(r, g, b, a);
	_material->draw();
}

void GameObject::updateBox(){
	D_TRACE(<<"SHOLDN'T BE CALLED");
}

void updateBox() {
	D_TRACE(<<"SHOLDN'T BE CALLED");
}


