CXX = /usr/bin/g++
CXXFLAGS = -ansi -pedantic -Wall -Werror -std=c++14
RM = /bin/rm

qtest: FORCE
	$(CXX) $(CXXFLAGS) -o qtest myqueue.cpp qtest.cpp
	$(CXX) $(CXXFLAGS) -o chexa chexa.cpp
	$(CXX) $(CXXFLAGS) -o windback windback.cpp
	$(CXX) $(CXXFLAGS) -o lastint lastint.cpp

clean: FORCE
	$(RM) -rf qtest *.o
	$(RM) -rf chexa *.o
	$(RM) -rf windback *.o
	$(RM) -rf lastint *.o
	
FORCE:
