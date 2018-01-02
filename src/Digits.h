#ifndef DIGITS_H
#define DIGITS_H

#include <ncurses.h>
#include <fstream>
#include <vector>
using namespace std;

class Digits{
private:
	vector<char> number[10];
	vector<char> number1[10];
public:
	Digits();
	int size() { return 10; }
	void print(int digit , int start_y, int start_x, int style);
	vector<char> get(int i, int style){
		switch(style){ 
			case 0:return number[i];
			case 1: return number1[i];
			default: return number[i];
		}
	}
	int getHeight(int style);
	int getWidth(int style);
};

#endif
