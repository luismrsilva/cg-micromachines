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

class GameManager {
	public:
		GameManager();
		~GameManager();
		void display();
		void reshape(GLsizei w, GLsizei h);
		void keyPressed();
		void onTimer(int val);
		void idle();
		void update();
		void init();
		void setKeyPressed(int glut_key, bool status);
	private:
		Car *_car;
		vector<GameObject*> _game_objects;
		bool *_isKeyPressed;
		
		enum KEYS{
			UP, LEFT, DOWN, RIGHT
		};

};

 #endif // __GAMEMANAGER_H
