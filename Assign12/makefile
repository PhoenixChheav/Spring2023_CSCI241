#
# PROGRAM:    Assignment 12
# PROGRAMMER: Phoenix Chheav and Sam Normoyle
# LOGON ID:   Z1966108) and Z1980761
# DATE DUE:   5/4/2023
#
#compiler variable
CXX = g++
CXXFLAGS = -Wall -Werror -ansi -pedantic -std=c++14 

assign12: assign12.o shape.o circle.o triangle.o rectangle.o
	$(CXX) $(CXXFLAGS) -o assign12 $^


assign12.o: assign12.cpp circle.h shape.h triangle.h rectangle.h
shape.o: shape.cpp shape.h
circle.o: circle.cpp circle.h
triangle.o: triangle.cpp triangle.h
rectangle.o: rectangle.cpp rectangle.h

circle.h: shape.h
triangle.h: shape.h
rectangle.h: shape.h

clean:
	rm -f assign12 *.o