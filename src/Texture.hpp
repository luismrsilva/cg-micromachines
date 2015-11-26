/*
 * Texture.hpp
 *
 * */

#ifndef __TEXTURE_H
#define __TEXTURE_H

#include <GL/glut.h>

class Texture{
	public:
		Texture(char *path);
		~Texture();
		void apply();
	private:
		GLuint _textureId;

};

#endif //__TEXTURE_H
