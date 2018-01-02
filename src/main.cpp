#include <ncurses.h>
#include "Screen.h"
#include "Digits.h"
#include "Message.h"
int main(){
	Screen screen;
	screen.update("0", "0");

	char ch = getch();
	int bestScore = 0;
	int currScore = 0;

	while(ch != 'q' && ch != 'Q'){
		vector<int> pattern = screen.getRandomPattern();
		for(int i=0; i<pattern.size(); i++){
			screen.highlight(pattern.at(i));
			napms(1000);
		}
		screen.highlight(0);	
		int i=0;
		bool correct = true;	
		while(i<pattern.size() && correct){	
			ch = getch();
			screen.highlight(ch-'0');
			if((ch-'0') != pattern.at(i)) correct = false;
			i++;
		}
		napms(1000);
		screen.highlight(0);	
		if(correct == true){
			currScore++;
			if(currScore > bestScore)
				bestScore++;
		}
		else 
			currScore=0;
		screen.update(to_string(bestScore), to_string(currScore));
		ch = getch();
	}
	
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
		check one by one, indicate when they get it wrong	
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

