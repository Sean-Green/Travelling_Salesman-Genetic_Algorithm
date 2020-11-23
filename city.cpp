//
// Created by seanj on 11/23/2020.
//
#include <iostream>
#include "city.hpp"

int city::getX() const {
    return x;
}

void city::setX(int x) {
    city::x = x;
}

int city::getY() const {
    return y;
}

void city::setY(int y) {
    city::y = y;
}

const string &city::getName() const {
    return name;
}

void city::setName(const string &name) {
    city::name = name;
}

double city::getDistance(const city &c) {
    double xDis = (double) this->x - c.getX();
    cout << " xd " << xDis << endl;
    double yDis = (double) this->y - c.getY();
    cout << " yd " << yDis << endl;
    xDis = xDis * xDis;
    cout << " xd " << xDis << endl;
    yDis = yDis * yDis;
    cout << " yd " << yDis << endl;
    return sqrt((xDis + yDis));
}


