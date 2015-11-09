/*
 * LightSource.hpp
 *
 * */

#ifndef __LIGHTSOURCE_H
#define __LIGHTSOURCE_H

#include <GL/glut.h>
#include "Vector3.hpp"

class LightSource {
	public:
		LightSource(GLenum num);
		~LightSource();
		bool getState();
		void setState(bool state);
		GLenum getNum();
		void setPosition(const Vector3 &pos);
		void setDirection(const Vector3 &dir);
		void setCutOff(double cut_off);
		void setExponent(double exp);
		void setAmbient(double r, double g, double b, double a);
		void setDiffuse(double r, double g, double b, double a);
		void setSpecular(double r, double g, double b, double a);
		void draw();
	private:
		Vector3 *_position;
		Vector3 *_direction;
		double _ambient[4];
		double _diffuse[4];
		double _specular[4];
		double _cut_off;
		double _exponent;
		GLenum _num;
		bool _state;
};

#endif //__LIGHTSOURCE_H
