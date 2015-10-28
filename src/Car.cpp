/*
 * Car.cpp
 *
 * */

#define _USE_MATH_DEFINES
#include <cmath>
#include "Car.hpp"
#include "Vector3.hpp"
#include "myunits.hpp"
#include <iostream>
using namespace std;
#include <GL/glut.h>

#include "debug.hpp"

Car::Car() : DynamicObject(){
	_angle_deg = 0;
	_isGoingForward = true;
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

void Car::draw(){
	D_TRACE();

	Vector3 *pos = this->getPosition();

	D_PRINT("car_pos: " << pos->getX() << ", " << pos->getY() << ", " << pos->getZ());

	glPushMatrix();
		glTranslatef(pos->getX(), pos->getY(), pos->getZ());
		glRotatef(this->_angle_deg-90., 0, 0, 1.);
	    glScalef(2.0f, 2.0f, 2.0f);

		glPushMatrix();	// car body
		    glColor3f(0.7f, 0.0f, 0.1f);
			glScalef(1, 2, 0.6);
			glTranslatef(0.0f, 0.0f, 0.01f);
			glutSolidCube(cm(4));
		glPopMatrix();

		glPushMatrix();	// car window
			glColor3f(0.7f, 0.6f, 1.0f);
			glScalef(1, 1.2, 1.2); // longer and taller
			glTranslatef(0.0f, -0.01f, 0.016f);
			glutSolidSphere(cm(1.5), 16, 16);
		glPopMatrix();

		glPushMatrix();	// car tires
			glRotatef(-90, 0, 1, 0);
			glColor3f(0.06f, 0.06f, 0.06f);	// tire color

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
}
