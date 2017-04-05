#include"gameObjects.hpp"
#include<stdio.h>
gameObjects::gameObjects(){
  left_pressed=false;
  right_pressed=false;

  resetBall(ball,paddle);

  for(int row=0;row<7;row++)
    for(int col=0; col<8; col++)
      bricks.push_back(Brick(row,col));
}

void gameObjects::draw(){
  //move paddle
  movePaddleOnKey();
  //detect collision with boundary
  if(ball.x-BALL_RADIUS<-1)
    ball.vx = -ball.vx;
  if(ball.x+BALL_RADIUS>1)
    ball.vx = -ball.vx;
  if(ball.y-BALL_RADIUS<-1)
    resetBall(ball,paddle);
  if(ball.y+BALL_RADIUS>1)
    ball.vy = -ball.vy;

  //collision with rect
  detectCollision(ball,paddle);
  for(Bricks::iterator i = bricks.begin(); i!=bricks.end(); i++)
    detectCollision(ball, *i);

  ball.draw();
  paddle.draw();
  for(Bricks::iterator i = bricks.begin(); i!=bricks.end(); i++)
    i->draw();

}

void gameObjects::movePaddleOnKey(){

  if(!left_pressed && right_pressed && paddle.x+PADDLE_WIDTH<1)
    paddle.vx=0.05;
  if(!right_pressed && left_pressed && paddle.x>-1)
    paddle.vx=-0.05;

  if(!left_pressed && !right_pressed)
    paddle.vx=0.0;


  if(!ball.moving)
    resetBall(ball,paddle);

}



bool gameObjects::detectCollision(Ball &ball, Rect &rect){

  bool collided=false;
  if(!rect.solid)
    return false;

  float ball_t = ball.y+ball.radius;
  float ball_b = ball.y-ball.radius;
  float ball_l = ball.x-ball.radius;
  float ball_r = ball.x+ball.radius;

  float rect_t = rect.y+rect.height;
  float rect_b = rect.y;
  float rect_l = rect.x;
  float rect_r = rect.x+rect.width;


  //collision with rect top or bottom
  if(ball.x>rect_l && ball.x<rect_r){

    float ball_rect_dist = ball_b-rect_t;
    if(ball_rect_dist <=0 && fabs(ball_rect_dist)<=fabs(ball.vy)){
      ball.vy = -ball.vy;
      collided=true;
    }

    ball_rect_dist = ball_t-rect_b;
    if(ball_rect_dist >=0 && fabs(ball_rect_dist)<=fabs(ball.vy)){
      ball.vy = -ball.vy;
      collided = true;
    }
  }

  //collision with rect sides
  //right side of rect
  if(ball.y<rect_t && ball.y>rect_b){

    float ball_rect_dist = ball_l-rect_r;
    if(ball_rect_dist <=0 && fabs(ball_rect_dist)<=-ball.vx){
      ball.vx = -ball.vx;
      collided=true;
    }
    //left side of rect
    ball_rect_dist = ball_r-rect_l;
    if(ball_rect_dist >=0 && fabs(ball_rect_dist)<=ball.vx){
      ball.vx = -ball.vx;
      collided = true;
    }
  }

  if(collided)
    rect.onCollision();
  return collided;

}

void gameObjects::resetBall(Ball &ball,Paddle &paddle){
  ball.x=paddle.x+paddle.width/2;
  ball.y=paddle.y+paddle.height/2+ball.radius;
  ball.vx=BALL_VX;
  ball.vy=BALL_VY;
  ball.moving=false;
}
