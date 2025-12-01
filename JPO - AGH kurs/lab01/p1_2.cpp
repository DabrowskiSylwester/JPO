#include <iostream>

int main(){
	int arr[5]{};
	std::cout << "Enter 5 numbers" << std::endl;
	for( int i=0; i<5; i++){
		std::cin >> arr[i];
	}
	std::cout << "Your numbers: " << std::endl;
	for( int i=0; i<5; i++){
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
	return 0;
}