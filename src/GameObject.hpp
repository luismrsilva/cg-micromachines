/*
 * GameObject.hpp
 *
 * */

#ifndef __GAMEOBJECT_H
#define __GAMEOBJECT_H
 
#include "Entity.hpp"

class GameObject : public Entity {
	public:
		GameObject();
		GameObject(double x, double y, double z);
		virtual ~GameObject();
		virtual void draw();
		void update(double delta_t);
};

#endif

