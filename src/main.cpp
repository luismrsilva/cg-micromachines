#include <GL/glut.h>
#include <math.h>

#include "GameManager.hpp"

GameManager *gameManager;

void myReshape(GLsizei w, GLsizei h){
	gameManager->reshape(w, h);
}

void myDisplay(void){
	gameManager->display();
}

int main(int argc, char *argv[]){
	
	glutInit(&argc, argv);

	gameManager = new GameManager();
	gameManager->init();

	glutDisplayFunc(myDisplay);
	glutReshapeFunc(myReshape);
	glutMainLoop();

	delete gameManager;
	return 0;
}
