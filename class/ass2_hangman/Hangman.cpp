//
// Created by Ilya Rudyak on 2/22/16.
//

#include <stdlib.h>
#include <iostream>
#include "Hangman.h"

Hangman::Hangman(string filename) {
    srand ((unsigned int) time(NULL));
    loadWords(filename);
    for (int i = 0; i < kWordLength; ++i) {
        wordPattern += "-";
    }
}
void Hangman::play() {

    char guess;
    for (int i = 0; i < kNumberGuesses; ++i) {
        cout << wordPattern << endl;
        cout << "enter a symbol: ";
        cin >> guess;
        updateWords((char) tolower(guess));
    }
}

// helper functions
void Hangman::loadWords(string filename) {
    //TODO implement
}
void Hangman::updateWords(char letter) {

    string maxPattern;
    int maxLength = 0;
    for (string word : wordList) {
        string pattern = buildPattern(word, letter);

        // add word to word families
        wordFamilies[pattern].push_back(word);

        // check if this is max family
        WordVector words = wordFamilies[pattern];
        if (words.size() > maxLength) {
            maxLength = (int) words.size();
            maxPattern = pattern;
        }
    }

    // update word list
    wordList = wordFamilies[maxPattern];

    // update word pattern
    wordPattern = maxPattern;

}
string Hangman::buildPattern(string basic_string, char letter) {
    //TODO implement
}















