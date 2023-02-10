#include "books.h"

Books::Books(std::string Titulo, std::string AñoDePublicacion, float Precio) : Titulo_{Titulo}, AñoDePublicacion_{AñoDePublicacion}, Precio_{Precio} {}

void Books::Print() const {
    std::cout << Titulo_ << ", " << AñoDePublicacion_ << ", " << Precio_ << ", " << Precio_*1.60 << ":" << std::endl;
};  
