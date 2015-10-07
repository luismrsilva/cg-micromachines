/*
 * GameManager.cpp
 *
 * */

#include "GameManager.hpp"
#include "Camera.hpp"
#include "GameObject.hpp"
//#include "LightSource.hpp"

#include "Roadside.hpp"
#include "Butter.hpp"
#include <GL/glut.h>

#include <iostream>
using namespace std;

#define	WORLD_MAX	2.0f

GameManager::GameManager(){
	
	_game_objects.push_back(new Roadside());
	_game_objects.push_back(new Butter());
	
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
	
	/* pos, look at, up_v*/
	gluLookAt(	0, 0, 0,  // position of the eye point
				0, 0, 1,  // center - position of the reference point
				0, 1, 0); // up - specifies the direction of the up point
	
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
	cout << "GameManager::display()" << endl;
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0f, 1.0f, 1.0f);
	
	
	drawCube(0, 0, 0);
	
	for(vector<GameObject*>::iterator i = _game_objects.begin();
		i != _game_objects.end(); i++){
		(*i)->draw();
	}
	
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
