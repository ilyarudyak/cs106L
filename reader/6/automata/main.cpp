#include <iostream>
#include "DFA.h"

using namespace std;

void printSet(const set<int>& s) {
    for (auto e : s) {
        cout << e << " ";
    }
    cout << endl;
}
void printMap(const map<pair<int, int>, int>& m) {
    for (auto e : m) {
        cout << "(" <<e.first.first << ", " << e.first.second << "):"
             << e.second << " ";
    }
    cout << endl;
}

int main() {

    DFA dfa("dfa.txt");
    string input = "0011";
    cout << dfa.simulateDFA(input) << endl;

//    cout << dfa.getStartState() << endl;
//    printSet(dfa.getAcceptingStates());
//    printMap(dfa.getTransitions());
    return 0;
}