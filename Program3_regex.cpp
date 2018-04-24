#include "./include/Program3_regex.h"
using namespace std;
bool is_valid_ip(string ip){

     /*RegExpr details:
    Do the following 3 times:
    if character '2' '5', then the next character should be between 0 and 5 (255 maximum)
    if character '2', then next one is beween 0 and 4 and third one is between 0 and 9
    if character '1', then next one is between 0 and 9, and third one is between 0 and 9
    if two characters only, first one is between 1-9 (prevents leading 0) and second one is between 0 and 9.
    if only one character, then it should be between 0-9.
    then delimiter "\."
    Finally, do the same again, but without matching a delimiter at the end
    */
    regex integer("^((25[0-5]|2[0-4][0-9]|1[0-9][0-9]|[1-9]?[0-9])\\.){3}(25[0-5]|2[0-4][0-9]|1[0-9][0-9]|[1-9]?[0-9])$");
 	if(regex_match(ip,integer))
 	    return true;
 	    
 	return false;
}

