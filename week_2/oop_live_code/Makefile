PROG = main.exe
SRC = main.cpp Bus.cpp Student.cpp
CFLAGS = -g -std=c++17 -Wall -Werror
LIBS = 
CC = g++

all: $(PROG)

$(PROG) : $(SRC)
	$(CC) -o $@ $(CFLAGS) $(SRC) $(LIBS)

clean:
	rm -f $(PROG)