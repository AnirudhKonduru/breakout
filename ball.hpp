#include<math.h>
#pragma once
#include"consts.h"
#include"paddle.hpp"

class Ball{
public:
  double radius = BALL_RADIUS;
  double x=0;
  double y=-0.5;
  double vx= BALL_VX;
  double vy= BALL_VY;
  bool moving = false;
  Ball(double a=0, double b=0){
    x=a; y=b;
  }

  void draw(){
    glBegin(GL_POLYGON);
    glColor3f (0.0, 0.0, 0.0);
    x = x+vx*moving;
    y = y+vy*moving;
    for(double i=0; i<2*PI; i+=PI/12){
      glVertex3f(x+cos(i)*radius, y+sin(i)*radius,0.0);
    }
    glEnd();
  }

  void reset(Paddle paddle){
    x=paddle.x+PADDLE_WIDTH/2;
    y=paddle.y+PADDLE_HEIGHT/2+BALL_RADIUS;
    vx=BALL_VX;
    vy=BALL_VY;
    moving=false;
  }

};
