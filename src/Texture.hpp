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
	protected:
		void loadData(int width, int height, int nChannels, unsigned char *data);
		void loadRawFile(char *path, int width, int height, int nChannels);
		void loadPngFile(char *path);
	private:
		GLuint _textureId;

};

#endif //__TEXTURE_H
