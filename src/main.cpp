#include <GL/glut.h>
#include <math.h>

#include "GameManager.hpp"

GameManager *gameManager;
bool isKeyPressed[] = {false, false, false, false};

void myReshape(GLsizei w, GLsizei h){
	gameManager->reshape(w, h);
}

void myDisplay(void){
	gameManager->display();
}

void turnKeyPressed(int key, bool status){
	switch (key){
		case GLUT_KEY_UP:			isKeyPressed[0] = status; break;
		case GLUT_KEY_DOWN: 	isKeyPressed[1] = status; break;
		case GLUT_KEY_LEFT: 	isKeyPressed[2] = status; break;
		case GLUT_KEY_RIGHT: 	isKeyPressed[3] = status; break;
	}
}

void myKeySpecial(int key, int x, int y){
	std::cout << "called keyspecial: +" << key << std::endl;
	turnKeyPressed(key , true);
}

void myKeyUpSpecial(int key, int x, int y){
	std::cout << "called keyspecial: -" << key << std::endl;
	turnKeyPressed(key , false);
}

int main(int argc, char *argv[]){

	glutInit(&argc, argv);

	gameManager = new GameManager();
	gameManager->init();

	glutDisplayFunc(myDisplay);
	glutReshapeFunc(myReshape);

	glutSpecialFunc(myKeySpecial);
	glutSpecialUpFunc(myKeyUpSpecial);

	glutMainLoop();

	delete gameManager;
	return 0;
}
