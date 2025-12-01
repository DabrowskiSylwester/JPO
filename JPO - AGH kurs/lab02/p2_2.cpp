#include <iostream>
#include <string>
#include <algorithm> //std::reverse


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

int main()
{
    //input string:
    string input_str {};
    cout << "Insert a string: ";
    cin >> input_str;

    cout << "Your string: " << input_str << endl;

    //My reverse function:
    cout << "\nMy string reverse function: " << endl;
    string my_rev_str {};
    my_rev_str = my_reverse( input_str);
    cout << "Reversed string: " << my_rev_str << endl;

    //std::reverse():
    cout << "\nReverse function: " << endl;
    string rev_str = input_str;
    reverse(rev_str.begin(), rev_str.end());
    cout << "Reversed string: " << rev_str << endl;

}