#pragma once

#include"consts.h"
#include<GL/gl.h>
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

  void draw();
  virtual void onCollision(){};

};
