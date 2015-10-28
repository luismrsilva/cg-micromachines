/*
* PerspectiveCamera.cpp
*
* */

#include "PerspectiveCamera.hpp"
#include <GL/glut.h>
#include "debug.hpp"

PerspectiveCamera::PerspectiveCamera(double fovy, double aspect, double zNear, double zFar) : Camera(zNear, zFar) {
	_fovy = fovy;
	_aspect = aspect;
	_center = Vector3(0, 0, -1);
	_up = Vector3(0, 0, 1);
}


void PerspectiveCamera::setCenter(const Vector3 &center){
	_center = center;
}

void PerspectiveCamera::setUp(const Vector3 &up){
	_up = up;
}

void PerspectiveCamera::computeProjectionMatrix() {
	double aspect = (double)glutGet(GLUT_WINDOW_WIDTH)/glutGet(GLUT_WINDOW_HEIGHT);
	gluPerspective(_fovy, aspect, _near, _far);
}

void PerspectiveCamera::computeVisualizationMatrix() {
	Vector3 * pos = this->getPosition();

	D_PRINT("pcam_pos:\t" << pos->getX() << ", " << pos->getY() << ", " << pos->getZ());
	D_PRINT("pcam_cen:\t" << _center.getX() << ", " << _center.getY() << ", " << _center.getZ());
	D_PRINT("pcam_up:\t" << _up.getX() << ", " << _up.getY() << ", " << _up.getZ());

	gluLookAt(	pos->getX(), pos->getY(), pos->getZ(),
				_center.getX(), _center.getY(), _center.getZ(),
				_up.getX(), _up.getY(), _up.getZ());

}
PerspectiveCamera::~PerspectiveCamera() {

}
