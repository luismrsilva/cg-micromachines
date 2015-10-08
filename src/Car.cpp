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
		glVertex3f(	-0.02f,	-0.02f,	 0.0f);
		glVertex3f(	 0.02f,	-0.02f,	 0.0f);
		glVertex3f(	 0.02f,	 0.05f,	 0.0f);
		glVertex3f(	-0.02f,	 0.05f,	 0.0f);
	glEnd();

	glColor3f(0.9f, 0.0f, 0.6f);
	glBegin(GL_POLYGON);
		glVertex3f(	-0.012f,	-0.012f,	 0.0f);
		glVertex3f(	 0.012f,	-0.012f,	 0.0f);
		glVertex3f(	 0.012f,	 0.016f,	 0.0f);
		glVertex3f(	-0.012f,	 0.016f,	 0.0f);
	glEnd();

	glPushMatrix();
		glRotatef(-90, 0, 1, 0);
		glColor3f(0.4f, 0.4f, 0.4f);	// gray

		glTranslatef(0.0f, 0.0f, 0.02f);
		glutWireTorus(0.02f, 0.05f, 16, 32);

		glColor3f(0.0f, 1.0f, 0.0f);	// green
		glTranslatef(0.0f, 0.35f, 0.0f);
		glutWireTorus(0.02f, 0.05f, 16, 32);

		glColor3f(0.0f, 0.0f, 1.0f);	// blue
		glTranslatef(0.0f, 0.0f, -0.40f);
		glutWireTorus(0.02f, 0.05f, 16, 32);

		glColor3f(0.6f, 0.2f, 0.2f);	// red-dark
		glTranslatef(0.0f, -0.35f, 0.0f);
		glutWireTorus(0.02f, 0.05f, 16, 32);
	glPopMatrix();
}
