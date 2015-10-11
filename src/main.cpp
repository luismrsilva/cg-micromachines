#include <math.h>

#include <iostream>
using namespace std;
#include <GL/glut.h>
#include "GameManager.hpp"

GameManager *gameManager;
bool isKeyPressed[] = {false, false, false, false};
float speed[] = {0.0f, 0.0f, 0.0f};	// should be direction vector, etc...

void myReshape(GLsizei w, GLsizei h){
	gameManager->reshape(w, h);
}

void myDisplay(void){
	gameManager->display();
}

void turnKeyPressed(int key, bool status){
	switch (key){
		case GLUT_KEY_UP:		isKeyPressed[0] = status; break;
		case GLUT_KEY_LEFT:		isKeyPressed[1] = status; break;
		case GLUT_KEY_DOWN:		isKeyPressed[2] = status; break;
		case GLUT_KEY_RIGHT:	isKeyPressed[3] = status; break;
	}
}

void myKeySpecial(int key, int x, int y){
	cout << "called keyspecial: +" << key << endl;
	turnKeyPressed(key , true);
	gameManager->display();
}

void myKeyUpSpecial(int key, int x, int y){
	cout << "called keyspecial: -" << key << endl;
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

void myDraw(int val){
	//glutTimerFunc(20, myDraw, 0);	// draws every 20ms

	if (isKeyPressed[0]) speed[1] += 0.1f;	// ↑  y++
	if (isKeyPressed[1]) speed[0] -= 0.1f;	// ←  x--
	if (isKeyPressed[2]) speed[1] -= 0.1f;	// ↓  y--
	if (isKeyPressed[3]) speed[0] += 0.1f;	// →  x--

	glutPostRedisplay();
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

	glutTimerFunc(20, myDraw, 0);

	glutMainLoop();

	delete gameManager;
	return 0;
}
