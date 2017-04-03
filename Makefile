#OBJS specifies files to compile for project
OBJS = breakout.cpp

CC = g++

CFLAGS = -std=c++11 -Wall

LFLAGS = -lSDL2 -lglut -lGL

#specifies name of executable
OBJ_NAME = breakout

all : $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) $(LFLAGS) -o $(OBJ_NAME)
