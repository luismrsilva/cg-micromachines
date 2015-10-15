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

void drawTorusBezierXY(double x1, double y1, double x2, double y2,
						double x3, double y3, double n_points){
	double inc = 1.0 / (n_points < 1.0 ? 1.0 : n_points);
	for(double i = 0.; i < 1.0f; i+=inc){
		double x = (1.-i)*((1.-i)*x1+i*x2) + i*((1.-i)*x2+i*x3);
		double y = (1.-i)*((1.-i)*y1+i*y2) + i*((1.-i)*y2+i*y3);
		drawTorus(x, y, 0.);
	}
}

void Roadside::draw(){
	Vector3 *pos = this->getPosition();

	glPushMatrix();

	glTranslatef(pos->getX(), pos->getY(), pos->getZ());

	drawTorusLineXY(-1.0,-0.7, -1.0, 0.7);	// left inner
	drawTorusLineXY(-1.4,-1.1, -1.4, 1.1);	// left outer

	drawTorusLineXY(-1.1, 1.4, 1.15, 1.4);	// top outer
	drawTorusLineXY(-0.6, 1.0, 1.1,  1.0);	// top inner

	drawTorusLineXY( 1.4, 1.1, 1.4, -1.1);	// right outer
	drawTorusLineXY( 1.0, 1.1, 1.0, -0.8);	// right inner

	drawTorusLineXY(-1.1, -1.4, 1.2, -1.4);	// bottom outer

	drawTorusLineXY(-0.2, 0.5, -0.2, -1.4);	// center right
	drawTorusLineXY(-0.6, 1.0, -0.6, -0.8);	// center left

	drawTorusLineXY( 0.4, -1.0, 0.9, -1.0);	// P-down down
	drawTorusLineXY( 0.2, -0.8, 0.2, -0.5);	// P-down left
	drawTorusLineXY( 0.4, -0.4, 1.0, -0.4);	// P-down up

	drawTorusLineXY(-0.2, 0.0, 0.5, 0.0);	// P-up down
	drawTorusLineXY( 0.6, 0.2, 0.6, 0.5);	// P-up right
	drawTorusLineXY( 0.5, 0.6, 0.0, 0.6);	// P-up up

	// Corner Curves
	drawTorusBezierXY(-1.4, 1.1, -1.4, 1.4, -1.1, 1.4, 5);	// top left
	drawTorusBezierXY( 1.4, 1.1,  1.4, 1.4,  1.1, 1.4, 5);	// top right
	drawTorusBezierXY(-1.4,-1.1, -1.4,-1.4, -1.1,-1.4, 5);	// bottom left
	drawTorusBezierXY( 1.4,-1.1,  1.4,-1.4,  1.1,-1.4, 5);	// bottom right

	// Other Curves
	drawTorusBezierXY(-1.0,-0.8,	-1.0,-1.0,	-0.8,-1.0,	3);
	drawTorusBezierXY(-0.8,-1.0,	-0.6,-1.0,	-0.6,-0.8,	3);
	drawTorusBezierXY(-0.6,	1.0,	-1.0, 1.0,	-1.0, 0.6,	6);
	drawTorusBezierXY( 0.4,	0.0,	 0.6, 0.0,	 0.6, 0.2,	4);
	drawTorusBezierXY( 0.6,	0.4,	 0.6, 0.6,	 0.4, 0.6,	4);
	drawTorusBezierXY( 0.0,	0.6,	-0.2, 0.6,	-0.2, 0.4,	4);
	drawTorusBezierXY( 0.4,-0.4,	 0.2,-0.4,	 0.2,-0.6,	4);
	drawTorusBezierXY( 0.2,-0.8,	 0.2,-1.0,	 0.4,-1.0,	4);
	drawTorusBezierXY( 0.8,-1.0,	 1.0,-1.0,	 1.0,-0.8,	4);


	glPopMatrix();
}
