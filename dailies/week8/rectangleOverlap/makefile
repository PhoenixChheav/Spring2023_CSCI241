CXX = /usr/bin/g++
CXXFLAGS = -Wall -Werror -ansi -pedantic -std=c++14
RM = /bin/rm

overlap: FORCE
	$(CXX) $(CXXFLAGS) -o overlap overlap.cpp

clean: FORCE
	$(RM) -rf overlap *.o
	
FORCE: