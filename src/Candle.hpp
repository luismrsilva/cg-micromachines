/*
 * Candle.hpp
 *
 * */

#ifndef __CANDLE_H
#define __CANDLE_H

#include "StaticObject.hpp"
#include "LightSource.hpp"
#include <GL/glut.h>

class Candle : public StaticObject {
	public:
		Candle();
		Candle(double x, double y, double z);
		~Candle();
		void update(double delta_t);
		void draw();
		void updateBox();
		//virtual bool processCollisionWith(GameObject &obj);
	private:
		LightSource *_lightsource;

};

#endif //__CANDLE_H
