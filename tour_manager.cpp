//
// Created by seanj on 11/23/2020.
//

#include <iostream>
#include "tour_manager.hpp"

// Sets the fastest tour in current population if it is faster than the current elite.
void tour_manager::setElite() {
    if (tours[0].getFitness() < elite.getFitness()){
        elite = tours[0];
    }
}

// Base constructor
tour_manager::tour_manager() {
    make_tours();
}

// Helper method for printing generations to console, unused in final exe
void tour_manager::display() {
    for (tour t: tours) {
        t.display();
    }
}

// Generates a new set of children by crossing random parents
// Sets them as the new population, mutates them, sorts new population.
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

// creates a new tour from a pool of parents
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

// Mutates every tour in the population
void tour_manager::mutate() {
    for (int i = 0; i < tours.size(); i++){
        tours[i].mutate(mutation_rate);
    }
}

tour_manager::tour_manager(int cities, int tours, int iterations, double improvement, double mutation):
num_cities(cities), num_tours(tours), iterations(iterations), target_improvement(improvement), mutation_rate(mutation){
    make_tours();
}

//builds the initial population from the parameters set in the constructor
void tour_manager::make_tours() {
    srand(time(NULL));
    for (int i = 0; i < num_cities; i++) {
        cities.push_back(new city());
    }
    for (int i = 0; i < num_tours; ++i){
        tours.push_back(tour(cities));
    }
    sort(tours.begin(), tours.end());
    elite = tours[0];
    base_tour = tours[0];
    base_fitness = elite.getFitness();
}

// Runs the algorithm and prints to the console
void tour_manager::run() {
    int generation = 0;
    double gen_improvement = 0;
    string bar = "==============================================================\n";
    while (generation < iterations && gen_improvement < target_improvement ) {
        gen_improvement = (base_fitness - tours[0].getFitness()) / base_fitness;
        cout << bar;
        cout << "Generation #" << generation++ << "\nBest Distance: " << elite.getFitness() << endl;
        cout << "Distance this gen: " << tours[0].getFitness() << "\nImprovement this gen: " << gen_improvement << endl;
        cout << bar;
        generate();
    }
    cout << bar <<"REPORT for " << elite.getCities().size() << " cities with a tour population of "
                                                                    << tours.size() << " tours.\n";
    cout << "Iterations: " << iterations << " Mutation rate: " << mutation_rate << endl;
    cout << bar <<  "Base Distance: " << base_fitness << "\nBest Distance: " << elite.getFitness() << endl;
    cout << "Base route: ";
    base_tour.display();
    cout << "\nBest route: ";
    elite.display();
    cout << "\nImprovement of " << ((base_fitness - elite.getFitness()) / base_fitness) << endl;
    if (gen_improvement >= target_improvement){
        cout << "ACHIEVED Target improvement of " << target_improvement << " in " << --generation << " generations.\n";
    } else {
        cout << "Unable to hit target improvement of " << target_improvement << " in " << --generation << " generations.\n";
    }
}

//clean up mem leaks
tour_manager::~tour_manager() {
    for (city * c: cities){
        delete c;
    }
}




