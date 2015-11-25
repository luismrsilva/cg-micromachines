/*
 * Table.hpp
 *
 * */

#ifndef __TABLE_H
#define __TABLE_H

#include "StaticObject.hpp"
#include "Texture.hpp"
#include <GL/glut.h>

class Table : public StaticObject {
	public:
		Table(GLfloat x, GLfloat y, GLfloat z);
		~Table();
		void draw();
	private:
		Texture *_texture;
};

#endif //__TABLE_H
