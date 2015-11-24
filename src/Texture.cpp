/*
 * Texture.cpp
 *
 * */

#include "Texture.hpp"
#include "Vector3.hpp"
#include <iostream>
#include <cmath>

using namespace std;
#include <GL/glut.h>
//#include "lib/SOIL.h"

#include "debug.hpp"
#include "myunits.hpp"
#include "game_config.hpp"


Texture::Texture(char *path, int width, int height){
	// IMAGE LOADING
}

Texture::~Texture(){
	// free image bytes!
}

void Texture::apply(){
	glGenTextures(1, &_texture);
	glBindTexture(GL_TEXTURE_2D, _texture);

	float border_color[] = { 0.0f, 0.0f, 0.0f, 1.0f };

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, border_color);




}