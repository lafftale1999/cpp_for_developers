PROG = main.exe
SRC = main.cpp exercise1.cpp
CFLAGS = -g -std=c++17 -Wall -Werror
LIBS = 
CC = g++

all: $(PROG)

$(PROG) : $(SRC)
	$(CC) -o $@ $(CFLAGS) $(SRC) $(LIBS)

clean:
	rm -f $(PROG)