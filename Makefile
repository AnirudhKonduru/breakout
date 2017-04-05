#OBJS specifies files to compile for project
OBJS = breakout.o ball.o rect.o brick.o paddle.o gameObjects.o
CC = g++
CPPFLAGS = -std=c++11 -Wall
LFLAGS = -lglut -lGL
#specifies name of executable
TARGET = breakout

%.o: %.cpp
	$(CC) -c $(CPPFLAGS) -o $@ $<

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET) $(LFLAGS)
#all : $(OBJS)
#	$(CC) $(OBJS) $(CFLAGS) -o $(TARGET) $(LFLAGS)

breakout.o: breakout.cpp gameObjects.hpp
gameObjects.o: gameObjects.cpp gameObjects.hpp \
ball.hpp brick.hpp paddle.hpp
ball.o: ball.cpp ball.hpp paddle.cpp
rect.o: rect.cpp rect.hpp
brick.o: brick.cpp brick.hpp rect.cpp
paddle.o: paddle.cpp paddle.hpp rect.cpp

clean:
	rm *.o breakout
