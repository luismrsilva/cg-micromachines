/*
 * Candle.hpp
 *
 * */

#ifndef __CANDLE_H
#define __CANDLE_H

#include "StaticObject.hpp"
#include "PointLightSource.hpp"
#include <GL/glut.h>

class Candle : public StaticObject {
	public:
		Candle(GLenum lightNum, double x, double y, double z);
		~Candle();
		void draw();
		void toggleLight();
		void setLightColor(GLfloat r, GLfloat g, GLfloat b);
	private:
		PointLightSource *_lightsource;

};

#endif //__CANDLE_H
