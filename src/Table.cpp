/*
 * Table.cpp
 *
 * */

#include "Table.hpp"

#include <GL/glut.h>
#include "myunits.hpp"
#include "game_config.hpp"


Table::Table(GLfloat x, GLfloat y, GLfloat z){
	setPosition(x, y, z);
	_material->setMaterial(0.15, 0.15, 0.15);
	_box.changeTo(	-GAME_TABLE_LIMIT, GAME_TABLE_LIMIT,
					-GAME_TABLE_LIMIT, GAME_TABLE_LIMIT);
}

Table::~Table(){

}

void drawSquareXY(GLfloat x, GLfloat y, GLfloat halfWidth) {
	glPushMatrix();
		glTranslatef(x, y, 0);
		glNormal3f(0.0, 0.0, 1.0);
		glVertex3f(x - halfWidth, y - halfWidth, 0);
		glVertex3f(x + halfWidth, y - halfWidth, 0);
		glVertex3f(x + halfWidth, y + halfWidth, 0);
		glVertex3f(x - halfWidth, y + halfWidth, 0);
	glPopMatrix();
}

void Table::draw(){
	Vector3 *pos = getPosition();
	const float halfWidth = GAME_TABLE_LIMIT / GAME_TABLE_TILE_DIVISION_COUNT;
	const float width = 2 * halfWidth;
	const float start = - GAME_TABLE_LIMIT + halfWidth;
	glPushMatrix();

		setColor(0.15, 0.20, 0.30);

		_material->draw();
		glTranslatef(pos->getX(), pos->getY(), pos->getZ() + GAME_TABLE_LIMIT);
		//glutSolidCube(GAME_TABLE_LIMIT*2);
		/* draws table surface in -GAME_TABLE_LIMIT < x, y < GAME_TABLE_LIMIT */
		glBegin(GL_QUADS);
			for (float i = start; i < GAME_TABLE_LIMIT; i += width) // each line
				for (float j = start; j < GAME_TABLE_LIMIT; j += width) // each column
					drawSquareXY(i, j, halfWidth);
		glEnd();
	glPopMatrix();

	StaticObject::draw();
}
