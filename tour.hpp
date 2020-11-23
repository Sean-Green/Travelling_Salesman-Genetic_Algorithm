//
// Created by seanj on 11/23/2020.
//

#ifndef GENETICALGORITHM_TOUR_HPP
#define GENETICALGORITHM_TOUR_HPP

#include <algorithm>
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
    ~tour();
    const vector<city *> &getCities() const;
    void setCities(const vector<city *> &cities);
    float getFitness();
};


#endif //GENETICALGORITHM_TOUR_HPP
