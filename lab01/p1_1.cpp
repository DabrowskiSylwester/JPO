#include <iostream>

int main(){
	int userNum{}, sum{};
	std::cout << "Enter a number: ";
	std::cin >> userNum;
	if ( userNum < 0){
		std::cout << "Your number is negative!" << std::endl;
        return 1;
	}
	for( int i=0; i<=userNum; i++){
		std::cout << i << " ";
		sum += i;
		
	}
	std::cout <<  std::endl << "Sum: " << sum << std::endl;
	return 0;
}