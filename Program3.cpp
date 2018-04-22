#include "include/Program3.h"

using namespace std;

/**
    Utility function to check whether a string is a chain of decimal digit 
    characters; using isdigit library function.  

    @param string representation of a digit.
    @return true if the string is a representation of a digit, else false.
*/
bool is_digit(const string& s){
    string::const_iterator it = s.begin();//get an iterator on the string
    
    //continue as long as iterator didn't reach the end of the string
    //and isdigit is true
    while (it != s.end() && isdigit(*it))  
        ++it;
    return it==s.end();//return true if iterator reached the end
}

/**
    Utility function to check whether a string of length more than one have 
    a leading zero.  

    @param string representation of a digit.
    @return true if the string has a leading zero digit character
*/
bool is_leading_zero(const string& s){
    if(s.length()>1 && s[0]=='0'){
        return true;
    }
    return false;
}

/**
    Tokenize a string IPv4 address with respect to a dot delimiter.  

    @param string representation of a IPv4 address.
    @return address bytes in a vector of strings 
*/
vector<string> tokenize_ip(string ip_address){
    vector<string> bytes;
   	stringstream verif(ip_address);
	string byte;	
	//Assuming a dot-decimal notation, tokenize with respect to '.' 
	while(getline(verif, byte, '.'))
	{
		bytes.push_back(byte);
	}
	return bytes;
}

/**
    Checks whether an IPv4 address is valid.  

    @param string representation of a IPv4 address.
    @return true if valid IPv4 address, else false
*/
bool is_valid_ip(string ip){

    /*
        Part 1: split the ip address string with respect to a delimiter 
        and save the tokens in an vector of strings.
    */
    vector<string> bytes=tokenize_ip(ip);//save the 4 bytes of the address as strings

    /*
        Part 2: check validity; rules taken into account: 
        4 bytes, no leading zero (eg.01), only digits, 0<=digits<=255 
    */
    if(bytes.size() != 4)
        return false;
    for (string byte: bytes){
        bool prd= !is_digit(byte) || is_leading_zero(byte) || stoi(byte)>255 || stoi(byte)<0;
        if(prd)
            return false;
    }
    return true;
}
