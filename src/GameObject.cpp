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
	_material = new Material(0.0, 0.0, 0.0);
}

GameObject::GameObject(double x, double y, double z) : Entity(x, y, z){
	_isBoxMode = false;
	_material = new Material(0.0, 0.0, 0.0);
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

void GameObject::setMaterialColor(GLfloat r, GLfloat g, GLfloat b){
	_material->setDefaultMaterial(r, g, b);
}

void GameObject::applyMaterialColor(GLfloat r, GLfloat g, GLfloat b){
	_material->setDefaultMaterial(r, g, b);
	_material->apply();
}

void GameObject::updateBox(){
	D_TRACE(<<"SHOULDN'T BE CALLED");
}

void updateBox() {
	D_TRACE(<<"SHOULDN'T BE CALLED");
}


