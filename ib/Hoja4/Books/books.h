#include <iostream>

#ifndef BOOKS_H
#define BOOKS_H

class Books {
    public:
     Books(std::string Titulo, std::string AñoDePublicacion, float Precio);
     void Print() const;
    private:
     std::string Titulo_{};
     std::string AñoDePublicacion_{};
     float Precio_{};
};

#endif