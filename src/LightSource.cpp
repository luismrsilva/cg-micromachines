/*
 * LightSource.cpp
 *
 * */

#include "LightSource.hpp"
#include "Vector3.hpp"
#include <iostream>
#include <cmath>


using namespace std;
#include <GL/glut.h>

#include "debug.hpp"
#include "myunits.hpp"
#include "game_config.hpp"


LightSource::LightSource(GLenum num){
	_num = num;

	setState(false);

	/* Set inital values to GL defaults */
	setPosition(0.0, 0.0, 0.0);
	setDirection(0.0, 0.0,-1.0);
	setAmbient(0.0, 0.0, 0.0, 1.0);
	if(_num == GL_LIGHT0){
		setDiffuse(1.0, 1.0, 1.0, 1.0);
		setSpecular(1.0, 1.0, 1.0, 1.0);
	}else{
		setDiffuse(0.0, 0.0, 0.0, 0.0);
		setSpecular(0.0, 0.0, 0.0, 0.0);
	}
	setCutOff(180.0);
	setExponent(0.0);
}

LightSource::~LightSource(){

}

bool LightSource::getState(){
	return _state;
}

void LightSource::setState(bool state){
	_state = state;
	if(_state){
		glEnable(_num);
	}else{
		glDisable(_num);
	}
}

void LightSource::toggleState(){
	setState(!getState());
}

GLenum LightSource::getNum(){
	return _num;
}

void LightSource::setPosition(const Vector3 &pos){
	_position[0] = pos.getX();
	_position[1] = pos.getY();
	_position[2] = pos.getZ();
	_position[3] = 1.;
}

void LightSource::setPosition(float x, float y, float z){
	_position[0] = x;
	_position[1] = y;
	_position[2] = z;
	_position[3] = 1.;
}

void LightSource::setDirection(const Vector3 &dir){
	_direction[0] = dir.getX();
	_direction[1] = dir.getY();
	_direction[2] = dir.getZ();
	_direction[3] = 0.;
}

void LightSource::setDirection(GLfloat x, GLfloat y, GLfloat z){
	_direction[0] = x;
	_direction[1] = y;
	_direction[2] = z;
	_direction[3] = 0.;
}

void LightSource::setCutOff(GLfloat cut_off){
	_cut_off = cut_off;
}

void LightSource::setExponent(GLfloat exp){
	_exponent = exp;
}

void LightSource::setAmbient(GLfloat r, GLfloat g, GLfloat b, GLfloat a){
	_ambient[0] = r;
	_ambient[1] = g;
	_ambient[2] = b;
	_ambient[3] = a;
}

void LightSource::setDiffuse(GLfloat r, GLfloat g, GLfloat b, GLfloat a) {
	_diffuse[0] = r;
	_diffuse[1] = g;
	_diffuse[2] = b;
	_diffuse[3] = a;
}

void LightSource::setSpecular(GLfloat r, GLfloat g, GLfloat b, GLfloat a){
	_specular[0] = r;
	_specular[1] = g;
	_specular[2] = b;
	_specular[3] = a;
}

void LightSource::draw(){
	if(_state){
		glLightfv(_num, GL_AMBIENT, _ambient);
		glLightfv(_num, GL_DIFFUSE, _diffuse);
		glLightfv(_num, GL_SPECULAR, _specular);
		glLightfv(_num, GL_POSITION, _position);

		glLightf(_num, GL_SPOT_CUTOFF, _cut_off);
		glLightfv(_num, GL_SPOT_DIRECTION, _direction);
		glLightf(_num, GL_SPOT_EXPONENT, _exponent);
	}
}
