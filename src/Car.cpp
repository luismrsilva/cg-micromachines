/*
 * Car.cpp
 *
 * */

#include "Car.hpp"
#include "Vector3.hpp"
#include <iostream>
using namespace std;
#include <GL/glut.h>

	Vector3 *pos;

Car::Car(){
	pos = new Vector3();
}

Car::~Car(){

}

void Car::draw(){
	cout << "Car::draw()" << endl;

	pos->set(pos->getX(), pos->getY()+0.1f, pos->getZ());

	glPushMatrix();
		glTranslatef(0.1f, -0.4f, 0.0f);
		glTranslatef(pos->getX(), pos->getY(), pos->getZ());
	    //glScalef(2.0f, 2.0f, 2.0f);
	    glColor3f(0.8f, 0.6f, 0.9f);
		glBegin(GL_POLYGON);
			glVertex3f(	-0.02f,	-0.02f,	 0.0f);
			glVertex3f(	 0.02f,	-0.02f,	 0.0f);
			glVertex3f(	 0.02f,	 0.05f,	 0.0f);
			glVertex3f(	-0.02f,	 0.05f,	 0.0f);
		glEnd();

		glColor3f(0.3f, 0.0f, 0.9f);
		glBegin(GL_POLYGON);
			glVertex3f(	-0.012f, -0.012f,  0.0f);
			glVertex3f(	 0.012f, -0.012f,  0.0f);
			glVertex3f(	 0.012f,  0.016f,  0.0f);
			glVertex3f(	-0.012f,  0.016f,  0.0f);
		glEnd();

		glRotatef(-90, 0, 1, 0);
		glColor3f(0.1f, 0.1f, 0.2f);	// tire color

		glTranslatef(00.00f, 0.0f, 0.02f);
		glutSolidTorus(0.002f, 0.005f, 32, 64);
		glTranslatef(0.0f, 0.035f, 0.0f);
		glutSolidTorus(0.002f, 0.005f, 32, 64);
		glTranslatef(0.0f, 0.0f, -0.040f);
		glutSolidTorus(0.002f, 0.005f, 32, 64);
		glTranslatef(0.0f, -0.035f, 0.0f);
		glutSolidTorus(0.002f, 0.005f, 32, 64);

    glPopMatrix();
}
