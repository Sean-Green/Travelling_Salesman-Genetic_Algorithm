//
// Created by seanj on 11/23/2020.
//

#include "tour.hpp"

tour::tour(int num_cities) {
    for (int i = 0; i < num_cities; i++) {
        cities.push_back(new city());
    }
}

tour::tour(vector<city *> city_v) {
    for (city* c: city_v){
        cities.push_back(c);
    }
    sort(cities.begin(), cities.end());
    shuffle(cities.begin(), cities.end(), rng);
}

tour::~tour() {
    for (city* c: cities){
        delete c;
    }
}

const vector<city *> &tour::getCities() const {
    return cities;
}

void tour::setCities(const vector<city *> &cities) {
    tour::cities = cities;
}

