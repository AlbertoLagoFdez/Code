#include <iostream>
#include <random>
#include <ctime>

int main() {
    std::srand(std::time(nullptr));
    int RandomVariable = std::rand();
    std::cout << "Random value on [0 " << RAND_MAX << "]: " << RandomVariable << std::endl;
    for (int i{0}; i != 20; i++) {
        int x{7};
        while(x>6){
            x = 1 + std::rand()/((RAND_MAX + 1u)/6);
            std::cout << x << ' ';
        }
    }
    std::cout << std::endl;
    return 0;

}