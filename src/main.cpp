#include <math.h>
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include <GL/glut.h>
#include "GameManager.hpp"

#include "debug.hpp"
#include "game_config.hpp"

#define _USE_MATH_DEFINES
#include <cmath>
#include <time.h>

GameManager *gameManager;

void myReshape(GLsizei w, GLsizei h){
	gameManager->reshape(w, h);
}

char title[128];

void myDisplay(void){
	static int frames = 0;
	static int start = glutGet(GLUT_ELAPSED_TIME);
	gameManager->display();
	frames++;

	if(glutGet(GLUT_ELAPSED_TIME) - start > 1000){
		start = glutGet(GLUT_ELAPSED_TIME);
		#ifdef _MSC_VER
			sprintf_s
		#else
			sprintf
		#endif
		(title, "%s (%d fps)", GAME_WINDOW_TITLE, frames);

		glutSetWindowTitle(title);
		frames = 0;
	}
}

void myKeySpecial(int key, int x, int y){
	D_TRACE();
	gameManager->setKeyPressed(key, true);
}

void myKeyUpSpecial(int key, int x, int y){
	D_TRACE();
	gameManager->setKeyPressed(key, false);
}

void myKeyboardFunc(unsigned char key, int x, int y){
	D_PRINT("key: " << key);
	static GLenum mode = GL_FILL;
	switch(key){
		case 'a':
		case 'A':
			mode = (mode == GL_FILL) ? GL_LINE : GL_FILL;
			glPolygonMode(GL_FRONT_AND_BACK, mode);
			glutPostRedisplay();
			break;
		case 'd':
		case 'D':
			glutPostRedisplay();
			break;
		case 'x':
		case 'X':
			exit(0);
			break;
		default:
			gameManager->keyPressed(key, x, y);
			break;
	}
}


void onTimer(int val){
	static int prev = glutGet(GLUT_ELAPSED_TIME);
	int now = glutGet(GLUT_ELAPSED_TIME);
	glutTimerFunc(GAME_TIMER_PERIOD, onTimer, GAME_TIMER_PERIOD);
	gameManager->onTimer(now-prev); // use elapsed delta time
	prev = now;
}


void orangeSpeedIncrease(int val){
	float increment = 1 + ((5+(rand()%5))/100.0);	// 5% to 10%
	gameManager->orangeSpeedInc(increment);
	glutTimerFunc(10+(rand()%10)*1000, orangeSpeedIncrease, 0);
}

void orangeRespawn(int val){
	gameManager->orangeRespawn();
	glutTimerFunc(4+(rand()%6)*1000, orangeRespawn, 0);
}

int main(int argc, char *argv[]){
	srand(time(NULL));
	glutInit(&argc, argv);

	gameManager = new GameManager();
	gameManager->init();

	glutDisplayFunc(myDisplay);
	glutReshapeFunc(myReshape);

	glutKeyboardFunc(myKeyboardFunc);
	glutSpecialFunc(myKeySpecial);
	glutSpecialUpFunc(myKeyUpSpecial);

	glutTimerFunc(GAME_TIMER_PERIOD, onTimer, GAME_TIMER_PERIOD);
	glutTimerFunc(10+(rand()%10)*1000, orangeSpeedIncrease, 0);
	glutTimerFunc(4+(rand()%6)*1000, orangeRespawn, 0);

	glutMainLoop();

	delete gameManager;
	return 0;
}
