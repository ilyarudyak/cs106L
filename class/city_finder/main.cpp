#include <iostream>
#include "CityFinder.h"
using namespace std;

void printMap(const CityFinder::CityMap & cityMap) {
    for (auto city : cityMap) {
        cout << city.first << " "
             << city.second.lat << " "
             << city.second.lon << endl;
    }
}

int main() {
    CityFinder finder("place_data_small.txt");
    printMap(finder.getCityLookup());
    return 0;
}