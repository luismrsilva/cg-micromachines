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
		void update(double delta_t);
		double rotateZ(double deg);
		double getXYAngle();
		bool setGoingForward(bool forward);
		bool isGoingForward();
		void setGhost(bool status);
		void setXYAngle(double deg);
		void updateBox();
		void reset();
	private:
		double _angle_deg;
		bool _isGoingForward;
		bool _isGhost;
};

#endif //_CAR_H
