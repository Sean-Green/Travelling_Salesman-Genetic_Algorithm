//
// Created by seanj on 11/23/2020.
//

#include "tour.hpp"

void tour::calcFitness() {
    fitness = 0;
    for (int i = 0; i < cities.size() - 1; ++i){
        fitness += cities[i]->getDistance(*cities[i+1]);
    }
}

tour::tour(int num_cities) {
    for (int i = 0; i < num_cities; i++) {
        cities.push_back(new city());
    }
    calcFitness();
}

tour::tour(const vector<city *>& city_v) {
    for (city* c: city_v){
        cities.push_back(c);
    }
    shuffle(cities.begin(), cities.end(), rng);
    calcFitness();
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
    calcFitness();
}

tour::tour() {

}

float tour::getFitness() {
    return fitness;
}


