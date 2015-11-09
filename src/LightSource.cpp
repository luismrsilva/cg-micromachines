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
}

LightSource::~LightSource(){

}

bool LightSource::getState(){
	return _state;
}

void LightSource::setState(bool state){
	_state = state;
}

GLenum LightSource::getNum(){
	return _num;
}

void LightSource::setPosition(const Vector3 &pos){
	*_position = pos;
}

void LightSource::setDirection(const Vector3 &dir){
	*_direction = dir;
}

void LightSource::setCutOff(double cut_off){
	_cut_off = cut_off;
}

void LightSource::setExponent(double exp){
	_exponent = exp;
}

void LightSource::setAmbient(double r, double g, double b, double a){
	_ambient[0] = r;
	_ambient[1] = g;
	_ambient[2] = b;
	_ambient[3] = b;
}

void LightSource::setDiffuse(double r, double g, double b, double a){
	_diffuse[0] = r;
	_diffuse[1] = g;
	_diffuse[2] = b;
	_diffuse[3] = b;
}

void LightSource::setSpecular(double r, double g, double b, double a){
	_specular[0] = r;
	_specular[1] = g;
	_specular[2] = b;
	_specular[3] = a;
}

void LightSource::draw(){

}
