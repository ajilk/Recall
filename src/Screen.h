#ifndef SCREEN_H
#define SCREEN_H

#include <ncurses.h>
#include <stdlib.h>	//exit()
#include <fstream>
#include <vector>
#include <random>
#include "Digits.h"
#include "Message.h"

class Screen{
private:
	int rows;
	int columns;
	Digits digits;
	Message message;
	struct Coordinate{
		int Y;
		int X;
		Coordinate() {Y=0; X=0;}
		Coordinate(int Y, int X):Y(Y), X(X) {}
	};
	Coordinate bestScore, currScore, msg;
public:
	Screen();
	int getRows() { return rows; }
	int getColumns() { return columns; }
	bool kbhit();
	void highlight(int highlightNumber, int mode);
	void update(string bestScoreValue, string currScoreValue, string msg);
	void printMsg(WINDOW* window, vector<char> msg, int start_y, int start_x);
	vector<int> getRandomPattern(int length);
	~Screen();
};

#endif
