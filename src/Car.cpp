/*
 * Car.cpp
 *
 * */

#include "Car.hpp"
#include <GL/glut.h>

Car::Car(){

}

Car::~Car(){

}

void Car::draw(){
  glColor3f(0.2f, 0.0f, 0.8f);
	glBegin(GL_POLYGON);
		glVertex3f(	-20.0f,	-20.0f,	 0.0f);
		glVertex3f(	 20.0f,	-20.0f,	 0.0f);
		glVertex3f(	 20.0f,	 50.0f,	 0.0f);
		glVertex3f(	-20.0f,	 50.0f,	 0.0f);
	glEnd();

	glColor3f(0.9f, 0.0f, 0.6f);
	glBegin(GL_POLYGON);
		glVertex3f(	-12.0f,	-12.0f,	 0.0f);
		glVertex3f(	 12.0f,	-12.0f,	 0.0f);
		glVertex3f(	 12.0f,	 16.0f,	 0.0f);
		glVertex3f(	-12.0f,	 16.0f,	 0.0f);
	glEnd();

	glPushMatrix();
		glRotatef(-90, 0, 1, 0);

		glColor3f(0.4f, 0.4f, 0.4f);	// gray
		glTranslatef(0.0f, 0.0f, 20.0f);
		glutWireTorus(2.0f, 5.0f, 16, 32);
		glColor3f(0.0f, 1.0f, 0.0f);	// green
		glTranslatef(0.0f, 35.0f, 0.0f);
		glutWireTorus(2.0f, 5.0f, 16, 32);
		glColor3f(0.0f, 0.0f, 1.0f);	// blue
		glTranslatef(0.0f, 0.0f, -40.0f);
		glutWireTorus(2.0f, 5.0f, 16, 32);
		glColor3f(0.6f, 0.2f, 0.2f);	// red-dark
		glTranslatef(0.0f, -35.0f, 0.0f);
		glutWireTorus(2.0f, 5.0f, 16, 32);
	glPopMatrix();
}
