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
#include "LightSource.hpp"

#include "Candle.hpp"
#include "Roadside.hpp"
#include "Butter.hpp"
#include "Orange.hpp"
#include "Car.hpp"
#include <GL/glut.h>
#include "debug.hpp"
#include "OrthogonalCamera.hpp"
#include "PerspectiveCamera.hpp"

#include <typeinfo>


void GameManager::orangeSpeedInc(float inc){
	for(vector<Orange*>::iterator i = _oranges.begin(); i != _oranges.end(); i++){
		(*i)->setSpeed((*i)->getSpeed() * inc);
	}
}

void GameManager::orangeRespawn(){
	for(vector<Orange*>::iterator i = _oranges.begin(); i != _oranges.end(); i++){
		if (!(*i)->isActive()) (*i)->resetPosition();
	}
}

GameManager::GameManager(){
	D_TRACE();

	/* Use (lightNum++) when creating a new light object */
	GLenum lightNum = GL_LIGHT0;

	/** Key State Array **/
	_isKeyPressed = (bool*) malloc(4 * sizeof(bool));
	memset(_isKeyPressed, false, 4);

	/** Game Objects **/
	_roadside = new Roadside();
	_game_objects.push_back(_roadside);

	_butters.push_back(new Butter(-1.1, 0.7, BUTTER_SIZE_Z/2.));
	_butters.push_back(new Butter(-1.3, 0.0, BUTTER_SIZE_Z/2.));
	_butters.push_back(new Butter(-1.1,-0.8, BUTTER_SIZE_Z/2.));
	_butters.push_back(new Butter(-0.4, 0.8, BUTTER_SIZE_Z/2.));
	_butters.push_back(new Butter( 0.7,-1.1, BUTTER_SIZE_Z/2.));

	_candles.push_back(new Candle(lightNum++, 1.0, -0.4, 0));
	_candles.push_back(new Candle(lightNum++, 1.0,  1.0, 0));
	_candles.push_back(new Candle(lightNum++,-0.8, -0.8, 0));
	_candles.push_back(new Candle(lightNum++,-0.8,  0.8, 0));
	_candles.push_back(new Candle(lightNum++, 0.0,  1.4, 0));
	_candles.push_back(new Candle(lightNum++,-0.2, -1.4, 0));

	/* Put candles inside _game_objects */
	for(vector<Candle*>::iterator i = _candles.begin(); i != _candles.end(); i++){
		_game_objects.push_back(*i);
	}

	/* Put butters inside _game_objects */
	for(vector<Butter*>::iterator i = _butters.begin(); i != _butters.end(); i++){
		_game_objects.push_back(*i);
	}

	/* Oranges */
	for (int i=0; i<3; i++){
		Orange *o = new Orange();
		_oranges.push_back(o);
		_game_objects.push_back(o);
	}

	_car = new Car();
	_car->reset();
	_game_objects.push_back(_car);


	/** Cameras **/

	/* Orthogonal Camera */
	_cameras.push_back(
		new OrthogonalCamera(
			-GAME_WORLD_MAX, GAME_WORLD_MAX,
			-GAME_WORLD_MAX, GAME_WORLD_MAX,
			-GAME_WORLD_MAX, GAME_WORLD_MAX
		)
	);

	/* Fixed perspective camera from table top */
	PerspectiveCamera *fixedPerspCam = new PerspectiveCamera(60, 1, 0.1, 10.);
	fixedPerspCam->setPosition(0, 0, 2.65);
	fixedPerspCam->setCenter(Vector3(0, 0.0, -1));
	fixedPerspCam->setUp(Vector3(0, 1.2, 0));
	_cameras.push_back(fixedPerspCam);

	/* Moving camera that follows the car */
	_movingCamera = new PerspectiveCamera(60, 1, 0.1, 10.);
	_cameras.push_back(_movingCamera);

	/* (not required) Fixed perspective from table side */
	PerspectiveCamera *fixedPerspCam2 = new PerspectiveCamera(60, 1, 0.1, 10.);
	fixedPerspCam2->setPosition(0, -4, 0);
	fixedPerspCam2->setCenter(Vector3(0, 1, 0));
	fixedPerspCam2->setUp(Vector3(0, 0, 1));
	_cameras.push_back(fixedPerspCam2);

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


	/* global lighting stuff */
	GLfloat ambient[4] = {0.01, 0.02, 0.1, 1.0};
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambient);
}

void GameManager::reshape(GLsizei w, GLsizei h){
	glViewport(0, 0, w, h);
	/* Cameras take care of aspect ratio too */
}

void drawSquareXY(GLfloat x, GLfloat y, GLfloat halfWidth) {
	glPushMatrix();
		glTranslatef(x, y, 0);
		glNormal3f(0.0, 0.0, 1.0);
		glVertex3f(x - halfWidth, y - halfWidth, 0);
		glVertex3f(x + halfWidth, y - halfWidth, 0);
		glVertex3f(x + halfWidth, y + halfWidth, 0);
		glVertex3f(x - halfWidth, y + halfWidth, 0);
	glPopMatrix();
}

void drawTable(GLfloat x, GLfloat y, GLfloat z){
	const float halfWidth = GAME_TABLE_LIMIT / GAME_TABLE_TILE_DIVISION_COUNT;
	const float width = 2 * halfWidth;
	const float start = - GAME_TABLE_LIMIT + halfWidth;
	glPushMatrix();
		GLfloat amb[] = {0.2, 0.8, 0.2, 1.0};
		GLfloat dif[] = {0.2, 0.8, 0.2, 1.0};
		GLfloat spec[] = {1.0, 1.0, 1.0, 1.0};
		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, amb);
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, dif);
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, spec);
		glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, 69.0);

		glColor3f(0.1f, 0.24f, 0.1f);
		glTranslatef(x, y, z + GAME_TABLE_LIMIT);
		//glutSolidCube(GAME_TABLE_LIMIT*2);
		/* draw table surface in -GAME_TABLE_LIMIT < x, y < GAME_TABLE_LIMIT */
		glBegin(GL_QUADS);
		//percorrer linhas
		for (float i = start; i < GAME_TABLE_LIMIT; i += width) {
			//percorrer colunas
			for (float j = start; j < GAME_TABLE_LIMIT; j += width) {
				drawSquareXY(i, j, halfWidth);
			}
		}
		glEnd();

	glPopMatrix();
}

void drawStartLine(GLfloat x, GLfloat y, GLfloat z){
	glPushMatrix();
		glColor3f(1.0f, 1.0f, 1.0f);
		glTranslatef(x, y, z);
		glScalef(0.2, 3.0, 0.02);
		glutSolidCube(0.1);
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

	drawTable(0, 0, -1.52f);
	drawStartLine(0.3, -0.2, 0);

	for(vector<GameObject*>::iterator i = _game_objects.begin(); i != _game_objects.end(); i++){
		(*i)->draw();
	}

	glFlush();
}

void GameManager::keyPressed(unsigned char key, int x, int y){
	switch(key){
		case 'r':
		case 'R':
			_car->reset();
			cout << "Car position resetted" << endl;
			break;
		case '1':
		case '2':
		case '3':
		case '4':
			_currentCamera = _cameras[key-'1'];
			cout << "Changed to camera " << (key) << endl;
			break;
		case 'l':
		case 'L':
			cout << "Global lighting toggled" << endl;
			toggleLighting();
			break;
		case 'c':
		case 'C':
			cout << "Candles lighting toggled" << endl;
			toggleCandles();
			break;
		case 'g':
		case 'G':
			cout << "Shading" << endl;
			toggleShading();
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
	Vector3 speed_v = _car->getSpeed();

	D_TRACE(<< "speed before: " << VECTOR3_STR(speed_v));

	double speed = _car->getSpeed().getXYModulus();

	/* update moving camera so it follows the car */
	if( _currentCamera == _movingCamera ){
		Vector3 pos = *(_car->getPosition());

		Vector3 new_pos =
				pos												// pos do carro
			+	Vector3(0, 0, 0.25 + speed*0.125)				// aumeta Z com a velocidade
			+	speed_v * (_car->isGoingForward()?-0.3:0.3)		// afasta-se com a velocidade
			-	Vector3(0.5, _car->getXYAngle()					// mantem distancia minima ao carro
			);

		/* smooth camera movement */
		new_pos =	new_pos * (1.-GAME_CAMERA_MOVEMENT_SMOTHENESS)
					+ _movingCamera->getPosition()
						->operator*(GAME_CAMERA_MOVEMENT_SMOTHENESS);

		_movingCamera->setPosition(new_pos);
		_movingCamera->setCenter(pos);		// olha para o carro
	}

	/* change car speed according to keys */

	if(_isKeyPressed[LEFT] ^ _isKeyPressed[RIGHT]){
		double da = delta_t*GAME_CAR_ANGLE_ACCELARATION(speed)*(_isKeyPressed[LEFT] ? 1 : -1);
		if(!_car->isGoingForward()) da *= -1.0;
		_car->setSpeed(_car->getSpeed().rotateZ(da));
		_car->rotateZ(da);
	}

	if(_isKeyPressed[UP] ^ _isKeyPressed[DOWN]){
		double da = delta_t*GAME_CAR_SPEED_ACCELARATION*(_isKeyPressed[UP] ? 1 : -0.5);
		if(_car->getSpeed().getXYModulus() == 0.){
			_car->setSpeed(Vector3(da, _car->getXYAngle()));
			_car->setGoingForward(da >= 0);
		}else{
			if(!_car->isGoingForward()) da *= -1.0;
			_car->setSpeed(_car->getSpeed().increaseMod(da));
		}
	}

	/* update all objects */
	for(vector<GameObject*>::iterator i = _game_objects.begin(); i != _game_objects.end(); i++){
		(*i)->update(delta_t);
		(*i)->updateBox();
	}


	/* check for collisions */
	for(vector<Orange*>::iterator i = _oranges.begin(); i != _oranges.end(); i++){
		if( (*i)->processCollisionWith(*_car) ){
			D_TRACE( << "COLISION!! " << typeid(*i).name() << " " << glutGet(GLUT_ELAPSED_TIME));
		};
	}
	for(vector<Butter*>::iterator i = _butters.begin(); i != _butters.end(); i++){
		if( (*i)->processCollisionWith(*_car) ){
			D_TRACE( << "COLISION!! " << typeid(*i).name() << " " << glutGet(GLUT_ELAPSED_TIME));
		};
	}
	if( _roadside->processCollisionWith(*_car) ){
		D_TRACE( << "COLISION!! " << typeid(_roadside).name() << " " << glutGet(GLUT_ELAPSED_TIME));
	}



}

bool GameManager::toggleLighting(){
	/* returns new state */
	if(glIsEnabled(GL_LIGHTING)){
		glDisable(GL_LIGHTING);
		return false;
	}else{
		glEnable(GL_LIGHTING);
	}
	return true;
}

void GameManager::toggleCandles(){
	for(vector<Candle*>::iterator i = _candles.begin(); i != _candles.end(); i++){
		(*i)->toggleLight();
	}
}

void GameManager::toggleShading() {
	GLint param;
	glGetIntegerv(GL_SHADE_MODEL, &param);
	if (param == GL_SMOOTH){
		glShadeModel(GL_FLAT);
	}
	else {
		glShadeModel(GL_SMOOTH);
	}
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
