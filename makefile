#makefile for Combat

exec: creature2.cpp creature2.h combat2.cpp tournament.h tournament.cpp 
	g++ -std=c++0x -g creature2.cpp tournament.cpp combat2.cpp -o combat