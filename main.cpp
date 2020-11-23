#include <iostream>
#include "city.hpp"
#include "tour.hpp"

void display_cities(vector<city *> c){
    for (auto i = 0; i < c.size(); i++){
        cout << c[i]->getName() << " X: " << c[i]->getX() << " Y: " << c[i]->getY() << endl;
    }
}
int main() {
    tour t(2);
    display_cities(t.getCities());
    tour t2(t.getCities());
    display_cities(t2.getCities());
    cout << t.getFitness();
    return 0;
}
