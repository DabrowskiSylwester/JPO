#include <iostream>
#include <cstdlib>
#include <ctime>

int main(){
	srand(static_cast<unsigned int>(time(0)));
	int randNum = rand() % 100 + 1;
	
	int userNum{};
	std::cout << "Enter a number: ";
	do{
		std::cin >> userNum;
		if( userNum < randNum){
			std::cout << "Your number is too low." << std::endl;
		} else if(userNum > randNum){
			std::cout << "Your number is too high." << std::endl;	
		}
	}while( userNum != randNum);
	std::cout<< "Your number is correct." << std::endl;
	return 0;
}