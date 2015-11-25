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
		Texture(char *path, int width, int height, int channels);
		~Texture();
		void apply();
	private:
		GLuint _textureId;
};

#endif //__TEXTURE_H
