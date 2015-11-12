/*
 * Candle.cpp
 *
 * */

#include "Candle.hpp"
#include "Vector3.hpp"

#include <GL/glut.h>
#include "myunits.hpp"

#define CANDLE_BODY_HEIGHT		cm(6)
#define CANDLE_WICK_WIDTH		mm(1)
#define CANDLE_WICK_HEIGHT		mm(4)
#define CANDLE_FLAME_HEIGHT		mm(4)

Candle::Candle(GLenum lightNum, double x, double y, double z) : StaticObject(x, y, z){
	_lightsource = new LightSource(lightNum);
	_lightsource->setPosition(x, y, z	+ CANDLE_BODY_HEIGHT
										+ CANDLE_WICK_HEIGHT
										+ 2*CANDLE_FLAME_HEIGHT);

	_lightsource->setDirection(0.0, 0.0, -1.0);
	_lightsource->setAmbient(0.0, 0.0, 0.0, 1.0);
	_lightsource->setDiffuse(1.0, 0.8, 0.4, 1.0);
	_lightsource->setSpecular(1.0, 0.8, 0.6, 1.0);
	_lightsource->setCutOff(85.0);		// [0, 90] or 180 (deg)
	_lightsource->setExponent(1);		// [0, 128]
}

Candle::~Candle(){
}

void Candle::draw(){
	Vector3 *pos = getPosition();

	glPushMatrix();

		/* body */
		glTranslatef(pos->getX(), pos->getY(), pos->getZ());
		setColor(0.8f, 0.7f, 0.6f);
		gluCylinder(gluNewQuadric(), cm(1), cm(1),
					CANDLE_BODY_HEIGHT, 12, 12);

		/* wick */
		glTranslatef(0, 0, CANDLE_BODY_HEIGHT);
		setColor(0.8f, 0.8f, 0.8f);
		gluCylinder(gluNewQuadric(),	CANDLE_WICK_WIDTH,
										CANDLE_WICK_WIDTH,
										CANDLE_WICK_HEIGHT, 8, 8);

		/* "flame" */
		glTranslatef(0, 0, CANDLE_WICK_HEIGHT);
		setColor(1.0f, 0.7f, 0.3f);
		glPushMatrix();
			glScalef(0.125, 0.125, 1);
			glutSolidSphere(CANDLE_FLAME_HEIGHT, 8, 8);
		glPopMatrix();
	glPopMatrix();

	_lightsource->draw();
}

void Candle::toggleLight(){
	_lightsource->toggleState();
}