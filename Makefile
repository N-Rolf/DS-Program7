# target            - output - highest priority
# prerequisites     - monitor changes to HashTest.o Stack.o
# command           - link object files (.o files)
#                   - generate executable named output
output: HashTest.o HashPython.o
	g++ -o output HashTest.o HashPython.o

# target            - HashTest.o
# prerequisites     - monitor changes to HashTest.cpp
# command           - generate HashTest.o
HashTest.o: HashTest.cpp
	g++ -c HashTest.cpp

# target            - Stack.o
# prerequisites     - monitor changes to Stack.cpp, Stack.h
# command           - generate Stack.o
BST.o: HashPython.h HashPython.cpp
	g++ -c HashPython.cpp

# target            - clean
# prerequisites     - none
# command           - remove .o files and executable
# command line      - make clean
clean:
	rm output HashTest.o HashPython.o