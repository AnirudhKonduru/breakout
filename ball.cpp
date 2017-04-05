#include"ball.hpp"
Ball::Ball(double a, double b){
  x=a; y=b;
}

void Ball::draw(){
  glBegin(GL_POLYGON);
  glColor3f (0.0, 0.0, 0.0);
  x = x+vx*moving;
  y = y+vy*moving;
  for(double i=0; i<2*M_PI; i+=M_PI/12){
    glVertex3f(x+cos(i)*radius, y+sin(i)*radius,0.0);
  }
  glEnd();
}
