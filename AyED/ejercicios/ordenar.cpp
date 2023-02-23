#include <iostream>

void ordenarvector(int *v, int tam) 
{
    for (int i = 0;i < tam; i++) 
    {
        for (int j = i + 1;j < tam; j++) 
        {
            if (v[j]<v[i]) 
            {
                int aux = v[i];     // 
                v[i] = v[j];        //SWAP
                v[j] = aux;         //
            }
        }
    }
}

int main() 
{
    int v[] = { 4, 3, 5, 3, 7, 2, -2, -12, 4, 34, 4};
    const int tam = 11;
    ordenarvector(v , tam);  
    for(int i = 0; i < 11;i++)
    {
        std::cout << v[i] << " ";
    }  
    std::cout << "\n";
    return 0; 
}