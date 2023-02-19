
CXX = g++
CFLAGS = -Wall



all: main test output input
	@cat ./test_out

debug:  CFLAGS+= -g
debug: main test output input
	@cat ./test_out

main : main.cpp
	@$(CC) $(CFLAGS) -o main main.cpp
test : test.cpp
	@$(CC) $(CFLAGS) -o test test.cpp
output: main
	@./main > ./out
input: test
	@./test < ./out > ./test_out
clean:
	@rm -f main test out test_out
