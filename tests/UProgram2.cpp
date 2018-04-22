//compilation:
//g++ -std=c++17 *.cpp -DBOOST_TEST_DYN_LINK -lboost_system -lboost_unit_test_framework -o UProgram1
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE TestPrograms  
#include <boost/test/unit_test.hpp>
#include <iostream>
#include "../include/Program2.h"

using namespace std;

//Program 02
BOOST_AUTO_TEST_CASE(test_total_on_a_checkerboard_method_b){
    vector<float> checkerboard(64);
    float expected = 1.84467441e+19;
    BOOST_CHECK_EQUAL(method_b(checkerboard),expected);
}

BOOST_AUTO_TEST_CASE(test_two){
    //vector<float> checkerboard(16);
    //float expected = 1.84467441e+19;
    //BOOST_CHECK_EQUAL(method_a(checkerboard),expected);
}

