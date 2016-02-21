//
// Created by Ilya Rudyak on 2/20/16.
//

#include "DFA.h"
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;

DFA::DFA(string filename) {
    read(filename);
}
void DFA::read(string filename) {

    ifstream in(filename);
    string line;

    // read start state
    getline(in, line);
    stringstream sin(line);
    sin >> startState;

    // read accepting states
    int state;
    getline(in, line);
    stringstream sin2(line);
    while (sin2 >> state) {
        acceptingStates.insert(state);
    }

    // read transitions table
    int state1, state2;
    while (getline(in, line)) {
        stringstream sin3(line);
        sin3 >> state1;
        for (int i = 0; i < alphabet.size(); ++i) {
            sin3 >> state2;
            transitions[make_pair(state1, i)] = state2;
        }
    }
}
bool DFA::simulateDFA(string input) {
    int currState = startState;
    for (char ch : input) {
        cout << currState << " -> ";
        int i = ch - '0';
        currState = transitions[make_pair(currState, i)];
    }
    cout << currState << endl;
    return acceptingStates.find(currState) != acceptingStates.end();
}
