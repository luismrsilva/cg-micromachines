/*
 * Material.cpp
 *
 * */

#include "Material.hpp"
#include "Vector3.hpp"
#include <iostream>
#include <cmath>

using namespace std;
#include <GL/glut.h>

#include "debug.hpp"
#include "myunits.hpp"
#include "game_config.hpp"


Material::Material(GLfloat r, GLfloat g, GLfloat b){
	setDefaultMaterial(r, g, b);
}

Material::Material(GLfloat r, GLfloat g, GLfloat b, GLfloat a){
	setDefaultMaterial(r, g, b, a);
}

Material::~Material(){
}

void Material::setDefaultMaterial(GLfloat r, GLfloat g, GLfloat b){
	setAmbient(r, g, b, 1.0);
	setDiffuse(r, g, b, 1.0);
	setSpecular(1.0, 1.0, 1.0, 1.0);
	setShininess(69.0);
}

void Material::setDefaultMaterial(GLfloat r, GLfloat g, GLfloat b, GLfloat a){
	setDefaultMaterial(r, g, b);
	setAlpha(a);
}

void Material::setAlpha(GLfloat a){
	_diffuse[3] = a;
}

void Material::setAmbient(GLfloat r, GLfloat g, GLfloat b, GLfloat a){
	_ambient[0] = r;
	_ambient[1] = g;
	_ambient[2] = b;
	_ambient[3] = a;
}

void Material::setDiffuse(GLfloat r, GLfloat g, GLfloat b, GLfloat a){
	_diffuse[0] = r;
	_diffuse[1] = g;
	_diffuse[2] = b;
	_diffuse[3] = a;
}

void Material::setSpecular(GLfloat r, GLfloat g, GLfloat b, GLfloat a){
	_specular[0] = r;
	_specular[1] = g;
	_specular[2] = b;
	_specular[3] = a;
}

void Material::setEmission(GLfloat r, GLfloat g, GLfloat b, GLfloat a){
	_emission[0] = r;
	_emission[1] = g;
	_emission[2] = b;
	_emission[3] = a;
}

void Material::setShininess(GLfloat shine){
	_shine = shine;
}

void Material::apply(){
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, _ambient);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, _diffuse);
	glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, _emission);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, _specular);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, _shine);
	glColor4fv(_diffuse);
}
