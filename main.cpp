#include <iostream>
#include "city.hpp"
int main() {
    char c = 'A';
    for (auto i = 0; i < 100; i++){
        city c;
        cout << c.getName() << " X: " << c.getX() << " Y: " << c.getY() << endl;
    }
    return 0;
}
