/*
 * Cheerio.cpp
 *
 * */

#include "Cheerio.hpp"
#include <iostream>
#include "Vector3.hpp"
#include <math.h>

#include "myunits.hpp"
using namespace std;
#include <GL/glut.h>

#include "debug.hpp"

#define CHEERIO_INNER_RADIUS	cm(1)
#define CHEERIO_OUTTER_RADIUS	cm(2)

Cheerio::Cheerio() : Obstacle(){

}

Cheerio::Cheerio(double x, double y, double z) : Obstacle(x, y, z){

}

Cheerio::~Cheerio(){

}

void Cheerio::updateBox(){
	D_TRACE();
	double box_width = CHEERIO_INNER_RADIUS + 2*CHEERIO_OUTTER_RADIUS;
	_box.changeTo(box_width, box_width, *getPosition());
}

void Cheerio::draw(){
	Vector3 *pos = this->getPosition();

    glPushMatrix();
		glTranslatef(pos->getX(), pos->getY(), pos->getZ());
        glColor3f(0.9f, 0.7f, 0.2f);
        glutSolidTorus(CHEERIO_INNER_RADIUS, CHEERIO_OUTTER_RADIUS, 6, 12);
    glPopMatrix();

	Obstacle::draw();
}
