/*
 * GameObject.cpp
 *
 * */

#include "GameObject.hpp"
#include "debug.hpp"
#include "Box.hpp"
#include <iostream>


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

void GameObject::draw(){
	D_TRACE();
	#ifdef DEBUG
		_box.draw();
	#endif
}

void GameObject::update(double delta_t){
	D_TRACE();
}

void GameObject::updateBox(){
	D_TRACE(<<"SHOLDN'T BE CALLED");
}

void updateBox() {
	D_TRACE(<<"SHOLDN'T BE CALLED");
}


