#include "Palindrome.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

bool isNotAlpha(char ch) {
    return !isalpha(ch);
}
bool isNotAlphaOrSpace(char ch) {
    return !isalpha(ch) && !isspace(ch);
}

Palindrome::Palindrome(string filename) {

    ifstream in(filename);
    getline(in, text);

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
bool Palindrome::isWordPalindrome() {
    string textCopy = text;

    // remove punctuation
    textCopy.erase(remove_if(textCopy.begin(), textCopy.end(),
                             isNotAlphaOrSpace), textCopy.end());

    // transform to upper case
    transform(textCopy.begin(), textCopy.end(), textCopy.begin(), ::toupper);

    // break up the input into a list of words
    stringstream tokenizer(textCopy);
    vector<string> tokens;
    tokens.insert(tokens.begin(),
                  istream_iterator<string>(tokenizer),
                  istream_iterator<string>());

    return equal(tokens.begin(), tokens.begin() + tokens.size() / 2,
                 tokens.rbegin());
}














