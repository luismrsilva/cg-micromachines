/*
 * LightSource.hpp
 *
 * */

#ifndef __LIGHTSOURCE_H
#define __LIGHTSOURCE_H

#include <stdlib.h>
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
		void setCutOff(float cut_off);
		void setExponent(float exp);
		void setAmbient(float r, float g, float b, float a);
		void setDiffuse(float r, float g, float b, float a);
		void setSpecular(float r, float g, float b, float a);
		void setPosition(float x, float y, float z);
		void setDirection(float x, float y, float z);
		void draw();
	private:
		float _position[4];
		float _direction[4];
		float _ambient[4];
		float _diffuse[4];
		float _specular[4];
		float _cut_off;
		float _exponent;
		GLenum _num;
		bool _state;
};

#endif //__LIGHTSOURCE_H
