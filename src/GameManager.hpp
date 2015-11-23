/*
 * GameManager.hpp
 *
 * */

#ifndef __GAMEMANAGER_H
#define __GAMEMANAGER_H

#include <GL/glut.h>

#include <vector>
using namespace std;

#include "Table.hpp"
#include "GameObject.hpp"
#include "Car.hpp"
#include "Camera.hpp"
#include "PerspectiveCamera.hpp"
#include "Cheerio.hpp"
#include "Candle.hpp"
#include "Butter.hpp"
#include "Orange.hpp"
#include "Roadside.hpp"
#include "SpotLightSource.hpp"

class GameManager {
	public:
		GameManager();
		~GameManager();
		void display();
		void reshape(GLsizei w, GLsizei h);
		void keyPressed(unsigned char key, int x, int y);
		void onTimer(int val);
		void init();
		void idle();
		void endGame();
		void resetGame();
		void update(double delta_t);
		void setKeyPressed(int glut_key, bool status);
		void orangeSpeedInc(float inc);
		void orangeRespawn();
		bool toggleLighting();
		void toggleCandles();
		void toggleShading();
	private:
		Car *_car;
		Table *_table;
		Roadside *_roadside;
		vector<Candle*> _candles;
		vector<Butter*> _butters;
		vector<Orange*> _oranges;
		vector<GameObject*> _game_objects;
		vector<Camera*> _cameras;
		bool *_isKeyPressed;
		bool _no_clip = false;
		bool _isPaused = false;
		int _lives = 5;

		enum KEYS{
			UP, LEFT, DOWN, RIGHT
		};
		Camera *_currentCamera;
		PerspectiveCamera *_movingCamera;
		SpotLightSource *_globalLight;
		bool _enableTeaPot;
		void checkCollisions();
};

 #endif // __GAMEMANAGER_H
