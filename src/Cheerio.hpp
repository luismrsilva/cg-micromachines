/*
 * Cheerio.hpp
 *
 * */

#ifndef __CHEERIO_H
#define __CHEERIO_H

#include "Obstacle.hpp"

class Cheerio : public Obstacle {
	public:
		Cheerio();
		Cheerio(double x, double y, double z);
		~Cheerio();
		void draw();
		void updateBox();
		virtual bool processCollisionWith(GameObject &obj);
};

#endif //__CHEERIO_H
