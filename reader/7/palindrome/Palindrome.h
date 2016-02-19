#ifndef PALINDROME_PALINDROME_H
#define PALINDROME_PALINDROME_H

#include <string>
using namespace std;

class Palindrome {

public:
    Palindrome() = default;
    Palindrome(string filename);
    bool isPalindrome();


    const string &getText() const {
        return text;
    }

private:
    string text;

};


#endif //PALINDROME_PALINDROME_H
