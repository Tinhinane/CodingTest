//compilation:
//g++ -std=c++17 *.cpp -DBOOST_TEST_DYN_LINK -lboost_system -lboost_unit_test_framework -o UProgram1
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE TestPrograms  
#include <boost/test/unit_test.hpp>
#include <iostream>
#include "../include/Program3.h"

using namespace std;

BOOST_AUTO_TEST_CASE(test_ip_address_is_valid)
{
  BOOST_CHECK_EQUAL(is_valid_ip("123.52.1.8"), true);
  BOOST_CHECK_EQUAL(is_valid_ip("255.7.128.10"), true);
}

BOOST_AUTO_TEST_CASE(test_ip_address_too_long)
{
  BOOST_CHECK_EQUAL(is_valid_ip("1.1.1.1.1"), false);
  BOOST_CHECK_EQUAL(is_valid_ip("25.8.0.0.0.15.14"), false);
}

BOOST_AUTO_TEST_CASE(test_ip_address_too_short)
{
  BOOST_CHECK_EQUAL(is_valid_ip("1.1.1"), false);
  BOOST_CHECK_EQUAL(is_valid_ip("128.120"), false);
}

BOOST_AUTO_TEST_CASE(test_ip_address_non_digits)
{
  BOOST_CHECK_EQUAL(is_valid_ip("1.q.0.e"), false);
  BOOST_CHECK_EQUAL(is_valid_ip("abc.d.5.1"), false);
}

BOOST_AUTO_TEST_CASE(test_ip_address_leading_zero)
{
  BOOST_CHECK_EQUAL(is_valid_ip("17.01.15.120"), false);
  BOOST_CHECK_EQUAL(is_valid_ip("005.120.255.1"), false);
}

BOOST_AUTO_TEST_CASE(test_ip_address_out_of_range)
{
  BOOST_CHECK_EQUAL(is_valid_ip("300.8.80.128"), false);
  BOOST_CHECK_EQUAL(is_valid_ip("-1.8.40.258"), false);
}

