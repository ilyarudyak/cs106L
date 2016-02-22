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

    const int kWordSize = 4;
    const int kNumberGuesses = 5;

    typedef map<string, vector<string>> WordMap;
    typedef vector<string> WordVector;

    Hangman() = default;
    Hangman(string filename);

    void play();

    // getters
    const WordVector &getWordList() const {
        return wordList;
    }

private:

    WordMap wordFamilies;
    WordVector wordList;
    string wordPattern;

    // helper functions
    void loadWords(string filename);
    void updateWords(char letter);
    string buildPattern(string word, char letter);
    const string toLower(string word);
    void printVector(WordVector words);
    void updatePattern(string pattern);
};


#endif //ASS2_HANGMAN_HANGMAN_H






























