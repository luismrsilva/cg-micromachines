/*
 * Orange.cpp
 *
 * */

#define _USE_MATH_DEFINES
#include "game_config.hpp"
#include "Orange.hpp"
#include "Vector3.hpp"
#include <cmath>

#include "myunits.hpp"
using namespace std;
#include <GL/glut.h>

#include "Car.hpp"

#include "debug.hpp"
#include "game_config.hpp"

Orange::Orange() : Obstacle(0, 0, ORANGE_RADIUS){
	init();
}

Orange::Orange(double x, double y, double z) : Obstacle(x, y, z+ORANGE_RADIUS){
	init();
}

Orange::~Orange(){
}

void Orange::init(){
	_active = true;
	setRandomSpeed();
	moveToRandomPosition();
}

bool Orange::isActive(){
	return _active;
}

void Orange::resetPosition(){
	_angle = 0;
	_active = true;
	moveToRandomPosition();
	setSpeed(Vector3(getSpeed().getXYModulus(), (double) (rand() % 3600) / 10.0f));	// change angle
}

void Orange::update(double delta_t){
	if (_active){
		DynamicObject::update(delta_t);
		_angle += (getSpeed().operator*(delta_t).getXYModulus()*360)/(2*M_PI*ORANGE_RADIUS);
		if (isOutOfBounds()){
			_active = false;
		}
	}

}

void Orange::updateBox(){
	D_TRACE();
	_box.changeTo(2*ORANGE_RADIUS, 2*ORANGE_RADIUS, *getPosition());
}

/* Draws an orange on x, y, z position */
void Orange::draw(){
	if (!_active) return;
	Vector3 *pos = getPosition();
	Vector3 speed = getSpeed();


	D_TRACE(<< pos->getZ());
	glPushMatrix();
		glTranslatef(pos->getX(), pos->getY(), pos->getZ());
		glRotatef(_angle, -speed.getY(), speed.getX(), 0.0);

		applyMaterialColor(0.8, 0.4, 0.0);
		glutSolidSphere(ORANGE_RADIUS, 8, 16);

		applyMaterialColor(0.2, 0.6, 0.2);
		glTranslatef(0.0f ,0.0f, ORANGE_RADIUS);
		glScalef(1, 1, 0.4);
		glutSolidCube(ORANGE_RADIUS/2);
	glPopMatrix();

	Obstacle::draw();
}


bool Orange::processCollisionWith(GameObject &obj){
	D_TRACE();
	if(GameObject::processCollisionWith(obj)){
		return true;
	}
	return false;
}

