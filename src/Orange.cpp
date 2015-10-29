/*
 * Orange.cpp
 *
 * */

#include "game_config.hpp"
#include "Orange.hpp"
#include "Vector3.hpp"
#include <cmath>

#include "myunits.hpp"
using namespace std;
#include <GL/glut.h>

#include "debug.hpp"
#include "game_config.hpp"

Orange::Orange() : Obstacle(){
	_active = true;
	moveToRandomPosition();
	setSpeed(Vector3(	(double) (rand() % 25 + 5) / 100.0f,
						(double) (rand() % 3600) / 10.0f
					)
			);
}

Orange::Orange(double x, double y, double z) : Obstacle(x, y, z){
	Orange();
}

Orange::~Orange(){
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
				_activate_time = glutGet(GLUT_ELAPSED_TIME) + ((2+(rand()%4))*1000);
			}
	} else if (_activate_time <= glutGet(GLUT_ELAPSED_TIME)){
		resetPosition();
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

	glPushMatrix();
		glTranslatef(pos->getX(), pos->getY(), pos->getZ()+ORANGE_RADIUS-0.02f);

		glRotatef(_angle, -speed.getY(), speed.getX(), 0.0);
		glColor3f(1.0f, 0.6f, 0.0f);
		glutSolidSphere(ORANGE_RADIUS, 8, 16);
		glColor3f(0.2f, 0.6f, 0.2f);
		glTranslatef(0.0f ,0.0f, ORANGE_RADIUS);
		glScalef(1, 1, 0.4);
		glutSolidCube(ORANGE_RADIUS/2);
	glPopMatrix();

	Obstacle::draw();
}


bool Orange::processCollisionWith(GameObject &obj){
	D_TRACE();
	if(GameObject::processCollisionWith(obj)){
		DynamicObject &dobj = ((DynamicObject&)obj);

		dobj.setSpeed(dobj.getSpeed()*0.5);
		return true;
	}
	return false;
}

