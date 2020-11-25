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
    tour_manager tm(32, 32, 1000, .75);
    tm.run();
    return 0;
}
