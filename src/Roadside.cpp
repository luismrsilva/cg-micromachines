/*
 * Roadside.cpp
 *
 * */

#include "Roadside.hpp"
#include "Vector3.hpp"
#include <math.h>
#include <iostream>
using namespace std;
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
	glColor3f(0.9f, 0.7f, 0.2f);
	glutSolidTorus( cm(1), cm(2), 6, 12);

	glPopMatrix();
}

static void drawTorusLineXY(double sX, double sY, double eX, double eY){
	double m, b;
	m = (eY-sY)/(eX-sX);
	b = sY - m*sX;

	if(sY > eY){
		double t = eY;
		eY = sY;
		sY = t;
	}

	if(sX > eX){
		double t = eX;
		eX = sX;
		sX = t;
	}else if(sX == eX){
		for(double y = sY; y <= eY; y+=0.1f){
			drawTorus(sX, y, 0);
		}
		return;
	}

	if(m > 1){
		for(double y = sY; y <= eY; y+=0.1f){
			drawTorus((y-b)/m, y, 0);
		}
	}else{
		for(double x = sX; x <= eX; x+=0.1f){
			drawTorus(x, m*x+b, 0);
		}
	}

}

void Roadside::draw(){
	Vector3 *pos = this->getPosition();

	glPushMatrix();

	glTranslatef(pos->getX(), pos->getY(), pos->getZ());

	drawTorusLineXY(-1.0,-1.0, -1.0, 1.0);	// left inner
	drawTorusLineXY(-1.4,-1.4, -1.4, 1.4);	// left outer

	drawTorusLineXY(-1.4, 1.4, 1.45, 1.4);	// top outer
	drawTorusLineXY(-1.0, 1.0, 1.1,  1.0);	// top inner

	drawTorusLineXY( 1.4, 1.4, 1.4, -1.4);	// right outer
	drawTorusLineXY( 1.0, 1.1, 1.0, -1.0);	// right inner

	drawTorusLineXY(-1.4, -1.4, 1.4, -1.4);	// bottom outer

	drawTorusLineXY(-0.2, 0.6, -0.2, -1.4);	// middle center right
	drawTorusLineXY(-0.6, 1.0, -0.6,-1.0);	// middle center left

	drawTorusLineXY( 0.2, -1.0, 1.1, -1.0);	// P-down down
	drawTorusLineXY( 0.2, -1.0, 0.2, -0.4);	// P-down left
	drawTorusLineXY( 0.2,-0.4, 1.0,-0.4);	// P-down up

	drawTorusLineXY(-0.2, 0.0, 0.6, 0.0);	// P-up down
	drawTorusLineXY( 0.6, 0.0, 0.6, 0.7);	// P-up right
	drawTorusLineXY( 0.6, 0.6,-0.2, 0.6);	// P-up up

	drawTorusLineXY(-0.6,-1.0, -1.0,-1.0);	// bottom left inner

	glPopMatrix();
}
