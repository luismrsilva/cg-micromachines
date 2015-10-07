#include <GL/glut.h>

//RESHAPE CALLBACK FUNCTION
void myReshape(GLsizei w, GLsizei h) {
	glViewport(0, 0, w, h); //definicao do viewport (x,y,w = horiz,h = vert)
	glMatrixMode(GL_PROJECTION); // definir projecao
	glLoadIdentity();   //faz load da matriz identidade
	glOrtho(-2.0f, 2.0f, -2.0f, 2.0f, -2.0f, 2.0f); // (left, right, bottom, top, near, far)
	glMatrixMode(GL_MODELVIEW); // inicializa a matriz de model-projec; especifica que a matriz eh atual
	glLoadIdentity(); //substitui o conteudo da matriz no topo da pilha atual pela identidade

}

//DISPLAY CALLBACK FUNCTION
void myDisplay(void) {
	// 1 - Limpa os buffers
	//glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	//glClearDepth(0.0f, 0.0f, 0.0f, 0.0f); // ArgS'??
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// 2 - Descreve pontos, Linhas e polígonos
	//retangulo 1
	glBegin(GL_POLYGON); // marca inicio de uma lista de vertices
	glColor3f(0.6f, 1.0f, 0.8f);
	glVertex3f(-1.5f, -1.5f, 0.0f);
	glVertex3f(1.5f, -1.5f, 0.0f);
	glVertex3f(1.5f, 1.5f, 0.0f);
	glVertex3f(-1.5f, 1.5f, 0.0f);
	glEnd(); // marca fim de lista de vertices


			 // 3 - Forcar o processamento do desenho
	glFlush(); //forca comandos a serem executados; invocada apos desenho estar terminado

}

void main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_SINGLE); //eh RGBA e SINGLE BUFFER
	glutInitWindowSize(2000, 2000); //dimensao da janela (largura X altura)
	glutInitWindowPosition(-1, -1); //posicao da janela no dispositivo CSE
	glutCreateWindow("Cars"); //cria uma janela; retorna um identificador único da janela
	glutDisplayFunc(myDisplay);// tipo void glutDisplayFunc(void(*func)(void));  eh callback
							   //-> define a func a ser chamada quando o conteudo da janela necessida de ser redesenhado. 
							   //Coloca-se o que se quer desenhar;
	glutReshapeFunc(myReshape);//tipo glutReshapeFunc(void(*func) (int, int)); eh callback
							   //-> define a funcao a ser chamada quando a janela eh movida ou redimensionada;
							   // deve-se definir aqui as coordenadas do viewport;
	glutMainLoop(); // corre o ciclo principal; depois de chamada entra em ciclo e nao sai; invoca func de callback qdo precisa;
}