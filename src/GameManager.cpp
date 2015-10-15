/*
 * GameManager.cpp
 *
 * */

#include "game_config.hpp"


#define _USE_MATH_DEFINES
#include <cmath>

#include <iostream>
using namespace std;
#include <string.h>
#include "GameManager.hpp"
#include "Camera.hpp"
#include "GameObject.hpp"
//#include "LightSource.hpp"

#include "Roadside.hpp"
#include "Butter.hpp"
#include "Orange.hpp"
#include "Car.hpp"
#include <GL/glut.h>
#include "debug.hpp"



GameManager::GameManager(){
	D_TRACE();

	_isKeyPressed = (bool*) malloc(4 * sizeof(bool));
	memset(_isKeyPressed, false, 4);

	_game_objects.push_back(new Roadside());

	_car = new Car();
	_game_objects.push_back(_car);

	_game_objects.push_back(new Butter(-1.1, 0.7, 0));
	_game_objects.push_back(new Butter(-1.3, 0.0, 0));
	_game_objects.push_back(new Butter(-1.1,-0.8, 0));
	_game_objects.push_back(new Butter(-0.4, 0.4, 0));
	_game_objects.push_back(new Butter( 0.7,-1.1, 0));
	_game_objects.push_back(new Orange(-1.3, 0.8, 0));
	_game_objects.push_back(new Orange( 0.0, 1.1, 0));
	_game_objects.push_back(new Orange( 1.3,-0.8, 0));

}

GameManager::~GameManager(){
	D_TRACE();
	free(_isKeyPressed);

	for(vector<GameObject*>::iterator i = _game_objects.begin();
		i != _game_objects.end(); i++){
		delete (*i);
	}
}

void GameManager::init(){
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(700, 700);
	glutInitWindowPosition(-1, -1);
	glutCreateWindow(GAME_WINDOW_TITLE);
}

void GameManager::reshape(GLsizei w, GLsizei h){
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	if(w<h){
		glOrtho(	-GAME_WORLD_MAX,	GAME_WORLD_MAX,
					-GAME_WORLD_MAX*h/w,	GAME_WORLD_MAX*h/w,
					-GAME_WORLD_MAX,	GAME_WORLD_MAX);
	}else{
		glOrtho(	-GAME_WORLD_MAX*w/h,	GAME_WORLD_MAX*w/h,
					-GAME_WORLD_MAX,	GAME_WORLD_MAX,
					-GAME_WORLD_MAX,	GAME_WORLD_MAX);
	}

	/* pos, look at, up_v*/
	gluLookAt(	0, 0, 0,  // position of the eye point
				0, 0, -1,  // center - position of the reference point
				0, 1, 0); // up - specifies the direction of the up point

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void drawCube(GLfloat x, GLfloat y, GLfloat z){
	glPushMatrix();

	glTranslatef(x, y, z);
	glColor3f(0.1f, 0.3f, 0.1f);
	glutSolidCube(3.0f);

	glPopMatrix();
}

void GameManager::display(){
	D_TRACE();
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

void GameManager::keyPressed(unsigned char key, int x, int y){
	switch(key){
		case 'r':
		case 'R':
			_car->setPosition(0,0,0);
			_car->setSpeed(Vector3(0,0,0));
			_car->setXYAngle(0.0);
			break;
		default:
			break;
	}
}

void GameManager::onTimer(int val){
	update(((double) val)/1000.);
	glutPostRedisplay();
}

void GameManager::idle(){

}

void GameManager::update(double delta_t){
	D_TRACE(<< "speed before");
	_car->getSpeed().println();

	double speed = _car->getSpeed().getXYModulus();

	if(_isKeyPressed[LEFT] ^ _isKeyPressed[RIGHT]){
		double da = delta_t*(_isKeyPressed[LEFT]
						? GAME_CAR_ANGLE_ACCELARATION(speed)
						: -GAME_CAR_ANGLE_ACCELARATION(speed));
		if(!_car->isGoingForward())
			da *= -1.0;
		_car->setSpeed(_car->getSpeed().rotateZ(da));
		_car->rotateZ(da);
	}
	if(_isKeyPressed[UP] ^ _isKeyPressed[DOWN]){
		double da = delta_t*(_isKeyPressed[UP]
						? GAME_CAR_SPEED_ACCELARATION
						: -0.5*GAME_CAR_SPEED_ACCELARATION);
		if(_car->getSpeed().getXYModulus() == 0.){
			_car->setSpeed(Vector3(da, _car->getXYAngle()));
			_car->setGoingForward(da >= 0);
		}else{
			if(!_car->isGoingForward())
				da *= -1.0;
			_car->setSpeed(_car->getSpeed().increaseMod(da));
		}

		cout << "da: " << (da/((double)delta_t)) << endl;
	}


	double da = -GAME_CAR_SPEED_DRAG(speed) * delta_t;
	cout << "speed: " << speed << endl;
	cout << "drag: " << (double)da/((double)delta_t) << endl;

	_car->setSpeed(_car->getSpeed().increaseMod(da));


	_car->update(delta_t);
}

void GameManager::setKeyPressed(int glut_key, bool status){
	switch (glut_key){
		case GLUT_KEY_UP:		_isKeyPressed[UP] = status; break;
		case GLUT_KEY_LEFT:		_isKeyPressed[LEFT] = status; break;
		case GLUT_KEY_DOWN:		_isKeyPressed[DOWN] = status; break;
		case GLUT_KEY_RIGHT:	_isKeyPressed[RIGHT] = status; break;
		default: break;
	}
}
