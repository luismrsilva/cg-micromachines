/*
 * Orange.hpp
 *
 * */

#ifndef __ORANGE_H
#define __ORANGE_H

#include "Obstacle.hpp"

class Orange : public Obstacle {
	public:
		Orange();
		Orange(double x, double y, double z);
		~Orange();
		void draw();
		void update(double delta_t);
		void resetPosition();
	private:
		int _angle;
};

#endif //__ORANGE_H
