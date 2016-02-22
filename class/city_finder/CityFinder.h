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
    typedef map<double, string> CoordMap;
    typedef pair<string, CityLocation> City;

    CityFinder() = default;
    CityFinder(string filename, string city);

    // rough conversion from miles
    // to latitude/longitude degrees.
    const double kDegreesPerMile = 1.0 / 69.172;

    double distance(City other);
    void findNearbyCities(double radius);

    // getters
    const CityMap &getCityLookup() const {
        return cityLookup;
    }
    const City &getCity() const {
        return centerCity;
    }
    const CoordMap &getLatLookup() const {
        return latLookup;
    }
    const CoordMap &getLonLookup() const {
        return lonLookup;
    }

private:

    City centerCity;
    CityMap cityLookup;
    CoordMap latLookup;
    CoordMap lonLookup;

    // helper functions
    void loadData(string);
    CityLocation makeCityLocation(string);
    void populateLookupTables();
};


#endif //CITY_FINDER_CITYFINDER_H

































