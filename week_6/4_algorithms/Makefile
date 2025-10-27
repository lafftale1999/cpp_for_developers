PROG = main.exe 							# Target file for executable
SRC = main.cpp ../classes/movie.cpp ../classes/movies.cpp				# Source code files (when creating more source code files, you will need to add them here).
CFLAGS = -g -std=c++17 -Wall -Werror		# Compile flags - instructions to the compiler (warnings, optimization, version etc)
LIBS = 										# Specific libraries
CC=g++										# Compiler to be used

all: $(PROG)								# Defining standard behaviour to be - build the PROG executable

$(PROG): $(SRC)								# TARGET : DEPENDENCIES | If one of the dependencies is newer than the target, compile again
	$(CC) -o $@ $(CFLAGS) $(SRC) $(LIBS)	
	
clean: 										# Defining clean command - remove the executable
	rm -f $(PROG)

