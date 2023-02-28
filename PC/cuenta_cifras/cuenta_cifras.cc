#include <iostream>
using namespace std;

int main() 
{
    int x, c;
    int cuenta = 0;
    while (true) 
    {
        cout << "Introduzca un numero entero positivo (introduzca negativo para finalizar el programa): ";
        cin >> x;
        if (x < 0) break;
        cout << "Introduzca la cifra (0-9, introduzca otra cosa para finalizar el programa): ";
        cin >> c;
        if ((c < 0) || (c > 9)) break;
        cuenta = 0;
        int resto;
        while (x != 0)
        {
            resto = x % 10;
            x /= 10;
            if ( resto == c ) cuenta++;
        }
    cout << "El numero de veces que aparece la cifra en el numero es: " << cuenta << endl;
    }
    cout << "Fin del programa.\n";
    return 0;
}