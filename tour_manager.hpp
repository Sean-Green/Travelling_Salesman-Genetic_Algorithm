//
// Created by seanj on 11/23/2020.
//

#ifndef GENETICALGORITHM_TOUR_MANAGER_PP
#define GENETICALGORITHM_TOUR_MANAGER_PP


#include "tour.hpp"

class tour_manager {

private:
    int num_cities = 32;
    int num_tours = 32;
    vector<tour> tours;
    tour elite;
    void setElite();
public:
    tour_manager();
    void display();
    void displayElite();
    void generate();

    tour get_child();
};


#endif //GENETICALGORITHM_TOUR_MANAGER_PP
