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
		void toggleState();
		GLenum getNum();
		void setPosition(const Vector3 &pos);
		void setAmbient(GLfloat r, GLfloat g, GLfloat b, GLfloat a);
		void setDiffuse(GLfloat r, GLfloat g, GLfloat b, GLfloat a);
		void setSpecular(GLfloat r, GLfloat g, GLfloat b, GLfloat a);
		void setPosition(float x, float y, float z);
		virtual void draw();
	protected:
		GLenum _num;
		bool _state;
	private:
		float _position[4];
		GLfloat _ambient[4];
		GLfloat _diffuse[4];
		GLfloat _specular[4];

};

#endif //__LIGHTSOURCE_H
