#ifndef MESSAGE_H
#define MESSAGE_H

#include <ncurses.h>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

class Message{
private:
	vector<char> react;	
	vector<char> confirm;
	vector<char> help;
	vector<char> focus;
	vector<char> credits;
	vector<char> bestScore;
	vector<char> currScore;
public:
	Message();
	vector<char> getMessage(string msgName);
};

#endif
