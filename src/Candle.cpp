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
	float height = 0.06f;

	glPushMatrix();
		glTranslatef(pos->getX(), pos->getY(), pos->getZ());
		glColor3f(0.8f, 0.7f, 0.6f);
		gluCylinder(gluNewQuadric(), 0.01, 0.01, height, 12, 12);

		glTranslatef(0, 0, height);
		glColor3f(0.4f, 0.2f, 0.2f);
		gluCylinder(gluNewQuadric(), 0.002, 0.002, 0.016, 8, 8);

		glTranslatef(0, 0, 0.018);
		glColor3f(1.0f, 0.9f, 0.8f);
		glutSolidSphere(mm(6), 8, 8);
	glPopMatrix();
}

void Candle::updateBox(){

}