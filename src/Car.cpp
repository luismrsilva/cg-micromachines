/*
 * Car.cpp
 *
 * */

#include "Car.hpp"
#include "Vector3.hpp"
#include "myunits.hpp"
#include <iostream>
using namespace std;
#include <GL/glut.h>

#include "debug.hpp"

Car::Car(){

}

Car::~Car(){

}

void Car::draw(){
	D_TRACE();

	/*Vector3 *speed = this->getSpeed();
	speed->set(speed->getX(), speed->getY()+0.1f, speed->getZ());*/

	glPushMatrix();
		glTranslatef(0.1f, -0.4f, 0.0f);	// initial position
		//glTranslatef(speed->getX(), speed->getY(), speed->getZ());
	    glScalef(2.0f, 2.0f, 2.0f);

		glPushMatrix();
		    glColor3f(0.7f, 0.0f, 0.1f);
			glScalef(1, 2, 1);
			glutSolidCube(cm(4));
		glPopMatrix();

		glPushMatrix();
			glColor3f(0.7f, 0.6f, 1.0f);
			glScalef(1, 1.2, 0.8); // longer and less tall
			glTranslatef(0.0f, -0.01f, 0.0f);
			//glutSolidCube(cm(2));
			glutSolidSphere(cm(1.5), 32, 32);
		glPopMatrix();

		glPushMatrix();
			glRotatef(-90, 0, 1, 0);
			glColor3f(0.06f, 0.06f, 0.06f);	// tire color

			glTranslatef(0.0f, -0.02f, 0.024f);
			glutSolidTorus(0.004f, 0.005f, 32, 64);
			glTranslatef(0.0f, 0.045f, 0.0f);
			glutSolidTorus(0.004f, 0.005f, 32, 64);
			glTranslatef(0.0f, 0.0f, -0.048f);
			glutSolidTorus(0.004f, 0.005f, 32, 64);
			glTranslatef(0.0f, -0.045f, 0.0f);
			glutSolidTorus(0.004f, 0.005f, 32, 64);
		glPopMatrix();

    glPopMatrix();
}
