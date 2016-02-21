//
// Created by Ilya Rudyak on 2/20/16.
//

#ifndef AUTOMATA_DFA_H
#define AUTOMATA_DFA_H

#include <map>
#include <set>
#include <string>

using namespace std;

class DFA {

public:

    DFA() = default;
    DFA(string filename);

    bool simulateDFA(string input);

    // getters
    const map<pair<int, int>, int> &getTransitions() const {
        return transitions;
    }
    const set<int> &getAcceptingStates() const {
        return acceptingStates;
    }
    int getStartState() const {
        return startState;
    }

private:

    set<int> alphabet = {0, 1};
    map<pair<int, int>, int> transitions;
    set<int> acceptingStates;
    int startState;

    void read(string filename);

};


#endif //AUTOMATA_DFA_H
