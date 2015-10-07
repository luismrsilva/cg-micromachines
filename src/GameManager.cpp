/*
 * GameManager.cpp
 *
 * */

#include "GameManager.hpp"
#include "Camera.hpp"
#include "GameObject.hpp"
//#include "LightSource.hpp"

#include <GL/glut.h>

#define	WORLD_MAX	100.0f

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
		glOrtho(	-WORLD_MAX,	WORLD_MAX,
					-WORLD_MAX*h/w,	WORLD_MAX*h/w,
					-WORLD_MAX,	WORLD_MAX);
	}else{		
		glOrtho(	-WORLD_MAX*w/h,	WORLD_MAX*w/h,
					-WORLD_MAX,	WORLD_MAX,
					-WORLD_MAX,	WORLD_MAX);
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
