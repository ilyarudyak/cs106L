#include "Palindrome.h"
#include <fstream>

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
































