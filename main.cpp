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
    tour_manager tm;
//    tm.displayElite();
    tm.display();
    int id = 1;
    for (int i = 0; i < 1000; ++i){
        cout << endl << "Generating<<" << id++ << "\n" << endl;
        tm.generate();
        tm.display();
    }
    return 0;
}
