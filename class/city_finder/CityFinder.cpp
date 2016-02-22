#include <cmath>
#include <fstream>
#include <sstream>
#include "CityFinder.h"

CityFinder::CityFinder(string filename) {
    loadData(filename);
}

// helper functions
double CityFinder::distance(CityFinder::City& other) {
    double dLat = city.second.lat - other.second.lat;
    double dLong = city.second.lon - other.second.lon;
    return sqrt(dLat * dLat + dLong * dLong);
}
void CityFinder::loadData(string filename) {

    ifstream in(filename);
    string line, line2;
    while (getline(in, line) && getline(in, line2)) {
        cityLookup[line] = makeCityLocation(line2);
    }
}
CityFinder::CityLocation &CityFinder::makeCityLocation(string line2) {
    stringstream sin(line2);
    CityLocation location;
    sin >> location.lat >> location.lon;
    return location;
}
