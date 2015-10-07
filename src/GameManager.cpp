/*
 * GameManager.cpp
 *
 * */

#include "GameManager.hpp"
#include "Camera.hpp"
#include "GameObject.hpp"
//#include "LightSource.hpp"

#include <GL/glut.h>

GameManager::GameManager(){

}

GameManager::~GameManager(){

}

void GameManager::init(){
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(700, 700);
	glutInitWindowPosition(-1, -1);
	glutCreateWindow("tg010/cg-micromachines");
}

void GameManager::reshape(GLsizei w, GLsizei h){
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	
	if(w<h){
		glOrtho(	-2.0f,	2.0f,
					-2.0f*h/w,	2.0f*h/w,
					-2.0f,	2.0f);
	}else{		
		glOrtho(	-2.0f*w/h,	2.0f*w/h,
					-2.0f,	2.0f,
					-2.0f,	2.0f);
	}
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void drawCube(GLfloat x, GLfloat y, GLfloat z){
	glPushMatrix();
	
	glTranslatef(x, y, z);
	glColor3f(1.0f, 1.0f, 1.0f);
	glutSolidCube(3.0f);
	
	glPopMatrix();
}

void GameManager::display(){
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0f, 1.0f, 1.0f);
	
	
	drawCube(0, 0, 0);
	
	//TODO: draw objects
	
	glFlush();
}

void GameManager::keyPressed(){

}

void GameManager::onTimer(){

}

void GameManager::idle(){

}

void GameManager::update(){

}
