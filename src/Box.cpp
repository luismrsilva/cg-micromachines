/*
 * Box.cpp
 *
 * */

#define _USE_MATH_DEFINES
#include "Vector3.hpp"
#include "Entity.hpp"
#include "myunits.hpp"
#include <GL/glut.h>
#include <stdbool.h>
#include "Box.hpp"
#include "debug.hpp"


Box::Box() : Entity() {
	_left = _right = _top = _bottom = 0;
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
}

void Box::changeTo(double width, double height, const Vector3 &center) {
	setPosition(center.getX(), center.getY(), 0);
	_left = center.getX() - (width / 2);
	_right = center.getX() + (width / 2);
	_top = center.getY() + (height / 2);
	_bottom = center.getY() - (height / 2);
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

	Box *a = (Box*) this;
	Box *b = (Box*) &box;

	if (a->_right < b->_right){
		a = (Box*) &box;
		b = (Box*) this;
	}

	//Verificar se ha intersecao horizontal
	if (b->_left <= a->_left && a->_left <= b->_right) {
		if (a->_top < b->_top) {
			a = (Box*)&box;
			b = (Box*) this;
		}
		//Verificar se ha intersecao vertical
		if (b->_bottom <= a->_bottom && a->_bottom <= b->_top) {
			return true;
		}
	}

	return false;
}
