#include <iostream>

using namespace std;

/****************************************
**Name:reverse
**Description: reverse a string from the user
****************************************/
string reverse(string s)
{
    
    string reverseString = "";
    
    if (str.length() <= 1)
    {
        return str;
    }

    string copy = str;
    int n = copy.length() - 1;

    string first = copy.substr(0, 1);

    copy = copy.substr(1, n);

    reverseString += reverse(copy);
    reverseString += first;

    return reverseString;
}

