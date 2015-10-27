/*
 * OrthogonalCamera.cpp
 *
 * */

#include "OrthogonalCamera.hpp"
#include "game_config.hpp"
#include <GL/glut.h>

OrthogonalCamera::OrthogonalCamera(GameManager *gameManager, double left, double right, double bottom, double top, double near, double far) : Camera(near, far){
	_left = left;
	_right = right;
	_bottom = bottom;
	_top = top;
	_gameManager = gameManager;
}


void OrthogonalCamera::computeProjectionMatrix(){
	GLsizei w = _gameManager->getViewWidth();
	GLsizei h = _gameManager->getViewHeight();
	if(w<h){
		glOrtho(	_left,		_right,
					_bottom*h/w,_top*h/w,
					_near,		_far);
	}else{
		glOrtho(	_left*w/h,	_right*w/h,
					_bottom,	_top,
					_near,		_far);
	}
}

void OrthogonalCamera::computeVisualizationMatrix(){

}

OrthogonalCamera::~OrthogonalCamera(){

}
