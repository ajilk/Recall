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

void Screen::update(int highlightNumber){
	Digits digits;
	int start_x = 55;
	int start_y = 7;
	int offset_x = 0; 
	int offset_y = 0;
	int spacing_x  = 8;
	int spacing_y = 3;
	for(int i=1; i<digits.size(); i++){
		if(i == highlightNumber){
			attron(A_REVERSE | A_BOLD | A_STANDOUT);
			digits.print(i, start_y + offset_y, start_x + offset_x);
			attroff(A_REVERSE | A_BOLD | A_STANDOUT);
		}else
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

void Screen::printMsg(WINDOW* window, vector<char> msg, int start_y, int start_x){
	int offset_x = 0;
	int offset_y = 0;
	for(int i=0; i<msg.size(); i++){
		char ch = msg.at(i);
		if(ch == '\n'){
			offset_x = 0;
			offset_y++;
		}else
			offset_x++;	
		mvwprintw(window, start_y+offset_y, start_x+offset_x, "%c", ch); 
	}
	wrefresh(window);
}

Screen::~Screen(){
	refresh();
	nodelay(stdscr, FALSE);
	getch();
	endwin();
}
