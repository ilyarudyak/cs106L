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

    CityFinder finder("place_data_small.txt", "Akron, AL");

    finder.findNearbyCities(1.0);

//    for (auto e : finder.getLonLookup()) {
//        cout << e.first << " " << e.second << endl;
//    }

    for (auto city : finder.getCityLookup()) {
        cout << city.first << ":" << finder.distance(city) << endl;
    }

//    printMap(finder.getCityLookup());
//    cout << endl;
//    cout << finder.getCity().first << " "
//    << finder.getCity().second.lat << " "
//    << finder.getCity().second.lon << endl;

    return 0;
}