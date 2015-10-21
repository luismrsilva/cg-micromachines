/*
 * OrthogonalCamera.cpp
 *
 * */

#include "OrthogonalCamera.hpp"

OrthogonalCamera::OrthogonalCamera(double left, double right, double bottom, double top, double near, double far) : Camera(near, far){
	_left = left;
	_right = right;
	_bottom = bottom;
	_top = top;
}

void OrthogonalCamera::update(){

}

void OrthogonalCamera::computeProjectionMatrix(){

}

void OrthogonalCamera::computeVisualizationMatrix(){

}

OrthogonalCamera::~OrthogonalCamera(){

}
