#include "include/Program1.h"

using namespace std;

/**
    Calculates total number of tokens on a checkerboard 

    @param checkerboard as a vector of doubles.
    @return total number of tokens as a double.
*/
float method_a(vector<float>& checkerboard){

    checkerboard[0]=1;//Populate the first element of the vector
    float prev=checkerboard[0];//Save the previous element in the vector
    float sum=checkerboard[0];//Initialize the total of tokens on the checkerboard
    
    /***
    For each element of vector from checkerboard[1] till the end apply the 
    lambda function. The vector stores a geometric sequence, with:
    checkerboard(0)=1 and checkerboard(n+1)=checkerboard(n)*2 
    ***/
    for_each (checkerboard.begin()+1, checkerboard.end(), [&prev, &sum](float &val){
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
string to_decimal(const float& sum){
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
void display_checkerboard(const vector<float>& checkerboard){  
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

