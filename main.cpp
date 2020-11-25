#include <iostream>
#include "city.hpp"
#include "tour.hpp"
#include "tour_manager.hpp"

void display_cities(vector<city *> c){
    for (auto i = 0; i < c.size(); i++){
        cout << c[i]->getName() << " X: " << c[i]->getX() << " Y: " << c[i]->getY() << endl;
    }
}
int main() {
    srand(time(NULL));
    int gen = 0;
    tour_manager tm;
    for (int i = 0; i < 1000; ++i){
        cout << "Generation " << gen++ << endl;
        tm.display();
        tm.generate();
    }
    return 0;
}
