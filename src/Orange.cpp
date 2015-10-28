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
	reset();
}

Orange::Orange(double x, double y, double z) : Obstacle(x, y, z){
	reset();
}

Orange::~Orange(){
}

void Orange::reset(){
	moveToRandomPosition();
	//this->setSpeed(Vector3(0, 0, 0));
}

/* Draws an orange on x, y, z position */
void Orange::draw(){
	Vector3 * pos = this->getPosition();
	glPushMatrix();
		glTranslatef(pos->getX(), pos->getY(), pos->getZ());
		//glRotatef(this->_angle_deg-90., 0, 0, 0);
		glScalef(1, 1, 1);
		glColor3f(1.0f, 0.6f, 0.0f);
		glutSolidSphere(cm(5.5), 8, 8);
	glPopMatrix();

}
