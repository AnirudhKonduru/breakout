#pragma once

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 640

#define BRICK_GAP 0.2247/10
#define BRICK_WIDTH 0.2247
#define BRICK_HEIGHT 0.07

#define PADDLE_X 0
#define PADDLE_Y -0.8
#define PADDLE_HEIGHT 0.013
#define PADDLE_WIDTH 0.3

#define BALL_VX 0.0125
#define BALL_VY 0.0125

#define BALL_RADIUS 0.022
#define PI 3.1415926535

//colors
#define HEX_RED 0xF44336
#define HEX_PURPLE 0x9C27B0
#define HEX_INDIGO 0x673AB7
#define HEX_BLUE 0x2196F3
#define HEX_TEAL 0x009688
#define HEX_LIME 0xCDDC39
#define HEX_AMBER 0xFFC107

enum colors {RED ,PURPLE,INDIGO, BLUE, TEAL, LIME,AMBER};

typedef struct{
public:
  float r,g,b;
  //COLOR(float x, float y, float z){
  //  r=x;g=y;z=b;
  //}
}COLOR;

COLOR hex2glcolor(int hex){
  float r = ((hex >> 16) & 0xFF) / 255.0;
  float g = ((hex >> 8) & 0xFF) / 255.0;
  float b = ((hex) & 0xFF) / 255.0;
  COLOR col = {r,g,b};
  return col;
}

COLOR colors[] = {
    hex2glcolor(HEX_RED),
    hex2glcolor(HEX_PURPLE),
  	hex2glcolor(HEX_INDIGO),
  	hex2glcolor(HEX_BLUE),
  	hex2glcolor(HEX_TEAL),
  	hex2glcolor(HEX_LIME),
    hex2glcolor(HEX_AMBER),
};
