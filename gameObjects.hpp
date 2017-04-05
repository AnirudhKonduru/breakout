#pragma once
#include<vector>
#include "ball.hpp"
#include "brick.hpp"
#include "paddle.hpp"

typedef std::vector<Brick> Bricks;


class gameObjects{
private:
  Paddle paddle;
  Bricks bricks;
  bool detectCollision(Ball &ball, Rect &rect);
public:
  Ball ball;
  bool left_pressed;
  bool right_pressed;

  gameObjects();
  void movePaddleOnKey();
  void draw();
  void resetBall(Ball &ball, Paddle &paddle);
};
