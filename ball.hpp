#pragma once
#include<GL/gl.h>
#include<math.h>
#include"consts.h"
class Ball{
public:
  double radius = BALL_RADIUS;
  double x=0;
  double y=-0.5;
  double vx= BALL_VX;
  double vy= BALL_VY;
  bool moving = false;
  Ball(double a=0, double b=0);

  void draw();


};
