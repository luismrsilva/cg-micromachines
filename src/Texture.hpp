/*
 * Texture.hpp
 *
 * */

#ifndef __TEXTURE_H
#define __TEXTURE_H

#include <GL/glut.h>
#include "Vector3.hpp"

class Texture {
	public:
		Texture();
		Texture(GLfloat r, GLfloat g, GLfloat b);
		~Texture();
		void setTexture(GLfloat r, GLfloat g, GLfloat b);
		void setTexture(GLfloat r, GLfloat g, GLfloat b, GLfloat a);
		void draw();
	private:
};

#endif //__TEXTURE_H
