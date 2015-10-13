#include <math.h>

#include <iostream>
using namespace std;
#include <GL/glut.h>
#include "GameManager.hpp"

#include "debug.hpp"
#include "game_config.hpp"

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
		sprintf(title, "%s (%d fps)", GAME_WINDOW_TITLE, frames);
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
	glutTimerFunc(GAME_TIMER_PERIOD, onTimer, GAME_TIMER_PERIOD);
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

	glutTimerFunc(GAME_TIMER_PERIOD, onTimer, GAME_TIMER_PERIOD);

	glutMainLoop();

	delete gameManager;
	return 0;
}
