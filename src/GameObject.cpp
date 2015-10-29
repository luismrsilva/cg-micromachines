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

void GameObject::draw(){
	cout << "GameObject::draw() | SHOULDN'T BE CALLED" << endl;
}

void GameObject::update(double delta_t){
	D_TRACE();
	updateBox();
}

void GameObject::updateBox(){
}

void updateBox() {
	cout << "GameObject::updateBox() | SHOULDN'T BE CALLED" << endl;
}

