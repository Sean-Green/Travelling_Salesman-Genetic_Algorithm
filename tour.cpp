//
// Created by seanj on 11/23/2020.
//

#include <iostream>
#include <stdlib.h>
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

const vector<city *> &tour::getCities() const {
    return cities;
}

void tour::setCities(const vector<city *> &cities) {
    tour::cities = cities;
    calcFitness();
}

tour::tour() {

}

double tour::getFitness() const {
    return fitness;
}

bool tour::operator<(const tour &t) {
    return fitness < t.getFitness();
}

// can't do this in the destructor, because every tour is looking at the same set of cities, must be called before
// deleting the last tour reference
void tour::deleteCities() {
    for (city * c: cities){
        delete c;
    }
}

// Helper method for displaying city order and tour fitness
void tour::display() {
    cout << "|";
    for (city * c: cities){
        cout << c->getIdNum() << "|";
    }
    cout << "Fitness " << fitness << endl;
}

tour tour::operator+(tour &t) {

    vector<city *> child_route;

    int index = rand() % cities.size();

    for (int i = 0; i < index; ++i){
        child_route.push_back(cities[i]);
    }

    for (int i = 0; i < t.cities.size(); ++i){
        bool duplicate_flag = false;
        for (int j = 0; !duplicate_flag && j < child_route.size(); ++j){
            if (child_route[j] == t.cities[i]) {
                duplicate_flag = true;
            }
        }
        if (!duplicate_flag){
            child_route.push_back(t.cities[i]);
        }
    }
    tour child;
    child.setCities(child_route);
    return child;
}

void tour::mutate() {
    city *temp;
    for (int i = 0; i < cities.size() - 1; ++i){
        int n = rand() % 100;
        if ( n <= 15 ){
            temp = cities[i];
            cities[i] = cities[i+1];
            cities[i+1] = temp;
        }
    }
    calcFitness();
}


