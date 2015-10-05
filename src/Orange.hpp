/*
 * Orange.hpp
 *
 * */

#ifndef __ORANGE_H
#define __ORANGE_H

#include "DynamicObject.hpp"

class Orange : public Obstacle {
	public:
		Orange();
		~Orange();
    void draw();
};

#endif //__ORANGE_H
