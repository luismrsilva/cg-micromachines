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

	if (a->_left < b->_left){
		a = (Box*) &box;
		b = (Box*) this;
	}

	//Verificar se ha intersecao horizontal
	if (b->_left <= a->_left && a->_left <= b->_right) {
		if (a->_bottom < b->_bottom) {
			a = (Box*)&box;
			b = (Box*) this;
		}
		//Verificar se ha intersecao vertical
		if (b->_bottom <= a->_bottom && a->_bottom <= b->_top) {
			return true;
		}
	}

	#define dist(x,y)	sqrt(x*x+y*y)

	double a_w = abs(a->_right - a->_left)/2;
	double a_h = abs(a->_bottom - a->_top)/2;
	double b_w = abs(b->_right - b->_left)/2;
	double b_h = abs(b->_bottom - b->_top)/2;

	double a_x = (a->_left + a->_right)/2;
	double a_y = (a->_bottom + a->_top)/2;
	double b_x = (b->_left + b->_right)/2;
	double b_y = (a->_bottom + a->_top)/2;

	double x_dist = a_w + b_w;
	double y_dist = a_h + b_h;

	if(dist(a_x, b_x) < x_dist){
		return true;
	}
	if(dist(a_y, b_y) < y_dist){
		return true;
	}

	return false;
}
