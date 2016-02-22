#ifndef CITY_FINDER_CITYFINDER_H
#define CITY_FINDER_CITYFINDER_H

#include <string>
#include <map>
#include <algorithm>
#include <iterator>
using namespace std;

class CityFinder {

public:

    // CityLocation stores latitude and
    // longitude coordinates for a city
    struct CityLocation {
        double lat;
        double lon;
    };

    typedef map<string, CityLocation> CityMap;
    typedef multimap<double, string> CoordMap;
    typedef pair<string, CityLocation> City;

    CityFinder() = default;
    CityFinder(string filename);

    // rough conversion from miles
    // to latitude/longitude degrees.
    const double kDegreesPerMile = 1.0 / 69.172;

    // getters
    const CityMap &getCityLookup() const {
        return cityLookup;
    }

private:

    City city;
    CityMap cityLookup;

    // helper functions
    double distance(City&);
    void loadData(string);
    CityLocation &makeCityLocation(string);
};


#endif //CITY_FINDER_CITYFINDER_H

































