//
// Created by seanj on 11/23/2020.
//

#ifndef GENETICALGORITHM_CITY_HPP
#define GENETICALGORITHM_CITY_HPP
#include <random>
#include <string>
using namespace std;
static int COORD_RANGE = 1000;
static int id = 0;
struct city {
private:
    int x;
    int y;
    string name;
public:
    city():x(rand()%COORD_RANGE), y(rand()%COORD_RANGE), name("City " + to_string(id++)){}
    int getX() const;
    void setX(int x);
    int getY() const;
    void setY(int y);
    const string &getName() const;
    void setName(const string &name);
};

#endif //GENETICALGORITHM_CITY_HPP
