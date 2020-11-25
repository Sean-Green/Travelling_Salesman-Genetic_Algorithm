#include <iostream>
#include "city.hpp"
#include "tour.hpp"
#include "tour_manager.hpp"

void getInt(int& i){
    cout << "Enter an int:" << endl;
    cin >> i;
    if (cin.fail()){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Not an int, try again\n";
        getInt(i);
    }
}

void getDouble(double& d){
    cout << "Enter a percentage amount as < 1 (ie: .50 = 50%):" << endl;
    cin >> d;
    if (cin.fail()){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Not a number, try again\n";
        getDouble(d);
    }
}

int main() {
    cout << "Traveling Salesman: Genetic Algorithm\nSet number of cities to visit.\n";
    int cities = 32;
    getInt(cities);
    cout << "Set population of tours:\n";
    int tours = 32;
    getInt(tours);
    cout << "Set number of iterations to generate:\n";
    int iterations = 1000;
    getInt(iterations);
    cout << "Set a target improvement percent as a decimal less than 1:\n";
    double improvement = .50;
    getDouble(improvement);
    cout << "Set a mutation rate as a decimal less than 1:\n";
    double mutation = .15;
    getDouble(mutation);
    tour_manager tm(cities, tours, iterations, improvement, mutation);
    tm.run();
    return 0;
}

