/*
 * Camera.cpp
 *
 * */

#include "Camera.hpp"

Camera::Camera(double near, double far){
	_near = near;
	_far = far;
}

Camera::~Camera(){

}

void Camera::update(){
	computeProjectionMatrix();
	computeVisualizationMatrix();
}

void Camera::computeProjectionMatrix(){

}

void Camera::computeVisualizationMatrix(){

}
