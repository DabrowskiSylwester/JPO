#include <iostream>
#include <string>

using std::cout, std::cin, std::endl, std::string;

int main()
{
    string sentence {};
    char character {};
    cout << "Insert a sentence: ";
    std::getline(cin, sentence); //getline is required to read ' ' correctly
    cout << "Insert a character: ";
    cin >> character;

    //Providing case-insensitive counter by converting given character to lower case:
    character = std::tolower(character);
    

    //Finding a occurance number of character in sentence:
    int occurance{};
    for (auto ch : sentence)
    {

        ch = std::tolower(ch);
    
        if ( ch == character)
        {
            occurance++;
        }
    }

    //Results:
    cout << "The character '" << character << "' occurs " << occurance << " times in your sentence." << endl;
}