cmake_minimum_required(VERSION 3.17)
project(GeneticAlgorithm)

set(CMAKE_CXX_STANDARD 14)

add_executable(GeneticAlgorithm main.cpp city.hpp city.cpp tour.cpp tour.hpp tour_manager.cpp tour_manager.hpp)