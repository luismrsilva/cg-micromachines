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
		void updateBox();
	private:
		float _angle;
		bool _active;
		int _activate_time;
};

#endif //__ORANGE_H
