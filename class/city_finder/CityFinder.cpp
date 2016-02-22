#include <cmath>
#include <fstream>
#include <sstream>
#include <set>
#include <iostream>
#include "CityFinder.h"

CityFinder::CityFinder(string filename, string cityName) {
    loadData(filename);
    populateLookupTables();
    centerCity = *cityLookup.find(cityName);

}
void CityFinder::findNearbyCities(double radius) {

    set<string> citySetRes, citySetInters, citySet1, citySet2;

    double latLowBound   = centerCity.second.lat - radius;
    double latUpperBound = centerCity.second.lat + radius;
    for (auto it  = latLookup.lower_bound(latLowBound);
              it != latLookup.upper_bound(latUpperBound); ++it) {
        citySet1.insert(latLookup[it->first]);
    }

    double lonLowBound   = centerCity.second.lon - radius;
    double lonUpperBound = centerCity.second.lon + radius;
    for (auto it  = lonLookup.lower_bound(lonLowBound);
         it != lonLookup.upper_bound(lonUpperBound); ++it) {
        citySet2.insert(lonLookup[it->first]);
    }

    set_intersection(citySet1.begin(), citySet1.end(),
    citySet2.begin(), citySet2.end(), inserter(citySetInters, citySetInters.end()));

    for (string cityName : citySetInters) {
        City city = make_pair(cityName, cityLookup.find(cityName)->second);
        if (distance(city) <= radius) {
            citySetRes.insert(cityName);
        }
    }

    for (string cityName : citySetRes) {
        cout << cityName << endl;
    }
}
double CityFinder::distance(CityFinder::City other) {
    double dLat = centerCity.second.lat - other.second.lat;
    double dLong = centerCity.second.lon - other.second.lon;
    return sqrt(dLat * dLat + dLong * dLong);
}

// helper functions
void CityFinder::loadData(string filename) {

    ifstream in(filename);
    string line, line2;
    while (getline(in, line) && getline(in, line2)) {
        cityLookup[line] = makeCityLocation(line2);
    }
}
CityFinder::CityLocation CityFinder::makeCityLocation(string line2) {
    stringstream sin(line2);
    CityLocation location;
    sin >> location.lat >> location.lon;
    return location;
}
void CityFinder::populateLookupTables() {
    for (auto city : cityLookup) {
        latLookup[city.second.lat] = city.first;
        lonLookup[city.second.lon] = city.first;
    }
}
