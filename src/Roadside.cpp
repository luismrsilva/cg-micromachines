/*
 * Roadside.cpp
 * 
 * */

#include "Roadside.hpp"
#include "Vector3.hpp"
#include <math.h>
#include <GL/glut.h>

#include <iostream>
using namespace std;

Roadside::Roadside(){

}

Roadside::~Roadside(){

}

/* Draws a torus on x, y, z position */
static void drawTorus(GLfloat x, GLfloat y, GLfloat z){
	glPushMatrix();

	glTranslatef(x, y, z);
	glColor3f(0.0f, 1.0f, 0.0f);
	glutSolidTorus(0.005f, 0.015f, 6, 16);
	
	glPopMatrix();
}

void Roadside::draw(){
	cout << "Roadside::draw()" << endl;
	
	Vector3 *pos = this->getPosition();
	
	glPushMatrix();
	
	glTranslatef(pos->getX(), pos->getY(), pos->getZ());
	
	// 1
	for (float y = 50.0; y < 90.0f; y += 1.0f) {
		float x = -95.0f;
		drawTorus(x, y, 0);
		drawTorus(x + 5.0f, y, 0);
	}

	// 2, 3
	for (float x = -95.0; x < 50.0f; x += 1.0f) {
		float y = 90.0f;
		drawTorus(x, y, 0);
		drawTorus(x, y + 5.0f, 0);
	}

	// 4 circunf quarto
	for (float x = 50.0; x < 95.0f; x += 1.0f) {
		float y = 90.0f;
		drawTorus(x, y, 0);
		drawTorus(x, y + 5.0f, 0);
	}

	// 5, 6
	for (float y = 50.0; y < -50.0f; y -= 1.0f) {
		float x = -90.0f;
		drawTorus(x, y, 0);
		drawTorus(x + 5.0f, y, 0);
	}

	// 7 circunf meia

	// 8, 9 
	for (float y = -50.0; y < 50.0f; y += 1.0f) {
		float x = 50.0f;
		drawTorus(x, y, 0);
		drawTorus(x + 5.0f, y, 0);
	}

	
	glPopMatrix();
}
