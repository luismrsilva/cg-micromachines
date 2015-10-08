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
    //glScalef(20.0f, 20.0f, 20.0f);
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

		glTranslatef(00.00f, 0.0f, 0.02f);
		glutSolidTorus(0.002f, 0.005f, 16, 32);

		//glColor3f(0.0f, 1.0f, 0.0f);	// green
		glTranslatef(0.0f, 0.035f, 0.0f);
		glutSolidTorus(0.002f, 0.005f, 16, 32);

		//glColor3f(0.0f, 0.0f, 1.0f);	// blue
		glTranslatef(0.0f, 0.0f, -0.040f);
		glutSolidTorus(0.002f, 0.005f, 16, 32);

		//glColor3f(0.6f, 0.2f, 0.2f);	// red-dark
		glTranslatef(0.0f, -0.035f, 0.0f);
		glutSolidTorus(0.002f, 0.005f, 16, 32);
	glPopMatrix();
    //dglScalef(0.1f, 0.1f, 0.1f);
}
