#include <ncurses.h>
#include "Screen.h"
#include "Digits.h"
#include "Message.h"
int main(){
	Screen screen;
	Digits digits;
	Message message;
	WINDOW* bestScore = newwin(18,45,15,7); 	//wborder(bestScore, 0,0,0,0,0,0,0,0);
	WINDOW* currScore = newwin(18,45,15,130);	//wborder(currScore, 0,0,0,0,0,0,0,0);
	WINDOW* msgBox = newwin(5,36, 1, 70);		//wborder(msgBox, 0,0,0,0,0,0,0,0);

	screen.update(0);	
	screen.printMsg(msgBox, message.getMessage("react"), 0, 0);
	screen.printMsg(bestScore, message.getMessage("bestScore"), 0, 0);
	screen.printMsg(currScore, message.getMessage("currScore"), 0, 0);
//	wrefresh(bestScore); 
//	wrefresh(currLevel);
//	wrefresh(msgBox);
	return 0;
}

/*
Steps
	while(count < level);
		Come up with a random number
		Highlight that random number 
		refresh
		pattern.push_back(number);	//Save the pattern to vector
	
	To check if they got it right
		getch until enter is pressed
		check if numbers match the saved pattern
			if(yes)
				level++; start_over;
			if(no);
				game_over; 
				|| 
				level--; start_over;	
IDEA!!!!!
************************************************
Highlight as the user enters numbers 
	IF correct COLOR_GREEN
	IF Wrong color COLOR_RED and blink for limited amount of time
*/

