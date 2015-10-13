#include <math.h>

#include <iostream>
using namespace std;
#include <GL/glut.h>
#include "GameManager.hpp"

#include "debug.hpp"

GameManager *gameManager;

void myReshape(GLsizei w, GLsizei h){
	gameManager->reshape(w, h);
}

void myDisplay(void){
	gameManager->display();
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

#define TIMER_PERIOD 20

void onTimer(int val){
	glutTimerFunc(TIMER_PERIOD, onTimer, TIMER_PERIOD);
	gameManager->onTimer(val);
}

int main(int argc, char *argv[]){

	glutInit(&argc, argv);

	gameManager = new GameManager();
	gameManager->init();

	glutDisplayFunc(myDisplay);
	glutReshapeFunc(myReshape);

	glutKeyboardFunc(myKeyboardFunc);
	glutSpecialFunc(myKeySpecial);
	glutSpecialUpFunc(myKeyUpSpecial);

	glutTimerFunc(TIMER_PERIOD, onTimer, TIMER_PERIOD);

	glutMainLoop();

	delete gameManager;
	return 0;
}
