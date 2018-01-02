#include "Screen.h"

Screen::Screen(){
	initscr();
	getmaxyx(stdscr, rows, columns);
	curs_set(0);
	cbreak();
	noecho();
	use_default_colors();
	srand(time(NULL));
/*	if(!has_colors()){
		clear();
		mvprintw(0,0,"ERROR: TERMINAL DOES NOT SUPPORT COLOR");
		exit (EXIT_FAILURE);
	}else
		start_color();
*/
	bestScore = newwin(10,30,22,5); 	//wborder(bestScore, 0,0,0,0,0,0,0,0);
    currScore = newwin(10,30,22,137);	//wborder(currScore, 0,0,0,0,0,0,0,0);
	msgBox = newwin(7,36, 0, 70);		//wborder(msgBox, 0,0,0,0,0,0,0,0);	
	refresh();
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

void Screen::highlight(int highlightNumber){
	int start_x = 55;
	int start_y = 10;
	int offset_x = 0; 
	int offset_y = 0;
	int spacing_x  = 8;
	int spacing_y = 3;
	for(int i=1; i<digits.size(); i++){
		if(i == highlightNumber){
			attron(A_REVERSE | A_BOLD | A_STANDOUT);
			digits.print(i, start_y + offset_y, start_x + offset_x, 0);
			attroff(A_REVERSE | A_BOLD | A_STANDOUT);
		}else
			digits.print(i, start_y + offset_y, start_x + offset_x, 0);
		if(i == 3 || i == 6){
			offset_x = 0;
			offset_y += digits.getHeight(0)+spacing_y;
		}
		else
			offset_x += digits.getWidth(0)+spacing_x;
	}
	refresh();
}

void Screen::update(string bestScoreValue, string currScoreValue){
	printMsg(msgBox, message.getMessage("react"), 1, 1);
    printMsg(stdscr, message.getMessage("bestScore"), 10, 7);
    printMsg(stdscr, message.getMessage("currScore"), 10, 130);

	int start_y = 0, start_x = 0, offset_x = 0;

	if(bestScoreValue.size() == 2) start_x = 2;
	else start_x = 8;
	for(int i=0; i<bestScoreValue.size(); i++){
		printMsg(bestScore, digits.get(bestScoreValue.at(i)-'0', 1), start_y, start_x+offset_x);
		offset_x += digits.getWidth(1);
	}
	offset_x = 0;
	if(currScoreValue.size() == 2) start_x = 2;
	else start_x = 8;
	for(int i=0; i<currScoreValue.size(); i++){
		printMsg(currScore, digits.get(currScoreValue.at(i)-'0', 1), start_y, start_x+offset_x);
		offset_x += digits.getWidth(1);
	}
	wrefresh(msgBox);
	wrefresh(stdscr);
}

void Screen::printMsg(WINDOW* window, vector<char> msg, int start_y, int start_x){
	char ch;
	int offset_x = 0;
	int offset_y = 0;
	for(int i=0; i<msg.size(); i++){	
		ch = msg.at(i);
		if(ch == '\n'){
			offset_x = 0;
			offset_y++;
		}else{
			offset_x++;	
			mvwprintw(window, start_y+offset_y, start_x+offset_x, "%c", ch); 
		}
	}
	wrefresh(window);
}

vector<int> Screen::getRandomPattern(){
	vector<int> pattern; 
	for(int i=0; i<3; i++){
		pattern.push_back(rand()%9+1);
	}
	return pattern;
}

Screen::~Screen(){
	refresh();
	nodelay(stdscr, FALSE);
	getch();
	endwin();
}
