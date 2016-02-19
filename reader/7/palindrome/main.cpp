#include <iostream>
#include "Palindrome.h"
using namespace std;

int main() {
    Palindrome p("word_text2.txt");
    cout << p.getText() << endl;;
    cout << p.isWordPalindrome() << endl;
    return 0;
}