//
// Created by Ilya Rudyak on 2/22/16.
//

#include <stdlib.h>
#include <iostream>
#include <fstream>
#include "Hangman.h"

Hangman::Hangman(string filename) {
    srand ((unsigned int) time(NULL));
    loadWords(filename);
    for (int i = 0; i < kWordSize; ++i) {
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
    ifstream in(filename);
    string word;
    while (in >> word) {
        if (word.size() == kWordSize) {
            wordList.push_back(toLower(word));
        }
    }
}
void Hangman::updateWords(char letter) {

    wordFamilies.clear();

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
    updatePattern(maxPattern);

    cout << wordPattern << " ";
    printVector(wordList);
    cout << endl;

}
string Hangman::buildPattern(string word, char letter) {
    string result;
    for (int i = 0; i < word.size(); ++i) {
        if (word[i] == letter) {
            result += letter;
        } else {
            result += '-';
        }
    }
    return result;
}
const string Hangman::toLower(string word) {
    transform(word.begin(), word.end(), word.begin(), ::tolower);
    return word;
}
void Hangman::printVector(Hangman::WordVector words) {
    copy(words.begin(), words.end(), ostream_iterator<string>(cout, " "));
}
void Hangman::updatePattern(string pattern) {
    for (int i = 0; i < kWordSize; ++i) {
        if (pattern[i] != '-') {
            wordPattern[i] = pattern[i];
        }
    }
}














