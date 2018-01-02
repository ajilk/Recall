#include "Message.h"

Message::Message(){
	string dir = "../resources/messages/";
	char ch;
	string filename;
	ifstream infile;
	
	filename = dir + "recall.txt";
	infile.open(filename);
	if(!infile.is_open()){
		mvprintw(0,0,"ERROR: Could not open %s", filename.c_str());
		getch();
	}
	while(infile.get(ch))
		recall.push_back(ch);
	infile.close();

	filename = dir + "confirm.txt";
	infile.open(filename);
	if(!infile.is_open()){
		mvprintw(0,0,"ERROR: Could not open %s", filename.c_str());
		getch();
	}
	while(infile.get(ch))
		confirm.push_back(ch);
	infile.close();

	filename = dir + "help.txt";
	infile.open(filename);
	if(!infile.is_open()){
		mvprintw(0,0,"ERROR: Could not open %s", filename.c_str());
		getch();
	}
	while(infile.get(ch))
		help.push_back(ch);
	infile.close();
	
	filename = dir + "focus.txt";
	infile.open(filename);
	if(!infile.is_open()){
		mvprintw(0,0,"ERROR: Could not open %s", filename.c_str());
		getch();
	}
	while(infile.get(ch))
		focus.push_back(ch);
	infile.close();

	filename = dir + "credits.txt";
	infile.open(filename);
	if(!infile.is_open()){
		mvprintw(0,0,"ERROR: Could not open %s", filename.c_str());
		getch();
	}
	while(infile.get(ch))
		credits.push_back(ch);
	infile.close();

	filename = dir + "bestScore.txt";
	infile.open(filename);
	if(!infile.is_open()){
		mvprintw(0,0,"ERROR: Could not open %s", filename.c_str());
		getch();
	}
	while(infile.get(ch))
		bestScore.push_back(ch);
	infile.close();
	
	filename = dir + "currScore.txt";
	infile.open(filename);
	if(!infile.is_open()){
		mvprintw(0,0,"ERROR: Could not open %s", filename.c_str());
		getch();
	}
	while(infile.get(ch))
		currScore.push_back(ch);
	infile.close();
	
	filename = dir + "ready.txt";
	infile.open(filename);
	if(!infile.is_open()){
		mvprintw(0,0,"ERROR: Could not open %s", filename.c_str());
		getch();
	}
	while(infile.get(ch))
		ready.push_back(ch);
	infile.close();	
}

vector<char> Message::getMessage(string msgName){
	if(msgName == "recall") 		return recall;
	else if(msgName == "confirm") 	return confirm;
	else if(msgName == "help") 		return help;
	else if(msgName == "focus") 	return focus;
	else if(msgName == "credits") 	return credits;
	else if(msgName == "bestScore") return bestScore;
	else if(msgName == "currScore") return currScore;
	else if(msgName == "ready")		return ready;
	else if(msgName == "focus")		return focus;
	else 							return confirm; 
}
