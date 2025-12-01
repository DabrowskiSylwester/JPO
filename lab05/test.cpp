#include <iostream>
#include <vector>

int main(){
    std::vector<int> v1 {1, 2, 3, 4};
    std::vector<int> v2 {1, 2, 3, 4};
    std::vector<int> v3 {30, 40, 50};
    std::cout << "v1 equals v2: " << (v1 == v2) << std::endl;
    std::cout << "v1 equals v3: " << (v1 == v3) << std::endl;
}