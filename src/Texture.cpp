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
//#include "lib/SOIL.h"

#include "debug.hpp"
#include "myunits.hpp"
#include "game_config.hpp"


Texture::Texture(char *path, int width, int height, int channels){
	/* Get an id for this texture*/
	glGenTextures(1, &_textureId);

	if(channels != 3 && channels != 4){
		cout	<< "WARNING: texture file \"" << path
				<< "\" unsupported channel count: " << channels
				<< ".\n" << endl;
		return;
	}

	/** Load texture from file **/
	unsigned char *data;
	int nBytes, nImgBytes;
	nImgBytes = width*height*channels;
	data = new unsigned char[ nImgBytes ];

	FILE *f = fopen(path, "rb");
	if(!f){
		cout	<< "WARNING: failed to open texture file \""
				<< path << "\".\n" << endl;
		return;
	}

	/* Read image pixels */
	/* Loads raw RGB(A) pixel data.
	 * Expects image to be vertically flipped. */
	nBytes = fread(data, 1, nImgBytes, f);
	if(nBytes != nImgBytes){
		cout	<< "WARNING: texture file \"" << path << "\" expected "
				<< nImgBytes << "bytes but only got " << nBytes
				<< ".\n" << endl;
		fclose(f);
		return;
	}

	cout << "INFO: texture file \"" << path << "\": loaded " << nBytes << " bytes OK.\n" << endl;
	/** **/

	/* Start playing with it */
	glBindTexture(GL_TEXTURE_2D, _textureId);


	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);


	/* Load it */
	if(channels == 3)
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
	else if(channels == 4)
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);

	delete data;
	fclose(f);

}

Texture::~Texture(){
}

void Texture::apply(){
	glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
	glBindTexture(GL_TEXTURE_2D, _textureId);
}
