#ifndef DIGITS_H
#define DIGITS_H

#include <ncurses.h>
#include <fstream>
#include <vector>
using namespace std;

class Digits{
private:
	vector<char> number[10];
public:
	Digits();
	int size() { return 10; }
	void print(int digit , int start_y, int start_x);
	int getHeight();
	int getWidth();
};

#endif
