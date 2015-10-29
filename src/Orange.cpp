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

float ORANGE_RADIUS = cm(6);

Orange::Orange() : Obstacle(){
	_active = true;
	moveToRandomPosition();
	setSpeed(Vector3(	(double) (rand() % 8 + 20) / 100.0f,
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
	setSpeed(
				Vector3(this->getSpeed().getXYModulus() * (((rand() % 5)+100)/100.0), // 0% -> 4% faster
				(double) (rand() % 3600) / 10.0f)
			);
}

void Orange::update(double delta_t){
	if (_active){
		DynamicObject::update(delta_t);
		_angle += (this->getSpeed().operator*(delta_t).getXYModulus()*360)/(2*M_PI*ORANGE_RADIUS);
		if (abs(this->getPosition()->getX()) >= GAME_TABLE_LIMIT ||	
			abs(this->getPosition()->getY()) >= GAME_TABLE_LIMIT){
				_active = false;
				_activate_time = glutGet(GLUT_ELAPSED_TIME) + ((4+(rand()%6))*1000);
			}
	} else if (_activate_time <= glutGet(GLUT_ELAPSED_TIME)){
		resetPosition();
	}

}

/* Draws an orange on x, y, z position */
void Orange::draw(){
	if (!_active) return;
	Vector3 *pos = this->getPosition();
	Vector3 speed = this->getSpeed();

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
}
