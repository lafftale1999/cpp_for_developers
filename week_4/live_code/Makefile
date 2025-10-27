# Setting up our compiler flags and destinations
PROG   = main.exe
CC     = g++
CFLAGS = -g -std=c++17
LIBS   =

# Setting up the src and object paths
ROOT_SRC = $(wildcard *.cpp)               		# points to all .cpp files in our root folder
SRC      = $(ROOT_SRC) $(wildcard src/*.cpp)	# points to all .cpp files in our src folder

ROOT_OBJ = $(patsubst %.cpp,      obj/%.o,      $(ROOT_SRC))			# points to all .o files in obj/
SRC_OBJ  = $(patsubst src/%.cpp,  obj/src/%.o,  $(wildcard src/*.cpp))	# points to all .o files in obj/src/
OBJ      = $(ROOT_OBJ) $(SRC_OBJ)

# Make sure the commands 'all' and 'clean' runs properly
# even if you included a file with the same name
.PHONY: all clean

# --- default target ---
all: $(PROG)

# --- link ---
# Explains to the compiler that all .o files in these
# directories will build the PROG (.exe file)
$(PROG): $(OBJ)
	$(CC) -o $@ $(OBJ) $(LIBS)

# --- compile (root .cpp -> obj/*.o) ---
# Can be transalated to:
# for every .cpp file in root/, build the responding .o file in obj/.
# First make sure directory obj/ exists and then compile.
obj/%.o: %.cpp | obj
	$(CC) $(CFLAGS) -c $< -o $@

# --- compile (src/*.cpp -> obj/src/*.o) ---
# Can be transalated to:
# for every .cpp file in src/, build the responding .o file in obj/src/.
# First make sure directory obj/src/ exists and then compile.
obj/src/%.o: src/%.cpp | obj/src
	$(CC) $(CFLAGS) -c $< -o $@

# --- ensure folders exist ---
obj:
	mkdir obj
obj/src:
	mkdir obj\src

# --- clean ---
clean:
	rm -f $(PROG) obj/*.o obj/src/*.o