/*
* PerspectiveCamera.cpp
*
* */

#include "PerspectiveCamera.hpp"
#include <GL/glut.h>

PerspectiveCamera::PerspectiveCamera(double fovy, double aspect, double zNear, double zFar) : Camera(zNear, zFar) {
	_fovy = fovy;
	_aspect = aspect;
}

void PerspectiveCamera::update() {

}

void PerspectiveCamera::computeProjectionMatrix() {
	gluPerspective(_fovy, _aspect, _near, _far);
}

void PerspectiveCamera::computeVisualizationMatrix() {
	Vector3 * pos = this->getPosition();
	gluLookAt(pos->getX(), pos->getY(), pos->getZ(), 0, 0, -1, 0, 1, 0);

}
PerspectiveCamera::~PerspectiveCamera() {

}
