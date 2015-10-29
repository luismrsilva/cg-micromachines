/*
 * GameObject.hpp
 *
 * */

#ifndef __GAMEOBJECT_H
#define __GAMEOBJECT_H
 
#include "Entity.hpp"
#include "Box.hpp"
#include <cstdlib>


class GameObject : public Entity {
	public:
		GameObject();
		GameObject(double x, double y, double z);
		virtual ~GameObject();
		virtual void draw();
		virtual void update(double delta_t);
	protected:
		virtual void updateBox();
		Box _box;
};

#endif

