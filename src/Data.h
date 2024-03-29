//
// Created by afdom on 18/12/2023.
//

#include "graph.h"
#include <set>
#include <fstream>
#include <sstream>
#include <string>
#include "Airline.h"
#include "Airport.h"
#include "unordered_map"


#ifndef GRAPHPROJECT_DATA_H
#define GRAPHPROJECT_DATA_H
/**
 * @class Data
 * @brief Represents the data that was parsed from the csv files.
 */
using namespace std;
class Data {
    private:
        Graph<Airport> ap;
        std::unordered_map<string,Airline> airlines;
        std::unordered_map<string,Vertex<Airport>*> airports;
        std::unordered_map<string,Vertex<Airport>*> airports_names;
        std::unordered_map<string,set<string>> city_by_country;
    public:
        void parse_airports();
        Graph<Airport> getAP();
        void parse_flights();
        void parse_airlines();
        unordered_map<string, Airline> getAirlines();
        unordered_map<string, Vertex<Airport>*> getAirports();
        unordered_map<string,Vertex<Airport>*> getAirportsName();
        void calculate_indegree();
        unordered_map<string,set<string>> getCity_by_country();
};


#endif //GRAPHPROJECT_DATA_H
