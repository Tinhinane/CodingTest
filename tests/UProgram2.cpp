//compilation:
//g++ -std=c++17 *.cpp -DBOOST_TEST_DYN_LINK -lboost_system -lboost_unit_test_framework -o UProgram2
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE TestPrograms  
#include <boost/test/unit_test.hpp>
#include <iostream>
#include "../include/Program2.h"

using namespace std;

BOOST_AUTO_TEST_CASE(test_total_on_a_checkerboard_method_b){
    vector<float> checkerboard(64);
    float expected = 1.84467441e+19;
    BOOST_CHECK_EQUAL(method_b(checkerboard),expected);
}

BOOST_AUTO_TEST_CASE(test_five_by_five_checkerboard){
    vector<float> checkerboard(25);
    float expected = 33554432;
    BOOST_CHECK_EQUAL(method_b(checkerboard),expected);
}

BOOST_AUTO_TEST_CASE(test_non_natural_number_size){
    vector<float> checkerboard(25.5);//will be casted to 25
    float expected = 33554432;
    BOOST_CHECK_EQUAL(method_b(checkerboard), expected);
}
