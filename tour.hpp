//
// Created by seanj on 11/23/2020.
//

#ifndef GENETICALGORITHM_TOUR_HPP
#define GENETICALGORITHM_TOUR_HPP

#include <algorithm>
#include <cstdlib>
#include <ctime>
#include "city.hpp"

static auto rng = default_random_engine();
class tour {
private:
    vector<city *> cities;
    double fitness;
    void calcFitness();
public:
    tour();
    tour(int num_cities);
    tour(const vector<city*>& city_v);
    const vector<city *> &getCities() const;
    void setCities(const vector<city *> &cities);
    float getFitness() const;
    bool operator<(const tour& t);
    void deleteCities();
    void display();
    tour operator+(tour& ot);
};


#endif //GENETICALGORITHM_TOUR_HPP
