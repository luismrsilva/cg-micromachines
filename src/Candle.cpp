/*
 * Candle.cpp
 *
 * */

#include "Candle.hpp"
#include "Vector3.hpp"

#include <GL/glut.h>
#include "myunits.hpp"

Candle::Candle(GLenum lightNum, double x, double y, double z) : StaticObject(x, y, z){
	_lightsource = new LightSource(lightNum);
	_lightsource->setPosition(x, y, z + mm(76));
}

Candle::~Candle(){
}

void Candle::update(double delta_t){

}

void Candle::draw(){
	Vector3 *pos = getPosition();
	float height = 0.06f;

	glPushMatrix();

		/* body */
		glTranslatef(pos->getX(), pos->getY(), pos->getZ());
		glColor3f(0.8f, 0.7f, 0.6f);
		gluCylinder(gluNewQuadric(), cm(1), cm(1), height, 12, 12);

		/* wick */
		glTranslatef(0, 0, height);
		glColor3f(0.8f, 0.8f, 0.8f);
		gluCylinder(gluNewQuadric(), mm(2), mm(2), mm(16), 8, 8);

		/* "flame" */
		glTranslatef(0, 0, 0.018);
		glColor3f(1.0f, 0.9f, 0.8f);
		glutSolidSphere(mm(6), 8, 8);
	glPopMatrix();

	_lightsource->draw();
}

void Candle::toggleLight(){
	_lightsource->toggleState();
}

void Candle::updateBox(){

}
