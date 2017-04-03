#pragma once
#include"consts.h"

class Rect{
public:
  double x;
  double y;
  double height;
  double width;
  double vx;
  double vy;
  bool solid; //if to be drawn
  COLOR color;

  void draw(){
    if(!solid)
      return;

    glBegin(GL_QUADS);
    glColor3f(color.r, color.g, color.b);
    x = x+vx;
    y = y+vy;
    glVertex2f(x,y);
    glVertex2f(x+width,y);
    glVertex2f(x+width,y+height);
    glVertex2f(x,y+height);
    glEnd();
  }

  virtual void onCollision(){};

};
