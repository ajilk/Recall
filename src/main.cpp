#include <ncurses.h>
#include "Screen.h"
#include "Digits.h"
int main(){
	Screen screen;
	Digits digits;
	screen.setup();	
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

