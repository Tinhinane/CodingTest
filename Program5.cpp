#include "include/Program5.h"

using namespace std;
using Matrix = vector<vector<int>>;//define a new type for matrices

/**
    Find the cell with the minimum number of stones, from the set of cells not
    yet visited  

    @param dist contains the minimum number of stones to go from source to vertex i 
    @param is_visited contains whether vertex i is included in shortest path tree
    @return index of the cell having the minimum number of stones
*/
int find_min_distance(int dist[], bool is_visited[], int V){

	int min = INT_MAX;// Initialize min to infinity (maximum int)
	int min_index;
  
    //Find the unvisited cell with the least number of stones
	for (int v = 0; v < V; v++)
		if (is_visited[v] == false && dist[v] <= min)
			min = dist[v], min_index = v;
  
	return min_index;
}

/**
    Generates a matrix n*m of integers (10<val<50)  

    @param  size of n, m
    @return matrix size n*m
*/
const Matrix get_matrix(int n, int m){
    vector<int> v(n);
    Matrix matrix(m, v);
    random_device rd;
    uniform_int_distribution<int> dist(10, 50);
    for(int i = 0; i<m; i++){
        for(int j = 0; j<n; j++){
            matrix[i][j] = dist(rd);
        }
    }
    return matrix;
}

/**
    Prints a matrix n*m of integers (10<i<50)  

    @param  size of n, m
    @return 
*/
void print_matrix(const Matrix& matrix){
    
    int m= matrix.size();
    int n= matrix[0].size();
    for(int i = 0; i<m; i++){
        for(int j = 0; j<n; j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << flush;
}

/**
    Finds the shortest path from a source to a target in a maze (2D matrix) by
    implementing Dijkstra's algorithm.

    @param Matrix representation of the maze.
    @param source 
    @return Minimum value of stones that was collected to get to the target
*/
int shortest_path(const Matrix& matrix, int src){

	/*
        Part 1: Transform the matrix to a graph of vertices, and assign weights
        to edges. 
    */
    int ROW=matrix.size();
    int COL=matrix[0].size();
    int V=COL*ROW;
	int graph[V][V];
	//Initialization; assuming vertices are not connected to one another, assign 0
	for(int i = 0; i < V; i++){
		for(int j = 0; j < V; j++)
			graph[i][j] = 0;
	}	
    //Fill in the graph (edge weights); if two cells are adjacent fill in with 
    //the value of 'stones'
	int j1 = 1, j2;
	for(int in = 0; in < V; in++){
		j2 = j1 + (COL - 1);
		if (j1 % (COL) != 0) {
			graph[in][j1] = matrix[in / COL][j1 % (COL)];
			graph[j1][in] = matrix[in / COL][j1 % (COL)];
		}
		if (j2 < V) {
			graph[in][j2] = matrix[j2 / COL][j2 % COL];
			graph[j2][in] = matrix[j2 / COL][j2 % COL];
		}
		j1++;
	}
	//Fill in for the first and last cell
	graph[0][0] = matrix[0][0];
	graph[V - 1][V - 1] = matrix[ROW - 1][COL - 1];
	
	
	/*
        Part 2: Calculate the shortest path from the source to the target 
        in the graph
    */
	int dist[V]; 
	bool is_visited[V]; 

	for (int i = 0; i < V; i++)
		dist[i] = INT_MAX, is_visited[i] = false;

	//Distance of source vertex from itself is the number of stones of the first cell
	dist[src] = graph[0][0];

	//Find least number of stones path for all vertices
	for(int count=0; count<V-1; count++){
		//Get the index of the cell with the minimum number of stones from the cells that were not
		//visited yet. u is always equal to the first cell in the first iteration.
		int u = find_min_distance(dist, is_visited, V);

		is_visited[u] = true;// Save the picked vertex as visited

		//Update dist value of the adjacent cells to the picked cell.
		for(int v=0; v<V; v++){
		    //Update dist[v] only if is not in is_visited, there is a way from
			//u to v (adjacents), and total number of stones from the first cell to v through u is
			//smaller than current value of dist[v]
			bool prd = !is_visited[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v];
			if (prd)
				dist[v] = dist[u] + graph[u][v];
		}	
	}

	return dist[V-1];
}
