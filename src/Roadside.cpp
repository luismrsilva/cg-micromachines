/*
 * Roadside.cpp
 * 
 * */

#include "Roadside.hpp"
#include "Vector3.hpp"
#include <math.h>
#include <GL/glut.h>

Roadside::Roadside(){

}

Roadside::~Roadside(){

}

/* Draws a torus on x, y, z position */
static void drawTorus(GLfloat x, GLfloat y, GLfloat z){
	glPushMatrix();

	glTranslatef(x, y, z);
	glColor3f(1.0f, 1.0f, 0.0f);
	glutSolidTorus(0.01f, 0.02f, 6, 16);
	
	glPopMatrix();
}

static void drawTorusLineXY(double sX, double sY, double eX, double eY){
	double m = (eY-sY)/((eX-sX));
	double b = sY - m*sX;
	
	for(double x = sX; x <= eX; x+=0.2f){
		drawTorus(x, m*x+b, 0);
	}
}

void Roadside::draw(){
	Vector3 *pos = this->getPosition();
	
	glPushMatrix();
	
	glTranslatef(pos->getX(), pos->getY(), pos->getZ());
	
	
	
	drawTorusLineXY(0.0, 0.0, 1.0, 3.0);
	
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

	//10 curva quarto

	//11 reta
	for (float x = -95.0; x < 50.0f; x += 1.0f) {
		float y = 53.4f;
		drawTorus(x, y, 0);
		drawTorus(x, y + 5.0f, 0);
	}

	//12 curva meia

	//13 reta

	//14 curva meia
	
	//15 reta

	//16 curva meia

	//17 reta

	//18 curva meia
	
	//19 reta

	
	glPopMatrix();
}
