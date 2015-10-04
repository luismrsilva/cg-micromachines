/*
 * Entity.hpp
 * 
 * */

#ifndef __ENTITY_H
#define __ENTITY_H

#include "Vector3.hpp"

class Entity {
	public:
		Entity();
		~Entity();
		Vector3* getPosition();
		Vector3* setPosition(double x, double y, double z);
		Vector3* setPosition(Vector3 *p);
	private:
		Vector3* _position;
};

#endif //__ENTITY_H
