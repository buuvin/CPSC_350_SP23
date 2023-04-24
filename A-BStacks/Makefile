


#change this to the current assignment
EXECUTABLE := mygenstacak

# teh source files to be built
SOURCES := *.cpp

#stuff dont need to worry about
INCLUDES := -I ../includes
EXT: out
CC := g++


all:
	$(CC) $(INCLUDES) $(SOURCES) -o $(EXECUTABLE).$(EXT)

realclean:
	find . -type f -name "*.o" -exec rm '{}' \;
	find . -type f -name "*.exe" -exec rm '{}' \;
	find . -type f -name "*.out" -exec rm '{}' \;

#this line required by make - dont delete