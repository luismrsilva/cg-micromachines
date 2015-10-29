/*
 * Roadside.cpp
 *
 * */

#include "Roadside.hpp"
#include "Vector3.hpp"
#include "Cheerio.hpp"
#include <math.h>
#include <iostream>
using namespace std;
#include <GL/glut.h>
#include "myunits.hpp"

#include "debug.hpp"

Roadside::Roadside() : StaticObject(){
	drawCheerioLineXY(-1.0,-0.7, -1.0, 0.7);	// left inner
	drawCheerioLineXY(-1.4,-1.1, -1.4, 1.1);	// left outer
	drawCheerioLineXY(-1.1, 1.4, 1.15, 1.4);	// top outer
	drawCheerioLineXY(-0.6, 1.0, 1.0,  1.0);	// top inner
	drawCheerioLineXY( 1.4, 1.1, 1.4, -1.1);	// right outer
	drawCheerioLineXY( 1.0, 1.1, 1.0, -0.8);	// right inner

	drawCheerioLineXY(-1.1, -1.4, 1.2, -1.4);	// bottom outer

	drawCheerioLineXY(-0.2, 0.5, -0.2, -1.4);	// center right
	drawCheerioLineXY(-0.6, 1.0, -0.6, -0.8);	// center left

	drawCheerioLineXY( 0.4, -1.0, 0.9, -1.0);	// P-down down
	drawCheerioLineXY( 0.2, -0.8, 0.2, -0.5);	// P-down left
	drawCheerioLineXY( 0.4, -0.4, 1.0, -0.4);	// P-down up
	drawCheerioLineXY(-0.2, 0.0, 0.5, 0.0);	// P-up down
	drawCheerioLineXY( 0.6, 0.2, 0.6, 0.5);	// P-up right
	drawCheerioLineXY( 0.5, 0.6, 0.0, 0.6);	// P-up up

	// Corner Curves
	drawCheerioBezierXY(-1.4, 1.1, -1.4, 1.4, -1.1, 1.4, 5);	// top left
	drawCheerioBezierXY( 1.4, 1.1,  1.4, 1.4,  1.1, 1.4, 5);	// top right
	drawCheerioBezierXY(-1.4,-1.1, -1.4,-1.4, -1.1,-1.4, 5);	// bottom left
	drawCheerioBezierXY( 1.4,-1.1,  1.4,-1.4,  1.1,-1.4, 5);	// bottom right

	// Other Curves
	drawCheerioBezierXY(-1.0,-0.8,	-1.0,-1.0,	-0.8,-1.0,	3);
	drawCheerioBezierXY(-0.8,-1.0,	-0.6,-1.0,	-0.6,-0.8,	3);
	drawCheerioBezierXY(-0.6, 1.0,	-1.0, 1.0,	-1.0, 0.6,	6);
	drawCheerioBezierXY( 0.4, 0.0,	 0.6, 0.0,	 0.6, 0.2,	3);
	drawCheerioBezierXY( 0.6, 0.4,	 0.6, 0.6,	 0.4, 0.6,	3);
	drawCheerioBezierXY( 0.0, 0.6,	-0.2, 0.6,	-0.2, 0.4,	3);
	drawCheerioBezierXY( 0.4,-0.4,	 0.2,-0.4,	 0.2,-0.6,	3);
	drawCheerioBezierXY( 0.2,-0.8,	 0.2,-1.0,	 0.4,-1.0,	3);
	drawCheerioBezierXY( 0.8,-1.0,	 1.0,-1.0,	 1.0,-0.8,	3);
}

Roadside::~Roadside(){
	for(vector<Cheerio*>::iterator i = _cheerios.begin(); i != _cheerios.end(); i++){
		delete (*i);
	}
}

/* Draws a torus on x, y, z position */
void Roadside::drawCheerio(GLfloat x, GLfloat y, GLfloat z){
	_cheerios.push_back(new Cheerio(x, y, z));
}

void Roadside::drawCheerioLineXY(double sX, double sY, double eX, double eY){
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
			drawCheerio(sX, y, 0);
		}
		return;
	}

	if(m > 1){
		for(double y = sY; y <= eY; y+=0.1f){
			drawCheerio((y-b)/m, y, 0);
		}
	}else{
		for(double x = sX; x <= eX; x+=0.1f){
			drawCheerio(x, m*x+b, 0);
		}
	}

}

void Roadside::drawCheerioBezierXY(double x1, double y1, double x2, double y2,
						double x3, double y3, double n_points){
	double inc = 1.0 / (n_points < 1.0 ? 1.0 : n_points);
	for(double i = 0.; i < 1.0f; i+=inc){
		double x = (1.-i)*((1.-i)*x1+i*x2) + i*((1.-i)*x2+i*x3);
		double y = (1.-i)*((1.-i)*y1+i*y2) + i*((1.-i)*y2+i*y3);
		drawCheerio(x, y, 0.);
	}
}

void Roadside::updateBox(){
	D_TRACE();
	for(vector<Cheerio*>::iterator i = _cheerios.begin(); i != _cheerios.end(); i++){
		(*i)->updateBox();
	}
}

void Roadside::draw(){
	for(vector<Cheerio*>::iterator i = _cheerios.begin(); i != _cheerios.end(); i++){
		(*i)->draw();
	}
}
