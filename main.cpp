#include <iostream>
#include "city.hpp"
#include "tour.hpp"

void diplay_cities(vector<city *> c){
    for (auto i = 0; i < c.size(); i++){
        cout << c[i]->getName() << " X: " << c[i]->getX() << " Y: " << c[i]->getY() << endl;
    }
}
int main() {
    tour t(5);
    diplay_cities(t.getCities());
    for (auto i = 0; i < 100; i++){
        tour tempt(t.getCities());
        diplay_cities(tempt.getCities());
    }
    return 0;
}
