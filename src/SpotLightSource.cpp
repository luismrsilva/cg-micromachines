/*
 * SpotLightSource.cpp
 *
 * */

#include "SpotLightSource.hpp"


SpotLightSource::SpotLightSource(GLenum num) : LightSource(num){
	setCutOff(30.0);
	setExponent(0.0);
	setDirection(0, 0, -1);
}

SpotLightSource::~SpotLightSource(){

}

void SpotLightSource::setDirection(const Vector3 &dir){
	_direction[0] = dir.getX();
	_direction[1] = dir.getY();
	_direction[2] = dir.getZ();
	_direction[3] = 0.;
}

void SpotLightSource::setDirection(GLfloat x, GLfloat y, GLfloat z){
	_direction[0] = x;
	_direction[1] = y;
	_direction[2] = z;
	_direction[3] = 0.;
}

void SpotLightSource::setCutOff(GLfloat cut_off){
	_cut_off = cut_off;
}

void SpotLightSource::setExponent(GLfloat exp){
	_exponent = exp;
}

void SpotLightSource::draw(){
	LightSource::draw();
	if(_state){
		glLightf(_num, GL_SPOT_CUTOFF, _cut_off);
		glLightfv(_num, GL_SPOT_DIRECTION, _direction);
		glLightf(_num, GL_SPOT_EXPONENT, _exponent);
	}
}
