#include <iostream>
#include <string>
#include <cctype>
#include <cstring>

using namespace std;

bool ispalindrome(const string&);

int main()
{
    if (ispalindrome("noon"))
        cout << "PASSED - \"noon\" is a palindrome\n";
    else
        cout << "FAILED - \"noon\" is a palindrome\n";

    if (!ispalindrome("                 norton"))
        cout << "PASSED - \"                 norton\" is not a palindrome\n";
    else
        cout << "FAILED - \"                 norton\" is not a palindrome\n";

    if (ispalindrome("level"))
        cout << "PASSED - \"level\" is a palindrome\n";
    else
        cout << "FAILED - \"level\" is a palindrome\n";

    if (ispalindrome("     noon     "))
        cout << "PASSED - \"     noon     \" is a palindrome\n";
    else
        cout << "FAILED - \"     noon     \" is a palindrome\n";

    if (ispalindrome("taco cat"))
        cout << "PASSED - \"taco cat\" is a palindrome\n";
    else
        cout << "FAILED - \"taco cat\" is a palindrome\n";

    if (!ispalindrome("taco rat"))
        cout << "PASSED - \"taco rat\" is not a palindrome\n";
    else
        cout << "FAILED - \"taco rat\" is not a palindrome\n";

    if (ispalindrome("A man, a plan, a canal... Panama!"))
        cout << "PASSED - \"A man, a plan, a canal... Panama!\" is a palindrome\n";
    else
        cout << "FAILED - \"A man, a plan, a canal... Panama!\" is a palindrome\n";

    return 0;
}
bool ispalindrome(const string& word){
    string new_word = word;
    string  palindrome = "";
    //reverse(palindrome.begin(), palindrome.end());
    int size = word.length();
    cout << "word size: " << size << endl;
    // for(int i = 0; i < size; i++){
    //     if(isalpha(word[i])){
    //         palindrome[i] = word[i];
    //     }else{
    //         continue;
    //     }
    // }
    // reverse(palindrome.begin(), palindrome.end());

    int index = 0;
    int j = 0;
    while(j < size){
        if(isalpha(word[j])){
            new_word[index] = word[j];
            index++;
        }
        j++;
    }

    for(int i = index - 1; i >= 0; i--){
        cout << "i:"<< i << endl;
        palindrome[i] = new_word[i];
    }

    if(palindrome != new_word){
        return false; 
    }
    return true;
}