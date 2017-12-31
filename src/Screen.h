#ifndef SCREEN_H
#define SCREEN_H

#include <ncurses.h>
#include <stdlib.h>	//exit()
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
	void setup();
	~Screen();
};

#endif
