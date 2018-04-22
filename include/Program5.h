#include <limits.h>
#include <iostream>
#include <vector>
#include <array>
#include <random>

/**
    Coding Test
    Program5.cpp
    Purpose: Calculates the minimum value of tokens that can be collected
    going from the first matrix element to the last one (generic).

    @author Tinhinane Ait Hamouda
    @version 1.0 21/04/18 
*/


int find_min_distance(int dist[], bool is_visited[], int V);
int shortest_path(std::vector<std::vector<int>> matrix, int src);
const std::vector<std::vector<int>> get_matrix(int n, int m);

