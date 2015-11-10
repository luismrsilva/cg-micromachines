/*
 * StaticObject.hpp
 * 
 * */

#ifndef __STATIC_OBJECT_H
#define __STATIC_OBJECT_H

#include "GameObject.hpp"

class StaticObject : public GameObject {
	public:
		StaticObject();
		StaticObject(double x, double y, double z);
		~StaticObject();
};

#endif //__STATIC_OBJECT_H
