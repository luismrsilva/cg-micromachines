/*
 * Butter.hpp
 *
 * */

#ifndef __BUTTER_H
#define __BUTTER_H

#include "Obstacle.hpp"

class Butter : public Obstacle {
	public:
		Butter();
		Butter(double x, double y, double z);
		~Butter();
		void draw();
		void updateBox();
		virtual bool processCollisionWith(GameObject &obj);
};

#endif //__BUTTER_H
