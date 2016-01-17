#include <iostream>
#include <set>
#include <fstream>
using namespace std;

void readFile(set<string> &words, istream &in);
void printSet(set<string> &words);
void findPrefix(set<string> &words, string &prefix);

int main(int argc, const char * argv[]) {
    
    set<string> words;
    ifstream in("prefixes.txt");
    readFile(words, in);
//    printSet(words);

    string prefix = "abid";
    findPrefix(words, prefix);
    
    return 0;
}

void findPrefix(set<string> &words, string &prefix) {
    
    set<string>::iterator start = words.lower_bound(prefix);
    for(set<string>::iterator it = start; it != words.end(); ++it) {
        if (it->find(prefix) != string::npos) {
            cout << *it << " " << endl;
        }
    }
}

void readFile(set<string> &words, istream &in) {
    
    string line;
    while (in >> line) {
        words.insert(line);
    }
}

void printSet(set<string> &words) {
    
    for (auto s: words) {
        cout << s << endl;
    }
}


























