#include <math.h>

#include <iostream>
using namespace std;
#include <GL/glut.h>
#include "GameManager.hpp"

#include "debug.hpp"

GameManager *gameManager;
bool isKeyPressed[] = {false, false, false, false};
float speed[] = {0.0f, 0.0f, 0.0f};	// should be direction vector, etc...

enum KEYS{
	UP, LEFT, DOWN, RIGHT
};

void myReshape(GLsizei w, GLsizei h){
	gameManager->reshape(w, h);
}

void myDisplay(void){
	gameManager->display();
}

void turnKeyPressed(int key, bool status){
	switch (key){
		case GLUT_KEY_UP:		isKeyPressed[UP] = status; break;
		case GLUT_KEY_LEFT:		isKeyPressed[LEFT] = status; break;
		case GLUT_KEY_DOWN:		isKeyPressed[DOWN] = status; break;
		case GLUT_KEY_RIGHT:	isKeyPressed[RIGHT] = status; break;
	}
}

void myKeySpecial(int key, int x, int y){
	D_TRACE();
	turnKeyPressed(key , true);
	gameManager->display();
}

void myKeyUpSpecial(int key, int x, int y){
	D_TRACE();
	turnKeyPressed(key , false);
}

void myKeyboardFunc(unsigned char key, int x, int y){
	cout << "key " << key << endl;
	static GLenum mode = GL_FILL;
	switch(key){
		case 'a':
			mode = (mode == GL_FILL) ? GL_LINE : GL_FILL;
			glPolygonMode(GL_FRONT_AND_BACK, mode);
			glutPostRedisplay();
			break;
		case 'd':
			glutPostRedisplay();
			break;
		case 'x':
			exit(0);
			break;
		default:
			break;
	}
}

void onTimer(int val){
	//glutTimerFunc(20, myDraw, 0);	// draws every 20ms

	if (isKeyPressed[UP]) speed[1] += 0.1f;	// ↑  y++
	if (isKeyPressed[LEFT]) speed[0] -= 0.1f;	// ←  x--
	if (isKeyPressed[DOWN]) speed[1] -= 0.1f;	// ↓  y--
	if (isKeyPressed[RIGHT]) speed[0] += 0.1f;	// →  x--

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

	glutTimerFunc(20, onTimer, 20);

	glutMainLoop();

	delete gameManager;
	return 0;
}
