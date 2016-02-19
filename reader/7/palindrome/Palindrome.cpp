#include "Palindrome.h"
#include <fstream>

bool isNotAlpha(char ch) {
    return !isalpha(ch);
}

Palindrome::Palindrome(string filename) {

    ifstream in(filename);
    string s;
    while (in >> s) {
        text += s;
    }

}

bool Palindrome::isPalindrome() {
    string reversed = text;
    reverse(reversed.begin(), reversed.end());
    return reversed == text;
}
bool Palindrome::isPalindrome2() {
    string textCopy = text;
    textCopy.erase(remove_if(textCopy.begin(), textCopy.end(),
                             isNotAlpha), textCopy.end());
    transform(textCopy.begin(), textCopy.end(), textCopy.begin(), ::toupper);
    return equal(textCopy.begin(), textCopy.begin() + textCopy.size() / 2,
                 textCopy.rbegin());
}


bool Palindrome::isWordpalindrome() {
    return false;
}
