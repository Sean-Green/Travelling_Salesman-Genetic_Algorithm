//
// Created by seanj on 11/23/2020.
//

#ifndef GENETICALGORITHM_TOUR_MANAGER_PP
#define GENETICALGORITHM_TOUR_MANAGER_PP


#include "tour.hpp"

class tour_manager {

private:
    int num_cities = 100;
    int num_tours = 32;
    int iterations;
    double base_fitness;
    double target_improvement;
    double mutation_rate;
    vector<city *> cities;
    vector<tour> tours;
    tour elite;
    tour base_tour;
    void make_tours();
    void setElite();
public:
    tour_manager();
    tour_manager(int cities, int tours, int iterations, double improvement, double mutation);
    void display();
    void displayElite();
    void generate();
    tour get_child();
    void mutate();
    void run();
    ~tour_manager();
};


#endif //GENETICALGORITHM_TOUR_MANAGER_PP
