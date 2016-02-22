//
// Created by Ilya Rudyak on 2/22/16.
//

#ifndef ASS2_HANGMAN_HANGMAN_H
#define ASS2_HANGMAN_HANGMAN_H

#include <string>
#include <map>
#include <vector>
using namespace std;

class Hangman {

public:

    const int kWordLength = 4;
    const int kNumberGuesses = 5;

    typedef map<string, vector<string>> WordMap;
    typedef vector<string> WordVector;

    Hangman() = default;
    Hangman(string filename);

    void play();


private:

    WordMap wordFamilies;
    WordVector wordList;
    string wordPattern;

    // helper functions
    void loadWords(string filename);
    void updateWords(char letter);
    string buildPattern(string word, char letter);
};


#endif //ASS2_HANGMAN_HANGMAN_H






























