/*
 * Camera.hpp
 *
 * */

#ifndef __CAMERA_H
#define __CAMERA_H

#include "Entity.hpp"

class Camera : public Entity {
  protected:
    double _near;
    double _far;
  public:
    Camera(double near, double far);
    ~Camera();
    void update();
    void computeProjectionMatrix();
    void computeVisualizationMatrix();
};

 #endif // __CAMERA_H
