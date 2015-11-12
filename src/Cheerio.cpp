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

#include "game_config.hpp"

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
        setColor(0.9, 0.7, 0.2);
        glutSolidTorus(CHEERIO_INNER_RADIUS, CHEERIO_OUTTER_RADIUS, 6, 12);
    glPopMatrix();

	Obstacle::draw();
}

void Cheerio::update(double delta_t){
	double da = -GAME_OBJECTS_SPEED_DRAG(getSpeed().getXYModulus()) * delta_t;
	setSpeed(getSpeed().increaseMod(da));
	DynamicObject::update(delta_t);
}

bool Cheerio::processCollisionWith(GameObject &obj){
	D_TRACE();
	if(GameObject::processCollisionWith(obj)){
		DynamicObject &dobj = ((DynamicObject&)obj);

		((DynamicObject*)this)->setSpeed(dobj.getSpeed()*0.20);
		dobj.setSpeed(dobj.getSpeed()*0);
		dobj.moveToOldPosition();
		return true;
	}
	return false;
}
