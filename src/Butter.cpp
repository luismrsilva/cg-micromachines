/*
 * Butter.cpp
 *
 * */

#include "Butter.hpp"
#include <iostream>
#include "Vector3.hpp"
#include <math.h>

#include "myunits.hpp"
using namespace std;
#include <GL/glut.h>

Butter::Butter(){

}

Butter::Butter(double x, double y, double z) : Obstacle(x, y, z){

}

Butter::~Butter(){

}

/* Draws a cube of butter on x, y, z position */
void Butter::draw(){
	//cout << "Butter::draw()" << endl;
	Vector3 *pos = this->getPosition();

	glPushMatrix();
		glTranslatef(pos->getX(), pos->getY(), pos->getZ());
		glScalef(1, 0.5, 1);
		glColor3f(0.8f, 0.8f, 0.5f);
		glutSolidCube(cm(10));
	glPopMatrix();

}
