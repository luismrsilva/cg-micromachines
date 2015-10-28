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
	moveToRandomPosition();
	setSpeed(Vector3(this->getSpeed().getXYModulus(), (double) (rand() % 3600) / 10.0f));
}

void Orange::update(double delta_t){
	DynamicObject::update(delta_t);
	if (abs(this->getPosition()->getX()) >= GAME_TABLE_LIMIT ||	
		abs(this->getPosition()->getY()) >= GAME_TABLE_LIMIT){
		resetPosition();
	}
}

/* Draws an orange on x, y, z position */
void Orange::draw(){
	Vector3 * pos = this->getPosition();
	glPushMatrix();
		//glRotatef(60.0, 0, 0, 1.0);
		glTranslatef(pos->getX(), pos->getY(), pos->getZ()+0.03f);
		glColor3f(1.0f, 0.6f, 0.0f);
		glutSolidSphere(cm(5.5), 8, 8);
		glColor3f(0.2f, 0.6f, 0.2f);
		glTranslatef(0.0f ,0.0f, 0.05f);
		glutSolidCube(cm(2));
	glPopMatrix();
}
