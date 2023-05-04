CXX = /usr/bin/g++
CXXFLAGS = -Wall -Werror -ansi -pedantic -std=c++14
RM = /bin/rm

replace: FORCE
	$(CXX) $(CXXFLAGS) -o wc wc.cpp

clean: FORCE
	$(RM) -rf wc *.o
	
FORCE: