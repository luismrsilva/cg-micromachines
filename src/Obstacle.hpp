/*
 * Obstacle.hpp
 *
 * */

#ifndef __OBSTACLE_H
#define __OBSTACLE_H

#include "DynamicObject.hpp"

class Obstacle : public DynamicObject {
	public:
		Obstacle();
		Obstacle(double x, double y, double z);
		~Obstacle();
		void draw();
};

#endif //__OBSTACLE_H
