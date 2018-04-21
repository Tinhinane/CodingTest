/**
    Coding Test
    Program2.cpp
    Purpose: Calculates the total of tokens on an 8×8 checkerboard (method b)

    @author Tinhinane Ait Hamouda
    @version 1.0 21/04/18 
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <sstream>

using namespace std;

/**
    Calculates total number of tokens on a checkerboard 

    @param checkerboard as a vector of doubles.
    @return total number of tokens as a double.
*/
double method_b(vector<double>& checkerboard){
    //Sum of a finite number of terms (checkerboard size), such as 1 + 2 + 4 +...
    //The mathematical formula for such a sum is: 2^(k+1) -1
    //The advantage of method B over method A is that there is not need to populate the sequence
    return pow(2, checkerboard.size())-1;
}

/**
    Encodes the total number of tokens in fixed-point notation 

    @param sum as a double in scientific-notation.
    @return string representation of the sum in fixed-point notation.
*/
string to_decimal(const double& sum){
    ostringstream ss;
    ss.precision(1);
    ss << fixed << sum;//write sum value in fixed-point notation.
    return ss.str();
}

int main() {
  int size=64;
  vector<double> checkerboard(size);//Vector of size 64 to represent an 8×8 checkerboard
  double total = method_b(checkerboard);
  cout << "The sum is: " << total << " (" << to_decimal(total) << ")" <<endl;
  //display_checkerboard(checkerboard);
  return 0;
}
