/*
 * Roadside.cpp
 * 
 * */

#include "Roadside.hpp"
#include "Vector3.hpp"
#include <math.h>
#include <GL/glut.h>

Roadside::Roadside(){

}

Roadside::~Roadside(){

}

/* Draws a torus on x, y, z position */
static void drawTorus(GLfloat x, GLfloat y, GLfloat z){
	glPushMatrix();
	
	glTranslatef(x, y, z);
	glColor3f(1.0f, 1.0f, 0.0f);
	glutSolidTorus(0.011f, 0.03f, 6, 16);
	
	glPopMatrix();
}

void Roadside::draw(){
	Vector3 *pos = this->getPosition();
	
	glPushMatrix();
	
	glTranslate3f(pos->getX(), pos->getY(), pos->getZ());
	
	for(float x = -1.2; x < 0.6f; x+=0.1f){
		float y = log(x + 1.5f);
		drawTorus(x, y, 0);
		drawTorus(x+0.8f, y, 0);
	}
	
	glPopMatrix();
}
