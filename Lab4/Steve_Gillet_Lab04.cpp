#include <iostream>
#include <string>
using namespace std;

void palindrome(string str)                         //problem 1
{
    string strCopy, strReverse;
    string :: iterator it;
    string :: reverse_iterator itR;
    for(it = str.begin(); it != str.end(); it++)
    {
        if(*it != ' ')
        {
        strCopy.push_back(*it);
        }
    }
    cout << strCopy << endl; 
    for(itR = strCopy.rbegin(); itR != strCopy.rend(); itR++)
    {
        strReverse.push_back(*itR);
    }
    if(strCopy == strReverse)
    {
        cout << strReverse << endl;
        cout << "The string is a palindrome." << endl;
    }
    else
    {
        cout << strReverse << endl;
    }
}

void tokenize()                                 //problem 2
{
    string strIP, strToken = "{";    
    string :: iterator it;
    cout << "Input an IP to tokenize: " << endl;
    getline(cin, strIP);
    
    for(it = strIP.begin(); it != strIP.end(); it++)
    {
        if(*it != '.')
        {
            strToken.push_back(*it);
        }
        else
        {
            strToken.push_back(',');
            strToken.push_back(' ');
        }
    }
    strToken.push_back('}');
    cout << strToken;
}

int main()
{
    string str;    
    cout << "Input a string to test if it's a palindrome: " << endl;
    getline(cin, str);
    palindrome(str);
    tokenize();
}
