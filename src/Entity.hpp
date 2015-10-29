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
		Vector3 *_position;
		Vector3 *_old_position;
	public:
		Entity();
		Entity(double x, double y, double z);
		~Entity();
		Vector3* getPosition() const;
		Vector3* setPosition(double x, double y, double z);
		Vector3* setPosition(const Vector3 &pos);
		Vector3* setOldPosition(const Vector3 &pos);
		void moveToOldPosition();
		void moveToRandomPosition();
};

#endif //__ENTITY_H
