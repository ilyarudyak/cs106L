#include <iostream>
#include "Palindrome.h"
using namespace std;

int main() {
    Palindrome p("text.txt");
    cout << p.getText() << " is palindrome:";
    cout << p.isPalindrome() << endl;
    return 0;
}