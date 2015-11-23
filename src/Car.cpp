/*
 * Car.cpp
 *
 * */

#define _USE_MATH_DEFINES
#include <cmath>
#include "Car.hpp"
#include "Vector3.hpp"
#include "myunits.hpp"
#include "game_config.hpp"
#include <iostream>
using namespace std;
#include <GL/glut.h>

#include "debug.hpp"

Material *_tireMaterial = new Material();

#define CAR_BODY_COLOR	0.6,0,0

Car::Car() : DynamicObject(){
	_angle_deg = 0;
	_isGoingForward = true;
	_isGhost = false;

	setColor(CAR_BODY_COLOR);
	_tireMaterial->setMaterial(0.1, 0.1, 0.1);

}

Car::~Car(){
	delete _tireMaterial;
}

bool Car::isGoingForward(){
	return _isGoingForward;
}

bool Car::setGoingForward(bool forward){
	_isGoingForward = forward;
	return _isGoingForward;
}

double Car::getXYAngle(){
	return _angle_deg;
}

void Car::setXYAngle(double deg){
	_angle_deg = deg;
}

double Car::rotateZ(double deg){
	_angle_deg = fmod(180 + _angle_deg + deg, 360)-180;
	return _angle_deg;
}

void Car::update(double delta_t){
	double da = -GAME_CAR_SPEED_DRAG(getSpeed().getXYModulus()) * delta_t;
	setSpeed(getSpeed().increaseMod(da));
	//cout << "CAR speed: " << speed << "| " << "drag: " << (double)da/((double)delta_t) << endl;

	DynamicObject::update(delta_t);
}

void Car::updateBox(){
	D_TRACE();
	const double angle = _angle_deg * M_PI / 180.;
	_box.changeTo(	cm(6.5 + fabs(6.5*cos(angle))),
					cm(6.5 + fabs(6.5*sin(angle))), *getPosition());
}

void Car::setGhost(bool status){
	_isGhost = status;
	if(_isGhost){
		_tireMaterial->setAlpha(0.4);
		_material->setAlpha(0.4);
	}else{
		_tireMaterial->setAlpha(1.0);
		_material->setAlpha(1.0);
	}
}

void drawTireAt(float xc, float yc, float zc, float x, float y, float angle){
	glPushMatrix();
		glLoadIdentity();
		glTranslatef(xc, yc, zc);
		glRotatef(angle, 0, 0, 1.);
		glTranslatef(x, y, 0);
	    glScalef(cm(13), cm(13), cm(13));

		#include "one_tire_calls.h"

	glPopMatrix();
}

void Car::draw(){
	D_TRACE();

	Vector3 *pos = this->getPosition();

	D_PRINT("car_pos: " << pos->getX() << ", " << pos->getY() << ", " << pos->getZ());

	glPushMatrix();
		glTranslatef(pos->getX(), pos->getY(), pos->getZ());
		glRotatef(this->_angle_deg, 0, 0, 1.);
	    glScalef(cm(13), cm(13), cm(13));

		_material->draw();
		#include "car_calls.h"

		_tireMaterial->draw();
		drawTireAt(pos->getX(), pos->getY(), pos->getZ(), -0.03, -0.038, this->_angle_deg);
		drawTireAt(pos->getX(), pos->getY(), pos->getZ(),  0.03, -0.038, this->_angle_deg);
		drawTireAt(pos->getX(), pos->getY(), pos->getZ(), -0.03,  0.038, this->_angle_deg);
		drawTireAt(pos->getX(), pos->getY(), pos->getZ(),  0.03,  0.038, this->_angle_deg);

    glPopMatrix();

    DynamicObject::draw();
}

void Car::reset(){
	setPosition(0.1, -0.2, 0.0);
	setSpeed(Vector3(0,0,0));
	setXYAngle(0.0);
}
