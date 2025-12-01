#include <iostream>
#include <algorithm> //std::reverse
#include <string>


using std::cout, std::cin, std::string, std::reverse, std::endl;

string my_reverse(string str)
{
    int length = str.length();
    string bufor (length, ' '); //creating bufor with same legth as str and filled with spaces
    for( int i=0; i<length; i++) //iterator i from 0 to length - 1
    {
        int j = length - i - 1; //iterator j from length - 1 to 0
        bufor[i] = str[j];
    }
    return bufor;
}

bool my_if_palindrom(string str)
{
    //Deleting spaces and adding case-insensivity:
    string str_without_spaces{};
    for (auto ch : str)
    {
        if ( std::isupper(ch))
        {
            ch = std::tolower(ch);
        }
        if (ch != ' ')
        {
            str_without_spaces += ch; 
        }
    }
    //Checing if palindrom
    string rev_str = my_reverse(str_without_spaces);
    if (rev_str == str_without_spaces)
    {
        return true;
    }    
    return false;
} 

bool rev_if_palindrom(string str)
{
    string str_without_spaces{};
    for (auto ch : str)
    {
        if ( std::isupper(ch))
        {
            ch = std::tolower(ch);
        }
        if (ch != ' ')
        {
            str_without_spaces += ch; 
        }
    }
    string rev_str = str_without_spaces;
    reverse(rev_str.begin(), rev_str.end());
    if (rev_str == str_without_spaces)
    {
        return true;
    }    
    return false;

}

int main()
{ 
    //input string:
    string sentence {};
    cout << "Insert a sentence: ";
    std::getline(cin, sentence); ////getline is required to read ' ' correctly

    //My palindrom check function:
    cout << "\nMy palindrom check function: " << endl;
    bool if_pal_my = my_if_palindrom(sentence);
    if (if_pal_my)
    {
        cout << "Your sentence is a palindrom." << endl;
    } else 
    {
        cout << "Your sentence is not a palindrom." << endl;
    }

    //Palindrom check function with reverse():
    cout << "\nPalindrom check function with reverse():" << endl;
    bool if_pal_rev = rev_if_palindrom(sentence);
    if (if_pal_rev)
    {
        cout << "Your sentence is a palindrom." << endl;
    } else 
    {
        cout << "Your sentence is not a palindrom." << endl;
    }
}

/*
Insert a sentence: Si nummi immunis                        

My palindrom check function: 
Your sentence is a palindrom.

Palindrom check function with reverse():
Your sentence is a palindrom.
*/