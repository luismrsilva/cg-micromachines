/*
 * Box.cpp
 *
 * */

#define _USE_MATH_DEFINES
#include <cmath>
#include "Vector3.hpp"
#include "Entity.hpp"
#include "myunits.hpp"
#include <GL/glut.h>
#include <stdbool.h>
#include "Box.hpp"
#include "debug.hpp"
#include <stdlib.h>


Box::Box() : Entity() {
	_left = _right = _top = _bottom = 0;
	_halfWidth = _halfHeight = 0;
}

Box::Box(double left, double right, double top, double bottom) :  Entity() {
	changeTo(left, right, top, bottom);
}

Box::Box(double width, double height, const Vector3 &center) : Entity() {
	changeTo(width, height, center);
}

Box::~Box(){

}

void Box::changeTo(double left, double right, double top, double bottom) {
	_left = left;
	_right = right;
	_top = top;
	_bottom = bottom;
	_halfWidth = fabs(right-left)/2.0;
	_halfHeight = fabs(top-bottom)/2.0;
}

void Box::changeTo(double width, double height, const Vector3 &center) {
	setPosition(center.getX(), center.getY(), 0);
	_halfWidth = width/2.0;
	_halfHeight = height/2.0;
	_left = center.getX() - _halfWidth;
	_right = center.getX() + _halfWidth;
	_top = center.getY() + _halfHeight;
	_bottom = center.getY() - _halfHeight;
}

void Box::draw() const{
	D_TRACE( << "box: " << _left << ", " << _right << ", " << _bottom << ", " << _top);
	glColor3f(0.0, 0.0, 1.0);
	glBegin(GL_LINE_LOOP);
	glVertex3f(_left, _top, 0);
	glVertex3f(_left, _bottom, 0);
	glVertex3f(_right, _bottom, 0);
	glVertex3f(_right, _top, 0);
	glEnd();

	glBegin(GL_POINTS);
	glColor3f(0, 1., 1.);
	const Vector3 *pos = getPosition();
	glVertex3f(pos->getX(), pos->getY(), pos->getZ());
	glEnd();

}

bool Box::isIntersecting(const Box &box) const{
	const double aX = this->getPosition()->getX();
	const double aY = this->getPosition()->getY();
	const double bX = box.getPosition()->getX();
	const double bY = box.getPosition()->getY();

	return	( fabs(aX - bX) < (_halfWidth + box._halfWidth) ) &&
			( fabs(aY - bY) < (_halfHeight + box._halfHeight) );
}
