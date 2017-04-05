#pragma once
#include"rect.hpp"

class Brick:public Rect{
public:
  int row;
  int col;
  COLOR colors[7] = {
      hex2glcolor(HEX_RED),
      hex2glcolor(HEX_PURPLE),
    	hex2glcolor(HEX_INDIGO),
    	hex2glcolor(HEX_BLUE),
    	hex2glcolor(HEX_TEAL),
    	hex2glcolor(HEX_LIME),
      hex2glcolor(HEX_AMBER),
  };


  Brick(int row_n, int col_n);

  void onCollision();

};
