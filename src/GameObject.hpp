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
    ~GameObject();
    void draw();
    void update(double delta_t);
};

 #endif
