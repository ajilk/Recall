#include "Screen.h"

Screen::Screen(){
	initscr();
	getmaxyx(stdscr, rows, columns);
	curs_set(0);
	cbreak();
	noecho();
	use_default_colors();
/*	if(!has_colors()){
		clear();
		mvprintw(0,0,"ERROR: TERMINAL DOES NOT SUPPORT COLOR");
		exit (EXIT_FAILURE);
	}else
		start_color();
*/
}

int Screen::getRows(){
	return rows;
}

int Screen::getColumns(){
	return columns;
}

bool Screen::kbhit(){
	int ch=getch();
	if(ch != ERR){
		ungetch(ch);
		return true;
	}
	else
		return false;
}

void Screen::setup(){
	Digits digits;
	int start_x = 55;
	int start_y = 7;
	int offset_x = 0; 
	int offset_y = 0;
	int spacing_x  = 8;
	int spacing_y = 3;
	for(int i=1; i<digits.size(); i++){
		digits.print(i, start_y + offset_y, start_x + offset_x);
		if(i == 3 || i == 6){
			offset_x = 0;
			offset_y += digits.getHeight()+spacing_y;
		}
		else
			offset_x += digits.getWidth()+spacing_x;
	}
	refresh();
}

Screen::~Screen(){
	refresh();
	nodelay(stdscr, FALSE);
	getch();
	endwin();
}
