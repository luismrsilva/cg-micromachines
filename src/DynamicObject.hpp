/*
 * DynamicObject.hpp
 *
 * */

#ifndef __DYNAMIC_OBJECT_H
#define __DYNAMIC_OBJECT_H

#include "GameObject.hpp"
#include "Vector3.hpp"

class DynamicObject : public GameObject {
	public:
		DynamicObject();
		~DynamicObject();
		void update(double delta_t);
		void setSpeed(const Vector3 speed);
		void setSpeed(double x, double y, double z);
		Vector3 getSpeed();
	private:
		Vector3 *_speed;
};

#endif //__DYNAMIC_OBJECT_H
