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
	private:
		vector<GameObject*> _game_objects;
};

 #endif // __GAMEMANAGER_H
