#include <iostream>
#include "Palindrome.h"
using namespace std;

int main() {
    Palindrome p("long_text.txt");
    cout << p.getText() << endl;;
    cout << "is palindrome:" << p.isPalindrome2() << endl;
    return 0;
}