/*
 * Texture.hpp
 *
 * */

#ifndef __TEXTURE_H
#define __TEXTURE_H

#include <GL/glut.h>
#include "Vector3.hpp"

class Texture{
	public:
		Texture(char *path, int width, int height);
		~Texture();
		void apply();
	private:
		GLuint _texture;
};

#endif //__TEXTURE_H
