//*******************************************************************
//
//  solution.cpp
//  CSCI 241
//
// 
//  Leang Y Chheav(Z-ID: Z1966108)
//
//*******************************************************************

#include <iostream>

using namespace std;

int last_index_of(const char*, char);

int last_index_of(const char* s, char c){

    //count character of word
    int i = 0;
    //condition if the s[i] do not encounter the NULL character
    while(s[i] != '\0'){
        i++;
    }

    for(int j = i; j >= 0; j--){

        if(s[j] == c){
            return j;
        }

        //when loop almost end make sure that if every charater in word do not match with c return -1
        if(j == 0 && s[j] != c){
            return -1;
        }
    }

    return 0;
}