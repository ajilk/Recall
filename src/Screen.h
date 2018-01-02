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
	WINDOW* msgBox;
	WINDOW* bestScore;
	WINDOW* currScore;	
public:
	Screen();
	int getRows();
	int getColumns();
	bool kbhit();
	void highlight(int highlightNumber);
	void update(string bestScoreValue, string currScoreValue);
	void printMsg(WINDOW* window, vector<char> msg, int start_y, int start_x);
	vector<int> getRandomPattern();
	~Screen();
};

#endif
