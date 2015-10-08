/*
 * Roadside.cpp
 * 
 * */

#include "Roadside.hpp"
#include "Vector3.hpp"
#include <math.h>
#include <GL/glut.h>

#include "myunits.hpp"

Roadside::Roadside(){

}

Roadside::~Roadside(){

}

/* Draws a torus on x, y, z position */
static void drawTorus(GLfloat x, GLfloat y, GLfloat z){
	glPushMatrix();

	glTranslatef(x, y, z);
	glColor3f(1.0f, 1.0f, 0.0f);
	glutSolidTorus(0.01f, 0.02f, 6, 16);
	
	glPopMatrix();
}

static void drawTorusLineXY(double sX, double sY, double eX, double eY){
	double m = (eY-sY)/((eX-sX));
	double b = sY - m*sX;
	
	for(double x = sX; x <= eX; x+=0.1f){
		drawTorus(x, m*x+b, 0);
	}
	
}

void Roadside::draw(){
	Vector3 *pos = this->getPosition();
	
	glPushMatrix();
	
	glTranslatef(pos->getX(), pos->getY(), pos->getZ());
	
	
	drawTorusLineXY(-1.4,  1.4,	 1.4,  1.4);
	
	drawTorusLineXY( 1.4,  1.4,	 1.4, -1.4);
	
	
	
	
	glPopMatrix();
}
