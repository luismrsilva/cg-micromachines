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

Cheerio::Cheerio() : Obstacle(){

}

Cheerio::Cheerio(double x, double y, double z) : Obstacle(x, y, z){

}

Cheerio::~Cheerio(){

}

void Cheerio::draw(){
	Vector3 *pos = this->getPosition();

    glPushMatrix();
		glTranslatef(pos->getX(), pos->getY(), pos->getZ());
        glColor3f(0.9f, 0.7f, 0.2f);
        glutSolidTorus(cm(1), cm(2), 6, 12);
    glPopMatrix();

}
