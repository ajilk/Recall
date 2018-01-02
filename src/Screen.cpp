#include "Screen.h"

Screen::Screen(){
	initscr();
	getmaxyx(stdscr, rows, columns);
	curs_set(0);
	cbreak();
	noecho();
	use_default_colors();
	srand(time(NULL));
	start_color();

	bestScore.Y=10;	bestScore.X=7;
	currScore.Y=10; currScore.X=125;
	msg.Y = 2; 		msg.X=62;
//	bestScore = newwin(10,30,22,5); 	//wborder(bestScore, 0,0,0,0,0,0,0,0);
//    currScore = newwin(10,30,22,137);	//wborder(currScore, 0,0,0,0,0,0,0,0);
//	msgBox = newwin(7,36, 0, 70);		//wborder(msgBox, 0,0,0,0,0,0,0,0);	
	refresh();
}

bool Screen::kbhit(){
	int ch = getch();
	if(ch != ERR){
		ungetch(ch);
		return true;
	}
	else
		return false;
}

void Screen::highlight(int highlightNumber, int mode){
/*
	Mode: 0 - reset
		1 - reverse
		2 - red (wrong)
		3 - green (correct)
*/
	Coordinate start(10,100);
	Coordinate offset(0,0);
	Coordinate spacing(3,8);
	init_pair(2, COLOR_RED, COLOR_BLACK);
	init_pair(3, COLOR_GREEN, COLOR_BLACK);
	for(int i=digits.size()-1; i>=0; i--){
		if(i == highlightNumber){
			switch(mode){
				case 0:
					digits.print(i, start.Y + offset.Y, start.X + offset.X, 0);
					break;
				case 1:
					attron(A_REVERSE | A_BOLD | A_STANDOUT);
					digits.print(i, start.Y + offset.Y, start.X + offset.X, 0);
					attroff(A_REVERSE | A_BOLD | A_STANDOUT);
					break;
				case 2:
					attron(COLOR_PAIR(2) | A_BOLD | A_STANDOUT);
					digits.print(i, start.Y + offset.Y, start.X + offset.X, 0);
					attroff(COLOR_PAIR(2) | A_BOLD | A_STANDOUT);
					break;
				case 3: 
					attron(COLOR_PAIR(3) | A_BOLD | A_STANDOUT);
					digits.print(i, start.Y + offset.Y, start.X + offset.X, 0);
					attroff(COLOR_PAIR(3) | A_BOLD | A_STANDOUT);
					break;
				default: 
					digits.print(i, start.Y + offset.Y, start.X + offset.X, 0);
			}
		}else digits.print(i, start.Y + offset.Y, start.X + offset.X, 0);
		
		if(i == 7 || i == 4){
			offset.X = 0;
			offset.Y += digits.getHeight(0)+spacing.Y;
		}else offset.X -= digits.getWidth(0)+spacing.X;
	}
	refresh();
}

void Screen::update(string bestScoreValue, string currScoreValue, string msgName){
	printMsg(stdscr, message.getMessage(msgName),msg.Y, msg.X);
	printMsg(stdscr, message.getMessage("bestScore"), bestScore.Y, bestScore.X);
	printMsg(stdscr, message.getMessage("currScore"), currScore.Y, currScore.X);
	highlight(0,0);
	
	Coordinate start(bestScore.Y+11, bestScore.X);
	Coordinate offset;
	if(bestScoreValue.size() == 2) start.X += 1;
	else start.X += 7;
	for(int i=0; i<bestScoreValue.size(); i++){
		printMsg(stdscr, digits.get(bestScoreValue.at(i)-'0', 1), start.Y, start.X+offset.X);
		offset.X += digits.getWidth(1);
	}

	offset.X = 0;
	start.Y=currScore.Y+11;
	start.X=currScore.X;
	if(currScoreValue.size() == 2) start.X += 8;
	else start.X += 15;
	for(int i=0; i<currScoreValue.size(); i++){
		printMsg(stdscr, digits.get(currScoreValue.at(i)-'0', 1), start.Y, start.X+offset.X);
		offset.X += digits.getWidth(1);
	}
	refresh();
}

void Screen::printMsg(WINDOW* window, vector<char> msg, int start_y, int start_x){
	char ch;
	Coordinate offset(0,0);
	for(int i=0; i<msg.size(); i++){	
		ch = msg.at(i);
		if(ch == '\n'){
			offset.X = 0;
			offset.Y++;
		}else{
			offset.X++;	
			mvwprintw(window, start_y+offset.Y, start_x+offset.X, "%c", ch); 
		}
	} wrefresh(window);
}

vector<int> Screen::getRandomPattern(int length){
	vector<int> pattern; 
	for(int i=0; i<length; i++){
		pattern.push_back(rand()%9+1);
	}
	return pattern;
}

Screen::~Screen(){
	clear();
	printMsg(stdscr, message.getMessage("credits"), getRows()/2-1, getColumns()/2-17);
	refresh();
	nodelay(stdscr, FALSE);
	getch();
	endwin();
}
