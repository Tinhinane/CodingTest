#include <limits.h>
#include <iostream>
#include <vector>
#include <array>
#define ROW 3
#define COL 5
#define V 15

/**
    Coding Test
    Program4.cpp
    Purpose: Calculates the minimum value of tokens that can be collected
    going from the first matrix element to the last one. 

    @author Tinhinane Ait Hamouda
    @version 1.0 21/04/18 
*/

int find_min_distance(int dist[], bool is_visited[]);
int shorted_path(std::vector<std::vector<int>> matrix, int src);
std::array<std::array<int, V>, V> matrix_to_graph(std::vector<std::vector<int>> matrix);
