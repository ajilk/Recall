#include "Digits.h"

Digits::Digits(){	
	string dir = "../resources/digits/box/";
	string filename;
	char ch;
	
	ifstream infile;
	for(int i=0; i<10; i++){
		filename = dir + std::to_string(i) + ".txt";
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

	
	dir = "../resources/digits/regular/";	
	for(int i=0; i<10; i++){
		filename = dir + std::to_string(i) + ".txt";
		infile.open(filename);
		if(!infile.is_open()){
			mvprintw(0,0,"ERROR: Unable to open file %d.txt",i);
			refresh();
			getch();
		}
		while(infile.get(ch)){
			number1[i].push_back(ch);
		}
		infile.close();
	}


}

void Digits::print(int digit, int start_y, int start_x, int style){
	char ch;
	int offset_x = 0;
	int offset_y = 0;
	switch(style){
		case 0:
			for(int i=0; i<number[digit].size(); i++){
			 	ch = number[digit].at(i);
				if(ch == '\n') { offset_y++; offset_x = 0; }
				else { 
					offset_x++;
					mvprintw(start_y + offset_y, start_x+offset_x, "%c", ch); 
				}
			}break; 
		case 1:
			for(int i=0; i<number1[digit].size(); i++){
			 	ch = number1[digit].at(i);
				if(ch == '\n') { offset_y++; offset_x = 0; }
				else { 
					offset_x++;
					mvprintw(start_y + offset_y, start_x+offset_x, "%c", ch); 
				}
			}break; 
		default: 	
			for(int i=0; i<number[digit].size(); i++){
			 	ch = number[digit].at(i);
				if(ch == '\n') { offset_y++; offset_x = 0; }
				else {
					offset_x++;
					mvprintw(start_y + offset_y, start_x+offset_x, "%c", ch); 
				}
			}break; 
	}	
}

int Digits::getHeight(int style){
	int height = 0;
	switch(style){
		case 0:
			for(int i=0; i<number[1].size(); i++){
				if(number[1].at(i) == '\n')
					height++;
			}break;
		case 1:
			for(int i=0; i<number1[1].size(); i++){
				if(number1[1].at(i) == '\n')
					height++;
			}break;
		default:
			for(int i=0; i<number[1].size(); i++){
				if(number[1].at(i) == '\n')
					height++;
			}
	}
	return height;
}

int Digits::getWidth(int style){
	int width = 0;
	int i = 0;
	switch(style){
		case 0:
			while(number[1].at(i) != '\n'){
				width++;
				i++;
			}break;
		case 1:
			while(number1[1].at(i) != '\n'){
				width++;
				i++;
			}break;
		default:
			while(number[1].at(i) != '\n'){
				width++;
				i++;
			}
	}
	return width;
}
