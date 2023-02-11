#include <iostream>
#include <random>
 
int main()
{
    std::random_device rd;  // Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); // Standard mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<> distrib(1, 2);
 
    // Use distrib to transform the random unsigned int
    // generated by gen into an int in [1, 6]
    for (int n = 0; n != 10; ++n)
        std::cout << distrib(gen) << ' ';
    std::cout << '\n';
}