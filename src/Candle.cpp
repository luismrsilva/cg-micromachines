/*
 * Candle.cpp
 *
 * */

#include "Candle.hpp"
#include "Vector3.hpp"

#include <GL/glut.h>
#include "myunits.hpp"

Candle::Candle(){
	_lightsource = new LightSource(GL_LIGHT0);
}

Candle::Candle(double x, double y, double z) : StaticObject(x, y, z){
	_lightsource = new LightSource(GL_LIGHT0);
}

Candle::~Candle(){
}

void Candle::update(double delta_t){

}

void Candle::draw(){
	Vector3 *pos = getPosition();

    glPushMatrix();
		glTranslatef(pos->getX(), pos->getY(), pos->getZ());
        glColor3f(0.9f, 0.9f, 0.9f);
        gluCylinder(gluNewQuadric(), 0.4f, 0.4f, 0.6f, 10, 10);
    glPopMatrix();
}

void Candle::updateBox(){

}