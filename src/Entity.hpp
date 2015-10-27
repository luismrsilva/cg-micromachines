/*
 * Entity.hpp
 *
 * */

#ifndef __ENTITY_H
#define __ENTITY_H

#include "Vector3.hpp"
#include <cstdlib>

class Entity {
	private:
		Vector3* _position;
	public:
		Entity();
		Entity(double x, double y, double z);
		~Entity();
		Vector3* getPosition();
		Vector3* setPosition(double x, double y, double z);
		Vector3* setPosition(Vector3 *p);
		void moveToRandomPosition();
};

#endif //__ENTITY_H
