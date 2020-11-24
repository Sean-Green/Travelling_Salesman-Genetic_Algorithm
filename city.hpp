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
    int idNum;
    string name;
public:
    city():x(rand()%COORD_RANGE), y(rand()%COORD_RANGE), idNum(id++), name("City " + to_string(this->idNum)){}
    int getX() const;
    void setX(int x);
    int getY() const;
    void setY(int y);
    const string &getName() const;
    void setName(const string &name);
    double getDistance(const city &c);

    int getIdNum() const;
};

#endif //GENETICALGORITHM_CITY_HPP
