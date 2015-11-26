/*
 * Texture.cpp
 *
 * */

#if defined(_WIN32)
	#define _CRT_SECURE_NO_WARNINGS
	#define GL_CLAMP_TO_BORDER 0x812D
#endif
#include "Texture.hpp"
#include <iostream>
#include <cmath>

using namespace std;
#include <GL/glut.h>
#include "debug.hpp"
#include "myunits.hpp"
#include "game_config.hpp"

#include "SOIL_wrapper.hpp"


Texture::Texture(char *path){


	/* Get an id for this texture*/
	// SOIL does it: glGenTextures(1, &_textureId);

	/* load an image file directly as a new OpenGL texture */
	_textureId = SOIL_load_OGL_texture(path,
			SOIL_LOAD_AUTO,
			SOIL_CREATE_NEW_ID,
			SOIL_FLAG_TEXTURE_REPEATS | SOIL_FLAG_MULTIPLY_ALPHA | SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_COMPRESS_TO_DXT
		);

	/* check for an error during the load process */
	if( 0 == _textureId ){
		D_TRACE();
		cout << "SOIL loading error: " << SOIL_last_result() << endl;
		return;
	}

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

}


Texture::~Texture(){
}

void Texture::apply(){
	#if defined(HEADER_SIMPLE_OPENGL_IMAGE_LIBRARY)
	glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
	glBindTexture(GL_TEXTURE_2D, _textureId);
	#endif
}
