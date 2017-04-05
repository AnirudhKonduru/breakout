#include "rect.hpp"

void Rect::draw(){
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
