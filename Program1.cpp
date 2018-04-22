/**
    Coding Test
    Program1.cpp
    Purpose: Calculates the total of tokens on an 8×8 checkerboard (method a)

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
double method_a(vector<double>& checkerboard){

    checkerboard[0]=1;//Populate the first element of the vector
    double prev=checkerboard[0];//Save the previous element in the vector
    double sum=checkerboard[0];//Initialize the total of tokens on the checkerboard
    
    /***
    For each element of vector from checkerboard[1] till the end apply the 
    lambda function. The vector stores a geometric sequence, with:
    checkerboard(0)=1 and checkerboard(n+1)=checkerboard(n)*2 
    ***/
    for_each (checkerboard.begin()+1, checkerboard.end(), [&prev, &sum](double &val){
        prev=prev*2;//update val
        val=prev;//populate the vector element
        sum=sum+prev;//calculate the sum up to this point in the vector
    });
    
    /***
    Method A can also be implemented without creating a vector; meaning just 
    going through a loop from 0 to 64 and then perform the same calculations 
    inside our lambda function, but it is nice to have a vector to represent
    the checkerboard and doublecheck that it corresponds to the specifications
    ***/
    //display_checkerboard(checkerboard);
    return sum;
    
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

/**
    prints the checkerboard 

    @param checkerboard as a vector of doubles.
    @return 
*/
void display_checkerboard(const vector<double>& checkerboard){  
    int count=0;
    int row=0;
    while(row < 8){
        for(int i=0;i<8;i++){
            cout << checkerboard[count] << " ";
            count++;
        }
        cout << endl;
        ++row;
    }
    cout << flush;
}

int main(){
  int size=64;
  vector<double> checkerboard(size);//Vector of size 64 to represent an 8×8 checkerboard
  double total = method_a(checkerboard);
  cout << "The sum is: " << total << " (" << to_decimal(total) << ")" <<endl;
  //display_checkerboard(checkerboard);
  return 0;
}
