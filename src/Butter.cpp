/*
 * Butter.cpp
 *
 * */

#include "Butter.hpp"
#include <iostream>
#include "Vector3.hpp"
#include <math.h>

#include "myunits.hpp"
using namespace std;
#include <GL/glut.h>

#include "debug.hpp"
#include "game_config.hpp"


Butter::Butter() : Obstacle(){
	setMaterialColor(0.8, 0.8, 0.45);
}

Butter::Butter(double x, double y, double z) : Obstacle(x, y, z){
	setMaterialColor(0.8, 0.8, 0.45);
}

Butter::~Butter(){

}

void Butter::updateBox(){
	_box.changeTo(BUTTER_SIZE_X, BUTTER_SIZE_Y, *getPosition());
}

/* Draws a cube of butter on x, y, z position */
void Butter::draw(){
	Vector3 *pos = getPosition();

	glPushMatrix();
		_material->apply();
		glTranslatef(pos->getX(), pos->getY(), pos->getZ());
		glScalef(BUTTER_SIZE_X, BUTTER_SIZE_Y, BUTTER_SIZE_Z);
		glutSolidCube(1);
	glPopMatrix();

	Obstacle::draw();
}

void Butter::update(double delta_t){
	double da = -GAME_OBJECTS_SPEED_DRAG(getSpeed().getXYModulus()) * delta_t;
	setSpeed(getSpeed().increaseMod(da));
	DynamicObject::update(delta_t);
}

bool Butter::processCollisionWith(GameObject &obj){
	D_TRACE();
	if(GameObject::processCollisionWith(obj)){
		DynamicObject &dobj = ((DynamicObject&)obj);

		((DynamicObject*)this)->setSpeed(dobj.getSpeed()*0.4);
		dobj.setSpeed(dobj.getSpeed()*0);
		dobj.moveToOldPosition();
		return true;
	}
	return false;
}
