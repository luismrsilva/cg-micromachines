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

}

GameObject::GameObject(double x, double y, double z) : Entity(x, y, z){

}

GameObject::~GameObject(){

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
	#ifdef DEBUG
		_box.draw();
	#endif
}

void GameObject::update(double delta_t){
	D_TRACE();
}

void GameObject::initMaterial(GLfloat r, GLfloat g, GLfloat b){
	GLfloat amb[] = {r, g, b, 1.0};
	GLfloat dif[] = {r, g, b, 1.0};
	GLfloat spec[] = {1.0, 1.0, 1.0, 1.0};

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, amb);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, dif);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, spec);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, 69.0);
}

void GameObject::updateBox(){
	D_TRACE(<<"SHOLDN'T BE CALLED");
}

void updateBox() {
	D_TRACE(<<"SHOLDN'T BE CALLED");
}


