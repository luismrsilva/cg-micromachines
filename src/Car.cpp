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

#define CAR_BODY_COLOR	0.6,0,0

Car::Car(GLenum lightNumL, GLenum lightNumR) : DynamicObject(){
	_angle_deg = 0;
	_isGoingForward = true;
	_isGhost = false;

	setMaterialColor(CAR_BODY_COLOR);
	_tireMaterial = new Material(0.1, 0.1, 0.1);

	// Left headLight
	_headLightL = new SpotLightSource(lightNumL);
	_headLightL->setAmbient(0.8, 0.6, 0.4, 1.0);
	_headLightL->setDiffuse(1.0, 0.8, 0.4, 1.0);
	_headLightL->setSpecular(1.0, 0.8, 0.6, 1.0);
	_headLightL->setAttenuation(0.1, 1, 8);

	_headLightL->setCutOff(10);
	_headLightL->setExponent(0);
	_headLightL->setState(false);

	//Right headLight
	_headLightR = new SpotLightSource(lightNumR);
	_headLightR->setAmbient(0.8, 0.6, 0.4, 1.0);
	_headLightR->setDiffuse(0.0, 0.8, 0.4, 1.0);
	_headLightR->setSpecular(1.0, 0.8, 0.6, 1.0);
	_headLightR->setAttenuation(0.1, 1, 8);

	_headLightR->setCutOff(10);
	_headLightR->setExponent(0);
	_headLightR->setState(false);
}

Car::~Car(){
	delete _tireMaterial;
	delete _headLightL;
	delete _headLightR;
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

void Car::toggleLight() {
	_headLightL->toggleState();
	_headLightR->toggleState();
}

void Car::update(double delta_t){
	double da = -GAME_CAR_SPEED_DRAG(getSpeed().getXYModulus()) * delta_t;
	setSpeed(getSpeed().increaseMod(da));
	const double angle = _angle_deg * M_PI / 180.;

	//cout << "CAR speed: " << speed << "| " << "drag: " << (double)da/((double)delta_t) << endl;

	//lights go with the car (headLights)

	Vector3 pos = *(getPosition());  //get car position
	Vector3 direct = Vector3(cos(angle), sin(angle), 0);

	/* create copies direct because rotateZ is a modifier */
	Vector3 deltaL = direct*(2*CAR_FRONT/3);
	Vector3 deltaR = deltaL;
	deltaL.rotateZ(90);
	deltaR.rotateZ(-90);

	pos = pos + direct*(GAME_CAR_SCALE/2) + Vector3(0,0, GAME_CAR_SCALE/8);

	_headLightL->setPosition(pos + deltaL);
	_headLightL->setDirection(direct);

	_headLightR->setPosition(pos + deltaR);
	_headLightR->setDirection(direct);

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

	_headLightL->draw();
	_headLightR->draw();
	Vector3 *pos = getPosition();

	D_PRINT("car_pos: " << pos->getX() << ", " << pos->getY() << ", " << pos->getZ());

	glPushMatrix();
		glTranslatef(pos->getX(), pos->getY(), pos->getZ());
		glRotatef(this->_angle_deg, 0, 0, 1.);
	    glScalef(cm(13), cm(13), cm(13));
		_material->apply();
		#include "car_calls.h"
		_tireMaterial->apply();
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

bool Car::setHeadLightStateL(bool state) {
	return _headLightL->setState(state);
}

bool Car::setHeadLightStateR(bool state) {
	return _headLightR->setState(state);
}
