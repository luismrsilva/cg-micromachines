/*
 * GameManager.hpp
 *
 * */

#ifndef __GAMEMANAGER_H
#define __GAMEMANAGER_H

#include <GL/glut.h>

class GameManager {
  public:
    GameManager();
    ~GameManager();
    void display();
    void reshape(GLsizei w, GLsizei h);
    void keyPressed();
    void onTimer();
    void idle();
    void update();
    void init();
};

 #endif // __GAMEMANAGER_H
