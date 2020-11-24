//
// Created by seanj on 11/23/2020.
//

#include <iostream>
#include "tour_manager.hpp"

void tour_manager::setElite() {
    elite = tours[0];
    for (tour t: tours) {
        if (t.getFitness() < elite.getFitness()){
            elite = tour(t);
        }
    }
}

tour_manager::tour_manager() {
    tours.push_back(tour(num_cities));
    for (int i = 1; i < num_tours; ++i){
        tours.push_back(tour(tours[0].getCities()));
    }
    sort(tours.begin(), tours.end());
    setElite();
}

void tour_manager::display() {
    for (tour t: tours) {
        t.display();
    }
    cout << tours.size() << endl;
}

void tour_manager::displayElite() {
    elite.display();
}

void tour_manager::generate() {
    tours[0] = tours[tours.size() - 1];
    tours.pop_back();
    vector<tour> children;
    children.push_back(elite);
    for (int i = 0; i < tours.size(); i++) {
        shuffle(tours.begin(),tours.end(),rng);
        children.push_back(get_child());
    }
    tours = children;
    sort(tours.begin(), tours.end());
    elite = tours.front();
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


