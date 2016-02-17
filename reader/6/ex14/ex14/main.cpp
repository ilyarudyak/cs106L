#include <iostream>
#include <map>
#include <set>
#include <fstream>
using namespace std;

void read_file(map<string, string> &m);
void print_map(map<string, string> &m);
int duplicates(map<string, string> &m);


int main(int argc, const char * argv[]) {

    map<string, string> m;
    read_file(m);
    print_map(m);
    cout << "duplicates=" << duplicates(m) << endl;
    return 0;
}

void read_file(map<string, string> &m) {
    
    ifstream infile("map.txt");
    string a, b;
    while (infile >> a >> b) {
        m.insert(make_pair(a, b));
    }
    infile.close();
}

void print_map(map<string, string> &m) {
    
    cout << "[";
    for(auto it = m.cbegin(); it != m.cend(); it++) {
        if (it != --m.cend()) {
            cout << it->first << ":" << it->second << ", ";
        } else {
            cout << it->first << ":" << it->second;
        }
        
    }
    cout << "]" << endl;
}

/* the number of key/value pairs in the map with the same value */
int duplicates(map<string, string> &m) {
    
    set<string> values;
    int count = 0;
    for(auto it = m.cbegin(); it != m.cend(); it++) {
        if (values.count(it->second)) {
            count++;
        } else {
            values.insert(it->second);
        }
    }
    return count;
}
















