/*
 * Box.cpp
 *
 * */

#define _USE_MATH_DEFINES
#include <cmath>
#include "Vector3.hpp"
#include "GameObject.hpp"
#include "myunits.hpp"
#include <iostream>
using namespace std;
#include <GL/glut.h>

#include "debug.hpp"

#include "Box.hpp"

Box::Box(double left, double right, double top, double bottom) : GameObject() {
	_left = left;
	_right = right;
	_top = top;
	_bottom = bottom;
}

Box::Box(double width, double height, const Vector3 &center) : GameObject() {
	setPosition(center);
	_left = center.getX() - (width / 2);
	_right = center.getX() + (width / 2);
	_top = center.getY() + (height / 2);
	_bottom = center.getY() - (height / 2);
}

Box::~Box(){

}

void Box::draw(){
	D_TRACE();

	Vector3 *pos = this->getPosition();
	glColor3f(0.0, 0.0, 1.0);
	glBegin(GL_LINE_LOOP);
	glVertex3f(_left, _top, 0);
	glVertex3f(_left, _bottom, 0);
	glVertex3f(_right, _bottom, 0);
	glVertex3f(_right, _top, 0);
	glEnd();
}
