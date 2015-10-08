/*
 * GameObject.cpp
 *
 * */

#include "GameObject.hpp"

#include <iostream>
using namespace std;

GameObject::GameObject(){

}

GameObject::GameObject(double x, double y, double z) : Entity(x, y, z){

}

GameObject::~GameObject(){

}

void GameObject::draw(){
	cout << "GameObject::draw()" << endl;
}

void GameObject::update(double delta_t){

}
