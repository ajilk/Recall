#include "Digits.h"

Digits::Digits(){	
	ifstream infile;
	string filename;
	char ch;
	for(int i=0; i<10; i++){
		filename = "../digits/" + std::to_string(i) + ".txt";
		infile.open(filename);
		if(!infile.is_open()){
			mvprintw(0,0,"ERROR: Unable to open file %d.txt",i);
			refresh();
			getch();
		}
		while(infile.get(ch)){
			number[i].push_back(ch);
		}
		infile.close();
	}
}

void Digits::print(int digit, int start_y, int start_x){
	char ch;
	int offset_x = 0;
	int offset_y = 0;
	for(int i=0; i<number[digit].size(); i++){
		ch = number[digit].at(i);	
		if(ch == '\n') { offset_y++; offset_x = 0; }
		else offset_x++;
		mvprintw(start_y + offset_y, start_x+offset_x, "%c", ch); 
	}
}

int Digits::getHeight(){
	int height = 0;
	for(int i=0; i<number[1].size(); i++){
		if(number[1].at(i) == '\n')
			height++;
	}
	return height;
}

int Digits::getWidth(){
	int width = 0;
	int i = 0;
	while(number[1].at(i) != '\n'){
		width++;
		i++;
	}
	return width;
}
