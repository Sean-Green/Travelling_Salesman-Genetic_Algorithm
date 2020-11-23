//
// Created by seanj on 11/23/2020.
//
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


