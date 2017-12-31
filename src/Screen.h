#ifndef SCREEN_H
#define SCREEN_H

#include <ncurses.h>
#include <stdlib.h>	//exit()
#include <fstream>
#include <vector>
#include "Digits.h"

class Screen{
private:
	int rows;
	int columns;
public:
	Screen();
	int getRows();
	int getColumns();
	bool kbhit();
	void update(int highlightNumber);
	void createNewWin(int rows, int cols, int start_y, int start_x);
	void printMsg(WINDOW* window, vector<char> msg, int start_y, int start_x);
	~Screen();
};

#endif
