TARGET = a.out #recall 
CXXFLAGS = -Wall -std=C++11 -Wc++11-extensions -lncurses
CC = g++

OBJFILES = main.o Screen.o Digits.o Message.o

$(TARGET): $(OBJFILES)
	$(CC) -o $(TARGET) $(CXXFLAGS) $(OBJFILES)

main.o: main.cpp
	$(CC) -c main.cpp
Screen.o: Screen.cpp Screen.h
	$(CC) -c Screen.cpp
Digits.o: Digits.cpp Digits.h
	$(CC) -c Digits.cpp
Message.o: Message.cpp Message.h
	$(CC) -c Message.cpp

.PHONY: clean
clean:
	rm $(OBJFILES) $(TARGET)
