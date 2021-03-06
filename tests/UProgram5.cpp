//compilation:
//g++ -std=c++17 *.cpp -DBOOST_TEST_DYN_LINK -lboost_system -lboost_unit_test_framework -o UProgram5
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE TestPrograms  
#include <boost/test/unit_test.hpp>
#include <iostream>
#include "../include/Program5.h"

using namespace std;
using Matrix = vector<vector<int>>;

BOOST_AUTO_TEST_CASE(test_example_matrix){

	Matrix example_matrix = {{1, 2, 2, 5, 4},
					         {8, 1, 3, 5, 7},
					         {2, 8, 4, 1, 8}};
					         
	BOOST_CHECK_EQUAL(shortest_path(example_matrix, 0), 20);
}

BOOST_AUTO_TEST_CASE(test_bigger_matrix){

	Matrix test_matrix_b = {{1, 2, 2, 5, 4, 1},
					        {8, 1, 3, 5, 7, 3},
					        {2, 8, 4, 1, 8, 2},
					        {5, 3, 1, 7, 8, 9}};
					        
    BOOST_CHECK_EQUAL(shortest_path(test_matrix_b, 0), 29);   
}

BOOST_AUTO_TEST_CASE(test_matrices_generation){
    
    int n=2;
    int m=2;
    Matrix expected(2, vector<int>(2));
    Matrix actual = get_matrix(n,m);
    BOOST_CHECK_EQUAL(typeid(actual).name(), typeid(expected).name());//check if correct datatype returned 
    BOOST_CHECK_EQUAL(actual.size(), 2);
    BOOST_CHECK_EQUAL(actual[0].size(), 2);
    		        
}

BOOST_AUTO_TEST_CASE(test_min){
   
    int dist[] = {1,2,3,4,5};  
    bool is_visited[] = {true,false,true,false,true};
    int V = 5;
    int actual = find_min_distance(dist, is_visited, V);

    BOOST_CHECK_EQUAL(actual, 1);		        
}
