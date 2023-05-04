#include <iostream>
#include <string>
#include <cctype>
#include <fstream>

using namespace std;

int wc(const string& file_name, int& lines, int& words, int& characters){
    ifstream file(file_name);
    if(!file){
        return false;//if file not open
    }

    lines = words = characters = 0;
    bool word = false;
    char c;
    while(file.get(c)){
        ++characters;
        if(c == '\n'){ // count lines
            ++lines;
        }
        if(isspace(c)){ //count words
            word = false;
        }else {
            if(!word){
                ++words;
                word = true;
            }
        }
    }
    if(word){//if it is word, increment word count
        ++words;
    }

    return true;
}

int main()
{
    int l, w, c;
    string name;

    for (int i = 1; i <= 8; i++)
    {
        l = w = c = -1;
        name = "in" + to_string(i) + ".txt";
        
        if (wc(name, l, w, c))
        {
            cout << name << ": lines = " << l
                 << ", words = " << w
                 << ", characters = " << c << endl;
        }
        else
            cout << "Unable to open " << name << endl;
    }
    
    return 0;
}
