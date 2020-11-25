//
// Created by seanj on 11/23/2020.
//

#include <iostream>
#include "tour_manager.hpp"

void tour_manager::setElite() {
    if (tours[0].getFitness() < elite.getFitness()){
        elite = tours[0];
    }
}

tour_manager::tour_manager() {
    for (int i = 0; i < num_cities; i++) {
        cities.push_back(new city());
    }
    for (int i = 0; i < num_tours; ++i){
        tours.push_back(tour(cities));
    }
    sort(tours.begin(), tours.end());
    elite = tours[0];
}

void tour_manager::display() {
    for (tour t: tours) {
        t.display();
    }
}

void tour_manager::displayElite() {
    elite.display();
}

void tour_manager::generate() {
    setElite();
    tours[0] = tours[tours.size() - 1];
    tours.pop_back();
    vector<tour> children;
    children.push_back(elite);
    for (int i = 0; i < tours.size(); i++) {
        shuffle(tours.begin(),tours.end(),rng);
        children.push_back(get_child());
    }
    tours = children;
    mutate();
    sort(tours.begin(), tours.end());
}

tour tour_manager::get_child() {
    vector<tour> pg1;
    vector<tour> pg2;
    int i = 0;
    while (i < 10){
        pg1.push_back(tours[i++]);
        pg2.push_back(tours[i++]);
    }
    sort(pg1.begin(), pg1.end());
    sort(pg2.begin(), pg2.end());
    return pg1[0] + pg2[0];
}

void tour_manager::mutate() {
    for (int i = 0; i < tours.size(); i++){
        tours[i].mutate();
    }
}

void tour_manager::run(int cities, int tours, int iterations, double improvement) {
    num_cities = cities;
    num_tours = tours;
    int generations = 0;
    while (generations < iterations) {

    }
}



