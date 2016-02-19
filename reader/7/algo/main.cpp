#include <iostream>
#include <numeric>
#include <fstream>
#include <set>
#include <algorithm>
#include <vector>
#include <string>
#include <iterator>
using namespace std;

struct placeT {
    int x;
    int y; };
template <typename T>
void printVector(vector<T> v) {
    copy(v.begin(), v.end(), ostream_iterator<T>(cout, " "));
//    for (auto e : v) {
//        cout << e << " ";
//    }
//    cout << endl;
}
template <typename T>
void printSet(set<T> s) {
    copy(s.begin(), s.end(), ostream_iterator<T>(cout, ", "));
}
void computeAverage() {

    ifstream input("data.txt");
    multiset<int> values;

    // read the data from the file
    int currValue;
    while (input >> currValue)
        values.insert(currValue);

    // compute the average
    cout << accumulate(values.begin(), values.end(), 0.0) / values.size()
        << endl;
}
void sortVector() {

    ifstream input("data.txt");
    vector<int> values;

    // read the data from the file
    int currValue;
    while (input >> currValue)
        values.push_back(currValue);

    sort(values.begin(), values.end());

    for (auto v : values) {
        cout << v << " ";
    }
    cout << endl;
}
bool comparePlaces(placeT one, placeT two) {
    if(one.x != two.x)
        return one.x < two.x;
    return one.y < two.y;
}
string placeToString(placeT place) {
    string s = "(";
    return s + to_string(place.x) + ", " + to_string(place.y) + ")";
}
void sortPlaces() {

    ifstream input("data2.txt");
    vector<placeT> values;

    // read the data from the file
    int x, y;
    placeT place;
    while (input >> x >> y) {
        place.x = x;
        place.y = y;
        values.push_back(place);
    }

    sort(values.begin(), values.end(), comparePlaces);

    for (auto place : values) {
        cout << placeToString(place) + " ";
    }
    cout << endl;
}
bool compareStringLength(string one, string two) {
    return one.length() < two.length();
}
void sortStrings() {

    ifstream in("data3.txt");
    vector<string> values;

    string value;
    while (in >> value) {
        values.push_back(value);
    }

    sort(values.begin(), values.end(), compareStringLength);

    for (auto value : values) {
        cout << value << " ";
    }
    cout << endl;
}
void rotateVector() {
    vector<int> v = {1, 2, 3, 4, 5};
    rotate(v.begin(), v.begin() + 3, v.end());
    printVector(v);
}
void shuffleVector() {
    vector<int> v = {1, 2, 3, 4, 5};

    random_shuffle(v.begin(), v.end());
    printVector(v);
}
void backIterator() {

    vector<int> v;

    // this iterator will insert values into v
    back_insert_iterator< vector<int> > back_it(v);
    for (int i = 0; i < 10; ++i) {

        // implicit call to v.push_back(i)
        *back_it = i;

        ++back_it;
    }

    printVector(v);
}
void copyVector() {
    vector<int> original = {1, 2, 3, 4, 5};
    vector<int> destination;
    copy(original.begin(), original.end(), back_inserter(destination));
    printVector(destination);
}
void setUnion() {

    set<int> set1 = {1, 2, 3};
    set<int> set2 = {4, 5};
    set<int> setUnion;
    set_union(set1.begin(), set1.end(),
              set2.begin(), set2.end(),
              inserter(setUnion, setUnion.begin()));
    printSet(setUnion);

}


int main() {

    setUnion();
    return 0;
}





































