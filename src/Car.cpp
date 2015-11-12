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

Car::Car() : DynamicObject(){
	_angle_deg = 0;
	_isGoingForward = true;
	_isGhost = false;
}

Car::~Car(){

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
}

void Car::draw(){
	D_TRACE();

	Vector3 *pos = this->getPosition();

	D_PRINT("car_pos: " << pos->getX() << ", " << pos->getY() << ", " << pos->getZ());

	glPushMatrix();
		glTranslatef(pos->getX(), pos->getY(), pos->getZ());
		glRotatef(this->_angle_deg-90., 0, 0, 1.);
	    glScalef(1.4f, 1.4f, 1.4f);

		glPushMatrix();	// car body
		    setColor(0.7, 0.0, 0.1);
			glScalef(1, 2, 0.6);
			glTranslatef(0.0f, 0.0f, 0.01f);
			glutSolidCube(cm(4));
		glPopMatrix();

		glPushMatrix();	// car window
			setColor(0.7, 0.6, 1.0);
			glScalef(1, 1.2, 1.2); // longer and taller
			glTranslatef(0.0f, -0.01f, 0.016f);
			glutSolidSphere(cm(1.5), 6, 6);
		glPopMatrix();

		glPushMatrix();	// car tires
			glRotatef(-90, 0, 1, 0);
			if (_isGhost) setColor(0.9, 0.9, 0.9);
		    else setColor(0.06, 0.06, 0.06);

			glTranslatef(0.0f, -0.024f, 0.024f);
			glutSolidTorus(0.004f, 0.005f, 8, 16);
			glTranslatef(0.0f, 0.045f, 0.0f);
			glutSolidTorus(0.004f, 0.005f, 8, 16);
			glTranslatef(0.0f, 0.0f, -0.048f);
			glutSolidTorus(0.004f, 0.005f, 8, 16);
			glTranslatef(0.0f, -0.045f, 0.0f);
			glutSolidTorus(0.004f, 0.005f, 8, 16);
		glPopMatrix();

    glPopMatrix();

    DynamicObject::draw();
}

void Car::reset(){
	setPosition(0.1, -0.2, 0.0);
	setSpeed(Vector3(0,0,0));
	setXYAngle(0.0);
}
