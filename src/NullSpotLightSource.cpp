/*
 * NullSpotLightSource.cpp
 *
 * */

#include "NullSpotLightSource.hpp"
#include "Vector3.hpp"
#include <iostream>
#include <cmath>


using namespace std;
#include <GL/glut.h>

#include "debug.hpp"
#include "myunits.hpp"
#include "game_config.hpp"


NullSpotLightSource::NullSpotLightSource() : SpotLightSource(0) {
}

NullSpotLightSource::~NullSpotLightSource(){
}

bool NullSpotLightSource::getState(){
	return false;
}

bool NullSpotLightSource::setState(bool state){
	D_TRACE();
	return false;
}

bool NullSpotLightSource::toggleState(){
	D_TRACE();
	return false;
}

GLenum NullSpotLightSource::getNum(){
	return 0;
}

void NullSpotLightSource::setPosition(const Vector3 &pos){
}

void NullSpotLightSource::setPosition(float x, float y, float z){
}

void NullSpotLightSource::setAmbient(GLfloat r, GLfloat g, GLfloat b, GLfloat a){
}

void NullSpotLightSource::setDiffuse(GLfloat r, GLfloat g, GLfloat b, GLfloat a) {
}

void NullSpotLightSource::setSpecular(GLfloat r, GLfloat g, GLfloat b, GLfloat a){
}

void NullSpotLightSource::setAttenuation(GLfloat c, GLfloat l, GLfloat q){
}


/** SpotLightSource stuff **/

void NullSpotLightSource::setDirection(const Vector3 &dir){
}

void NullSpotLightSource::setDirection(GLfloat x, GLfloat y, GLfloat z){
}

void NullSpotLightSource::setCutOff(GLfloat cut_off){
}

void NullSpotLightSource::setExponent(GLfloat exp){
}

/** **/

void NullSpotLightSource::draw(){
}
