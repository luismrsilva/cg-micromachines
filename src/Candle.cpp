/*
 * Candle.cpp
 *
 * */

#include "Candle.hpp"
#include "Vector3.hpp"

#include <GL/glut.h>
#include "myunits.hpp"
#include "PointLightSource.hpp"

#define CANDLE_BODY_HEIGHT		cm(15)
#define CANDLE_WICK_HEIGHT		mm(9)
#define CANDLE_FLAME_HEIGHT		mm(6)

Candle::Candle(GLenum lightNum, double x, double y, double z) : StaticObject(x, y, z){
	_lightsource = new PointLightSource(lightNum);
	_lightsource->setPosition(x, y, z	+ CANDLE_BODY_HEIGHT
										+ CANDLE_WICK_HEIGHT
										+ 2*CANDLE_FLAME_HEIGHT);

	_lightsource->setAmbient(0.0, 0.0, 0.0, 1.0);
	_lightsource->setDiffuse(1.0, 0.8, 0.4, 1.0);
	_lightsource->setSpecular(1.0, 0.8, 0.6, 1.0);
	_lightsource->setAttenuation(1, 0, 4);

	setMaterialColor(0.8, 0.0, 0.0);

	_wickMaterial = new Material(0.5, 0.3, 0.1, 1.0);
	_flameMaterial = new Material(0.9, 0.8, 0.2, 0.1);
}

Candle::~Candle(){
	delete _wickMaterial;
	delete _flameMaterial;
}


void Candle::setLightColor(GLfloat r, GLfloat g, GLfloat b){
	_lightsource->setAmbient(r*0.01, g*0.01, b*0.01, 1.0);
	_lightsource->setDiffuse(r, g, b, 1.0);
	_lightsource->setSpecular(	r*0.6 + 0.4,
								g*0.6 + 0.4,
								b*0.6 + 0.4, 1.0);
}

void Candle::draw(){
	Vector3 *pos = getPosition();

	glPushMatrix();

		/* body */
		glTranslatef(pos->getX(), pos->getY(), pos->getZ());
		_material->apply();
		gluCylinder(gluNewQuadric(), cm(1), cm(1),
					CANDLE_BODY_HEIGHT, 12, 12);

		/* wick */
		glTranslatef(0, 0, CANDLE_BODY_HEIGHT + CANDLE_WICK_HEIGHT/2);
		_wickMaterial->apply();
		glPushMatrix();
			glScalef(0.125, 0.125, 1);
			glutSolidSphere(CANDLE_WICK_HEIGHT, 8, 8);
		glPopMatrix();

		/* "flame" */
		glTranslatef(0, 0, CANDLE_WICK_HEIGHT + CANDLE_FLAME_HEIGHT/4);
		_flameMaterial->apply();
		glPushMatrix();
			glScalef(0.125, 0.125, 1);
			glutSolidSphere(CANDLE_FLAME_HEIGHT, 8, 8);
		glPopMatrix();
	glPopMatrix();

	_lightsource->draw();
}

void Candle::toggleLight(){
	if(_lightsource->toggleState()){
		_flameMaterial->setEmission(10, 10, 5, 1.0);
	}else{
		_flameMaterial->setEmission(0, 0, 0, 1.0);
	}
}
