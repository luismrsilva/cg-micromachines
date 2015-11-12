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
#include "PerspectiveCamera.hpp"
#include "Cheerio.hpp"
#include "Candle.hpp"
#include "Butter.hpp"
#include "Orange.hpp"
#include "Roadside.hpp"

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
		void orangeSpeedInc(float inc);
		void orangeRespawn();
		bool toggleLighting();
		void toggleCandles();
		void toggleShading();
	private:
		Car *_car;
		Roadside *_roadside;
		vector<Candle*> _candles;
		vector<Butter*> _butters;
		vector<Orange*> _oranges;
		vector<GameObject*> _game_objects;
		vector<Camera*> _cameras;
		bool *_isKeyPressed;

		enum KEYS{
			UP, LEFT, DOWN, RIGHT
		};
		Camera *_currentCamera;
		PerspectiveCamera *_movingCamera;

};

 #endif // __GAMEMANAGER_H
