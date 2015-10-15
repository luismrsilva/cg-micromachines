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
		double rotateZ(double deg);
		double getXYAngle();
		bool setGoingForward(bool forward);
		bool isGoingForward();
		void setXYAngle(double deg);
	private:
		double _angle_deg;
		bool _isGoingForward;
};

#endif //_CAR_H
