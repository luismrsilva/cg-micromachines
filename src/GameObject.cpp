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
<<<<<<< HEAD
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
=======
	cout << "GameObject::draw()" << endl;
}

void GameObject::update(double delta_t){
	cout << "GameObject::update()" << endl;
>>>>>>> 0b719d5f37290cd77ec87c3aefee92e2e0bc2874
}

