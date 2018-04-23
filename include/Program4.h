#include <limits.h>
#include <iostream>
#include <vector>
#include <array>

const int ROW = 3;
const int COL = 5;
const int V = 15;

/**
    Coding Test
    Program4.cpp
    Purpose: Calculates the minimum value of tokens that can be collected
    going from the first matrix element to the last one. 

    @author Tinhinane Ait Hamouda
    @version 1.0 21/04/18 
*/

int find_min_distance(int dist[], bool is_visited[]);
int shortest_path(const std::vector<std::vector<int>>& matrix, int src);
const std::array<std::array<int, V>, V> matrix_to_graph(const std::vector<std::vector<int>>& matrix);
bool check_size(std::vector<std::vector<int>> matrix);
