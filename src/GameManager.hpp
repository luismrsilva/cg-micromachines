/*
 * GameManager.hpp
 *
 * */

#ifndef __GAMEMANAGER_H
#define __GAMEMANAGER_H

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
