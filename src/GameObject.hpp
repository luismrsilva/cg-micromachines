/*
 * GameObject.hpp
 *
 * */

#ifndef __GAMEOBJECT_H
#define __GAMEOBJECT_H

#include "Entity.hpp"
#include "Box.hpp"
#include "Material.hpp"
#include <GL/glut.h>
#include <stdbool.h>


class GameObject : public Entity {
	public:
		GameObject();
		GameObject(double x, double y, double z);
		virtual ~GameObject();
		virtual void draw();
		virtual void update(double delta_t);
		void setColor(GLfloat r, GLfloat g, GLfloat b);
		bool isColidingWith(const GameObject &obj);
		bool isOutOfBounds();
		virtual bool processCollisionWith(GameObject &obj);
		virtual void updateBox();
	protected:
		Box _box;
		Material *_material;
};

#endif

