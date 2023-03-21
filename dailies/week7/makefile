CXX = /usr/bin/g++
CXXFLAGS = -Wall -Werror -ansi -pedantic -std=c++14
RM = /bin/rm

rtod: FORCE
	$(CXX) $(CXXFLAGS) -o rtod rtod.cpp
	$(CXX) $(CXXFLAGS) -o nato nato.cpp
	$(CXX) $(CXXFLAGS) -o rotate rotate.cpp

clean: FORCE
	$(RM) -rf rtod *.o
	$(RM) -rf nato *.o
	$(RM) -rf rotate *.o
	$(RM) -rf replace *.o
	
FORCE: