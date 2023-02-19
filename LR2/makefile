
CXX = g++
CFLAGS = -Wall

all: part1 part2
	@echo Done

debug:  CFLAGS+= -g
debug: part1 part2
	@echo Done
part1 : part1.cpp
	@$(CC) $(CFLAGS) -o part1 part1.cpp
part2 : part2.cpp
	@$(CC) $(CFLAGS) -o part2 part2.cpp
clean:
	@rm -f part1 part2
