#include <iostream>
#include "Hangman.h"

using namespace std;

void printVector(vector<string> words) {
    copy(words.begin(), words.end(), ostream_iterator<string>(cout, " "));
}

int main() {

    Hangman hangman("small_dict.txt");
    hangman.play();
//    printVector(hangman.getWordList());

    return 0;
}