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


	drawTorusLineXY(-1.4,  1.4,	 1.45,  1.4);
	drawTorusLineXY(-1.2,  1.2,	 1.25,  1.2);

	drawTorusLineXY( 1.4,  1.4,	 1.4, -1.4);
	drawTorusLineXY( 1.2,  1.2,	 1.2, -1.2);

	drawTorusLineXY(  0.0, -1.4,	 1.4, -1.4);
	drawTorusLineXY(  0.2, -1.2,	 1.2, -1.2);

	drawTorusLineXY(  0.0, -1.4,	 1.4, -1.4);
	drawTorusLineXY(  0.2, -1.2,	 1.2, -1.2);

	drawTorusLineXY(  0.0, -1.4,	 0.0,  0.0);
	drawTorusLineXY(  0.2, -1.2,	 0.2, -0.2);

	drawTorusLineXY(  0.0,  0.0,	 0.4,  0.0);
	drawTorusLineXY(  0.2, -0.2,	 0.6, -0.2);

	drawTorusLineXY(0,0,0.8,0);
	drawTorusLineXY(0.2,-0.2,1.0,-0.2);

	drawTorusLineXY(0.8,0,0.8,0.8);
	drawTorusLineXY(1.0,-0.2,1.0,1.0);

	drawTorusLineXY(0.85,0.8,-0.4,0.8);
	drawTorusLineXY(1.05,1.0,-0.6,1.0);

	drawTorusLineXY(-0.4,0.8,-0.4,-1.4);
	drawTorusLineXY(-0.6,1.0,-0.6,-1.2);
	drawTorusLineXY(-0.6,-1.2,-1.2,-1.2);
	drawTorusLineXY(-0.4,-1.4,-1.4,-1.4);
	drawTorusLineXY(-1.2,-1.2,-1.2,1.2);
	drawTorusLineXY(-1.4,-1.4,-1.4,1.4);


	glPopMatrix();
}
