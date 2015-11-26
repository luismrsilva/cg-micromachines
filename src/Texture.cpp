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

#include <cstring>

/* test if str ends with suffix */
bool my_endsWith(char *str, char *suffix){
	int lenS = strlen(str);
	int lenSu = strlen(suffix);

	if(lenS < lenSu)
		return false;

	/* Compare from end to begining */
	for(int i = 1; i <= lenSu; i++){
		if( str[lenS-i] != suffix[lenSu-i] )
			return false;
	}
	return true;
}


Texture::Texture(char *path){
	/* Get an id for this texture*/
	glGenTextures(1, &_textureId);

	/* Decide which function to call based on file extension */
	if(my_endsWith(path, (char*)".data")){
		loadRawFile(path, 64, 64, 3);
	}else if(my_endsWith(path, (char*)".png")){
		loadPngFile(path);
	}else{
		D_TRACE();
		cout << "Texture: unsupported extension: \"" << path << "\".\n";
	}
}

void Texture::loadRawFile(char *path, int width, int height, int nChannels){

	if(nChannels != 3 && nChannels != 4){
		cout	<< "WARNING: texture file \"" << path
				<< "\" unsupported channel count: " << nChannels
				<< ".\n" << endl;
		return;
	}

	/** Load texture from file **/
	unsigned char *data;
	int nBytes, nImgBytes;
	nImgBytes = width*height*nChannels;
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

	loadData(width, height, nChannels, data);

	delete data;
	fclose(f);
}

void Texture::loadPngFile(char *path){
	D_TRACE();
	cout << "loadPngFile(): not implemented." << endl;
}

void Texture::loadData(int width, int height, int nChannels, unsigned char *data){

	if(nChannels != 3 && nChannels != 4){
		D_TRACE(<< "WARNING: texture file \"" << path
				<< "\" unsupported channel count: " << channels);
		return;
	}

	/* Start playing with it */
	glBindTexture(GL_TEXTURE_2D, _textureId);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	/* Load it */
	if(nChannels == 3)
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
	else if(nChannels == 4)
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
	else
		D_TRACE(<<"unsupported channel count: " << nChannels);

}

Texture::~Texture(){
}

void Texture::apply(){
	glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
	glBindTexture(GL_TEXTURE_2D, _textureId);
}
