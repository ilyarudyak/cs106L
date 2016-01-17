#include <iostream>
#include <set>
#include <fstream>
using namespace std;

void read_file(set<int> &s, string f);
void print_set(set<int> &s);
set<int> intersect(set<int> &s, set<int> &s2);

int main(int argc, const char * argv[]) {
    
    set<int> s, s2, si;
    read_file(s, "set.txt");
    read_file(s2, "set2.txt");
    si = intersect(s, s2);
    print_set(si);
    return 0;
}

set<int> intersect(set<int> &s, set<int> &s2) {
    
    set<int> si;
    for(auto it = s.cbegin(); it != s.cend(); it++) {
        if (s2.count(*it)) {
            si.insert(*it);
        }
    }
    return si;
}

void read_file(set<int> &s, string f) {
    
    ifstream infile(f.c_str());
    int n;
    while (infile >> n) {
        s.insert(n);
    }
    infile.close();
}

void print_set(set<int> &s) {
    
    cout << "[";
    for(auto it = s.cbegin(); it != s.cend(); it++) {
        if (it != --s.cend()) {
            cout << *it << ", ";
        } else {
            cout << *it;
        }
        
    }
    cout << "]" << endl;
}

























