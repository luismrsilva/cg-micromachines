/*
 * Roadside.hpp
 *
 * */

#ifndef __ROADSIDE_H
#define __ROADSIDE_H

#include <vector>
using namespace std;

#include "StaticObject.hpp"
#include "Cheerio.hpp"
#include <GL/glut.h>

class Roadside : public StaticObject {
	public:
		Roadside();
		~Roadside();
		void update(double delta_t);
		void draw();
		void updateBox();
		virtual bool processCollisionWith(GameObject &obj);
	private:
		vector<Cheerio*> _cheerios;
		void drawCheerio(GLfloat x, GLfloat y, GLfloat z);
		void drawCheerioLineXY(double sX, double sY, double eX, double eY);
		void drawCheerioBezierXY(double x1, double y1, double x2, double y2,
										double x3, double y3, double n_points);

};

#endif //__ROADSIDE_H
