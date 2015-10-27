/*
* PerspectiveCamera.cpp
*
* */

#include "PerspectiveCamera.hpp"

PerspectiveCamera::PerspectiveCamera(double fovy, double aspect, double zNear, double zFar) : Camera(zNear, zFar) {
	_fovy = fovy;
	_aspect = aspect;
}

void PerspectiveCamera::update() {

}

void PerspectiveCamera::computeProjectionMatrix() {

}

void PerspectiveCamera::computeVisualizationMatrix() {

}

PerspectiveCamera::~PerspectiveCamera() {

}
