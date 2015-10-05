/*
 * Car.hpp
 *
 * */

#ifndef __CAR_H
#define __CAR_H

#include "DynamicObject.hpp"

class Car : public DynamicObject {
	public:
		Car();
		~Car();
		void draw();
};

#endif //_CAR_H
