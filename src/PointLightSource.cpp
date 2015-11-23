/*
 * PointLightSource.cpp
 *
 * */

#include "PointLightSource.hpp"


PointLightSource::PointLightSource(GLenum num) : LightSource(num){
	_constantAttenuation = 1;
	_linearAttenuation = 0;
	_quadraticAttenuation = 0;
}

PointLightSource::~PointLightSource(){

}


void PointLightSource::setAttenuation(GLfloat c, GLfloat l, GLfloat q){
	_constantAttenuation = c;
	_linearAttenuation = l;
	_quadraticAttenuation = q;
}

void PointLightSource::draw(){
	LightSource::draw();
	if(_state){
		glLightf(_num, GL_CONSTANT_ATTENUATION, _constantAttenuation);
		glLightf(_num, GL_LINEAR_ATTENUATION, _linearAttenuation);
		glLightf(_num, GL_QUADRATIC_ATTENUATION, _quadraticAttenuation);
	}
}
