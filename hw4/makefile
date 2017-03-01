# "nq" means "n-queens"; "ts" means "test stack"
all: nq ts

# ... your makefile code to make an executable "ts" (for "test stack")
ts: Stack.h Stack.template	testStack.cxx
	g++ -Wall -g -o ts testStack.cxx

# ... your makefile code to make an executable "nq" (for "n queens")
nq: Stack.h Stack.template queens.cxx
	g++ -Wall -g -o nq queens.cxx

clean:
	rm -f *.o nq ts
