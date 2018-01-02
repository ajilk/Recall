#include <ncurses.h>
#include "Screen.h"
#include "Digits.h"
#include "Message.h"
int main(){
	Screen screen;
	int currScore = 1, bestScore = 1;
	screen.update(to_string(bestScore), to_string(currScore), "ready");
	
	char ch = getch();	
	while(ch != 'q' && ch != 'Q'){
		screen.update(to_string(bestScore), to_string(currScore), "focus");
		vector<int> pattern = screen.getRandomPattern(currScore);
		for(int i=0; i<pattern.size(); i++){
			screen.highlight(pattern.at(i), 1);
			napms(1000);
			screen.highlight(pattern.at(i), 0);
			napms(500);
		}
		screen.update(to_string(bestScore), to_string(currScore), "recall");
		
		int i=0;
		bool correct = true;
		do{
			ch = getch();
			if(ch != 'q' && ch != 'Q'){
				if(ch-'0' != pattern.at(i)){
					correct = false;
					currScore = 1;
					screen.highlight(ch-'0', 2);
					napms(1500);
				}else{
					screen.highlight(ch-'0', 3);
					if(i==pattern.size()-1) napms(150);
					napms(100);
					screen.highlight(ch-'0', 0);
				}
				i++;
			}else
				correct = false;
		}while(i<pattern.size() && correct);
		if(correct){
			currScore++;
			bestScore = bestScore < currScore ? currScore : bestScore;
		}
		if(ch != 'q' && ch != 'Q'){
			screen.update(to_string(bestScore), to_string(currScore), "ready");
			ch = getch();
		}
	}
	return 0;
}
