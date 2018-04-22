#include <iostream>
#include <string>
#include <vector>
#include <sstream>

/**
    Coding Test
    Program3.cpp
    Purpose: Verify IPv4 addresses (in dotted-decimal notation) validity 

    @author Tinhinane Ait Hamouda
    @version 1.0 21/04/18 
*/

bool is_digit(const std::string& s);
bool is_leading_zero(const std::string& s);
std::vector<std::string> tokenize_ip(std::string ip_address);
bool is_valid_ip(std::string ip);
