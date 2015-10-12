/*
 * Orange.cpp
 *
 * */

#include "Orange.hpp"
#include <iostream>
#include "Vector3.hpp"
#include <math.h>

#include "myunits.hpp"
using namespace std;
#include <GL/glut.h>

Orange::Orange(){

}

Orange::Orange(double x, double y, double z) : Obstacle(x, y, z) {

}

Orange::~Orange(){

}

/* Draws an orange on x, y, z position */
void Orange::draw(){
	Vector3 * pos = this->getPosition();

	glPushMatrix();
	glTranslatef(pos->getX(), pos->getY(), pos->getZ());
	glScalef(1, 1, 1);
	glColor3f(1.0f, 0.6f, 0.0f);
	glutSolidSphere(cm(5.5), 200, 200);
	glPopMatrix();

}
