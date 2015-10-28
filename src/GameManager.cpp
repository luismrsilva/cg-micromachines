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
#include "OrthogonalCamera.hpp"
#include "PerspectiveCamera.hpp"


GameManager::GameManager(){
	D_TRACE();

	_isKeyPressed = (bool*) malloc(4 * sizeof(bool));
	memset(_isKeyPressed, false, 4);

	_game_objects.push_back(new Roadside());

	_game_objects.push_back(new Butter(-1.1, 0.7, 0));
	_game_objects.push_back(new Butter(-1.3, 0.0, 0));
	_game_objects.push_back(new Butter(-1.1,-0.8, 0));
	_game_objects.push_back(new Butter(-0.4, 0.4, 0));
	_game_objects.push_back(new Butter( 0.7,-1.1, 0));

	for (int i=0; i<3; i++)
		_game_objects.push_back(new Orange());

	_car = new Car();
	_car->setPosition(0.1, -0.2, 0.0);
	_game_objects.push_back(_car);

	_cameras.push_back(
		new OrthogonalCamera(
			-GAME_WORLD_MAX, GAME_WORLD_MAX,
			-GAME_WORLD_MAX, GAME_WORLD_MAX,
			-GAME_WORLD_MAX, GAME_WORLD_MAX
		)
	);

	PerspectiveCamera *fixedPerspCam = new PerspectiveCamera(60, 3./4., 0.1, 10.);
	fixedPerspCam->setPosition(0, -2.5, 2.5);
	fixedPerspCam->setCenter(Vector3(0, 0.5, -1));

	_cameras.push_back(fixedPerspCam);

	_currentCamera = _cameras[0];

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
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(700, 700);
	glutInitWindowPosition(-1, -1);
	glutCreateWindow(GAME_WINDOW_TITLE);
}

void GameManager::reshape(GLsizei w, GLsizei h){
	glViewport(0, 0, w, h);
	/* Cameras take care of aspect ratio too */
}

void drawTable(GLfloat x, GLfloat y, GLfloat z){
	glPushMatrix();
		glTranslatef(x, y, z);
		glColor3f(0.1f, 0.3f, 0.1f);
		glutSolidCube(TABLE_LIMIT*2);
	glPopMatrix();
}

void GameManager::display(){
	D_TRACE();


	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	_currentCamera->update();


	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glClearDepth(1.0f);
	glDepthFunc(GL_LEQUAL);
	glEnable(GL_DEPTH_TEST);

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glColor3f(1.0f, 1.0f, 1.0f);

	drawTable(0, 0, -1.6f);

	for(vector<GameObject*>::iterator i = _game_objects.begin(); i != _game_objects.end(); i++){
		(*i)->draw();
	}

	glFlush();
}

void GameManager::keyPressed(unsigned char key, int x, int y){
	switch(key){
		case 'r':
		case 'R':
			_car->setPosition(0.1, -0.2, 0.0);
			_car->setSpeed(Vector3(0,0,0));
			_car->setXYAngle(0.0);
			break;
		case '1':
			_currentCamera = _cameras[0];
			break;
		case '2':
			_currentCamera = _cameras[1];
			break;
		case '3':
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
		double da = delta_t*GAME_CAR_ANGLE_ACCELARATION(speed)*(_isKeyPressed[LEFT] ? 1 : -1);
		if(!_car->isGoingForward())
			da *= -1.0;
		_car->setSpeed(_car->getSpeed().rotateZ(da));
		_car->rotateZ(da);
	}
	if(_isKeyPressed[UP] ^ _isKeyPressed[DOWN]){
		double da = delta_t*GAME_CAR_SPEED_ACCELARATION*(_isKeyPressed[UP] ? 1 : -0.5);
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

	for(vector<GameObject*>::iterator i = _game_objects.begin(); i != _game_objects.end(); i++){
		(*i)->update(delta_t);
	}

	_car->update(delta_t);	// doing this twice

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
