#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

string nato_spelling(string);

string nato_spelling(string word){
    string nato[26] = {"Alfa", "Bravo", "Charlie", "Delta", "Echo", "Foxtrot", "Golf",
                     "Hotel", "India", "Juliett", "Kilo", "Lima", "Mike", "November",
                     "Oscar", "Papa", "Quebec", "Romeo", "Sierra", "Tango", "Uniform",
                     "Victor", "Whiskey", "X-ray", "Yankee", "Zulu"};

    char letter;
    string convert;
    int count = 0;
    int size = word.length();
    for(int i = 0; i < size; i++){
        letter = word[i]; // get string of word break into character;
        letter = :: toupper(letter); // convert Word toUPPERCASE
        for(int j = 0; j < 26; j ++){
        if(letter == nato[j][0]){
            convert += nato[j];
            count ++;
            if(count > 0 && count < size){ // print , in the line and if it's the last one do not print ","
            convert += ", ";
            }
        }
        }
    }

  return convert;
}