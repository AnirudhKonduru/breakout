#include<iostream>
#include<stdio.h>
using namespace std;

#include<GL/glut.h>
#include<GL/gl.h>

#include"gameObjects.hpp"

GameObjects game_objs;

void display();

void keyboard(unsigned char key, int x, int y){
  switch(key){
    //case GLUT_KEY_LEFT:
    case 'a':// case '^[[D':
                game_objs.left_pressed=true;
                //game_objs.right_pressed=false;
                break;
    //case GLUT_KEY_RIGHT:
    case 'd':// case '^[[C':
                game_objs.right_pressed=true;
                //game_objs.left_pressed=false;
                break;

  }
}

void keyboardUp(unsigned char key, int x, int y){
  switch(key){
    case ' ':
                game_objs.ball.moving=true;
                break;
    case 'a':// case '^[[D':
                game_objs.left_pressed=false;
                break;
    case 'd':// case '^[[C':
                game_objs.right_pressed=false;
                //game_objs.left_pressed=false;
                break;
  }

}

/*
void mouse(int x, int){
  game_objs.movePaddleOnMouse((float)x/1000);
}
*/

int main(int argc, char * argv[]){

  //initialize glut library
  glutInit(&argc, argv);


  glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
  glutInitWindowSize(600,600);
  glutInitWindowPosition(0,0);


  glutCreateWindow("Atari Breakout!");

  glClearColor(1.0f,1.0f,1.0f,1.0f);
  glOrtho(-1.0f, +1.0f, -1.0f,+1.0f,1,1);
  glutDisplayFunc(display);
  glutIdleFunc(display);

  glutKeyboardFunc(keyboard);
  glutKeyboardUpFunc(keyboardUp);
  //glutPassiveMotionFunc(mouse);

  glutMainLoop();

  return 0;
}

void display(){
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  //draw here
  game_objs.draw();

  glutSwapBuffers();

}
