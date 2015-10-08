/*
 * Butter.cpp
 *
 * */

#include "Butter.hpp"
#include <iostream>
#include "Vector3.hpp"
#include <math.h>
#include <GL/glut.h>
using namespace std;

Butter::Butter(){

}

Butter::~Butter(){

}

/* Draws a cube of butter on x, y, z position */
static void drawCube(GLfloat x, GLfloat y, GLfloat z) {
	glPushMatrix();

	glTranslatef(x, y, z);
	glColor3f(0.0f, 0.2f, 1.0f);
	glutSolidCube(0.05f);

	glPopMatrix();
}

void Butter::draw(){
	cout << "Butter::draw()" << endl;
	Vector3 *pos = this->getPosition();

	glPushMatrix();
	glTranslatef(pos->getX(), pos->getY(), pos->getZ());
	drawCube(x, y, 0);	
	glPopMatrix();

	
	
}
