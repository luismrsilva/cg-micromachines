#include <GL/glut.h>
#include <math.h>

void myReshape(GLsizei w, GLsizei h){
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	
	/*
	glOrtho(	-2.0f,	2.0f,
				-2.0f,	2.0f,
				-2.0f,	2.0f);*/
	if(w<h){
		glOrtho(	-2.0f,	2.0f,
					-2.0f*h/w,	2.0f*h/w,
					-2.0f,	2.0f);
	}else{		
		glOrtho(	-2.0f*w/h,	2.0f*w/h,
					-2.0f,	2.0f,
					-2.0f,	2.0f);
	}
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void drawCube(GLfloat x, GLfloat y, GLfloat z){
	glPushMatrix();
	
	glTranslatef(x, y, z);
	glColor3f(1.0f, 1.0f, 1.0f);
	glutSolidCube(3.0f);
	
	glPopMatrix();
}

void drawTorus(GLfloat x, GLfloat y, GLfloat z){
	glPushMatrix();
	
	glTranslatef(x, y, z);
	glColor3f(1.0f, 1.0f, 0.0f);
	glutSolidTorus(0.011f, 0.03f, 6, 16);
	
	glPopMatrix();
}

void myDisplay(void){
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0f, 1.0f, 1.0f);
	
	
	drawCube(0, 0, 0);
	
	for(float x = -1.2; x < 0.6f; x+=0.1f){
		float y = log(x + 1.5f);
		drawTorus(x, y, 0);
		drawTorus(x+0.8f, y, 0);
	}
	
	glFlush();
}

int main(int argc, char *argv[]){
	
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(400, 400);
	glutInitWindowPosition(-1, -1);
	glutCreateWindow("Test");
	glutDisplayFunc(myDisplay);
	glutReshapeFunc(myReshape);
	glutMainLoop();
	return 0;
}
