#include <iostream>
#include <vector>
#include <string>

int main() {
    std::vector<std::string> cadena{"Hola", "Mundo", ",", "code", "on", "C++"};
    for(int i{0} ; i < cadena.size() ; i++) {
        std::cout << cadena[i];
    }
    std::cout << std::endl;
    return 0;
}