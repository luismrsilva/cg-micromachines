/*
 * Orange.cpp
 *
 * */

#include "game_config.hpp"
#include "Orange.hpp"
#include <iostream>
#include "Vector3.hpp"
#include <cmath>

#include "myunits.hpp"
using namespace std;
#include <GL/glut.h>

float ORANGE_RADIUS = cm(10.5);

Orange::Orange() : Obstacle(){
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
	moveToRandomPosition();
	setSpeed(Vector3(this->getSpeed().getXYModulus(), (double) (rand() % 3600) / 10.0f));
}

void Orange::update(double delta_t){
	DynamicObject::update(delta_t);
	float delta_ang = (this->getSpeed().operator*(delta_t).getXYModulus()*360)/(2*M_PI*ORANGE_RADIUS);
	_angle += delta_ang;

	if (abs(this->getPosition()->getX()) >= GAME_TABLE_LIMIT ||	
		abs(this->getPosition()->getY()) >= GAME_TABLE_LIMIT){
		resetPosition();
	}
}

/* Draws an orange on x, y, z position */
void Orange::draw(){
	Vector3 *pos = this->getPosition();
	Vector3 speed = this->getSpeed();

	glPushMatrix();
		glTranslatef(pos->getX(), pos->getY(), pos->getZ()+0.03f);

		glRotatef(_angle, -speed.getY(), speed.getX(), 0.0);
		glColor3f(1.0f, 0.6f, 0.0f);
		glutSolidSphere(ORANGE_RADIUS, 8, 16);
		glColor3f(0.2f, 0.6f, 0.2f);
		glTranslatef(0.0f ,0.0f, ORANGE_RADIUS);
		glutSolidCube(ORANGE_RADIUS/2);
	glPopMatrix();
}
