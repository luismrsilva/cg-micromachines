/*
 * GameManager.hpp
 *
 * */

#ifndef __GAMEMANAGER_H
#define __GAMEMANAGER_H

#include <GL/glut.h>

#include <vector>
using namespace std;

#include "GameObject.hpp"
#include "Car.hpp"
#include "Camera.hpp"

class GameManager {
	public:
		GameManager();
		~GameManager();
		void display();
		void reshape(GLsizei w, GLsizei h);
		void keyPressed(unsigned char key, int x, int y);
		void onTimer(int val);
		void idle();
		void update(double delta_t);
		void init();
		void setKeyPressed(int glut_key, bool status);
		GLsizei getViewWidth();
		GLsizei getViewHeight();
	private:
		Car *_car;
		vector<GameObject*> _game_objects;
		vector<Camera*> _cameras;
		bool *_isKeyPressed;

		enum KEYS{
			UP, LEFT, DOWN, RIGHT
		};
		GLsizei _viewWidth;
		GLsizei _viewHeight;
		Camera *_currentCamera;

};

 #endif // __GAMEMANAGER_H
