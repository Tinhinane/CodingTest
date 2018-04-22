#include "include/Program2.h"

using namespace std;

/**
    Calculates total number of tokens on a checkerboard 

    @param checkerboard as a vector of doubles.
    @return total number of tokens as a double.
*/
float method_b(vector<float>& checkerboard){
    //Sum of a finite number of terms (checkerboard size), such as 1 + 2 + 4 +...
    //The mathematical formula for such a sum is: 2^(k+1) -1
    //The advantage of method B over method A is that there is not need to populate the sequence
    return pow(2, checkerboard.size())-1;
}

