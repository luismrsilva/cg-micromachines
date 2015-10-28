/*
 * Orange.cpp
 *
 * */

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
}

void Orange::update(double delta_t){
	DynamicObject::update(delta_t);
	if (abs(this->getPosition()->getX()) >= 1.5f || abs(this->getPosition()->getY()) >= 1.5f){
		resetPosition();
	}
}

/* Draws an orange on x, y, z position */
void Orange::draw(){
	Vector3 * pos = this->getPosition();
	glPushMatrix();
		glTranslatef(pos->getX(), pos->getY(), pos->getZ());
		//glRotatef(-2., 0, 0, 1.); TODO
		glScalef(1, 1, 1);
		glColor3f(1.0f, 0.6f, 0.0f);
		glutSolidSphere(cm(5.5), 8, 8);
	glPopMatrix();

}
