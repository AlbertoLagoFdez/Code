#include <iostream>

using namespace std;

int main()
{
  // m: filas, n: columnas
  const int m = 2, n = 3;
  
  int *M = new int [m * n];
  for (int i = 0; i < m * n; i++)
    M[i] = (i + 1) * 10;

  //        0   1   2   3   4   5
  // M = { 10, 20, 30, 40, 50, 60 }
  // pero realmente queremos tratar a M como:
  //            1   2   3
  // M = { 1: { 10, 20, 30 },
  //       2: { 40, 50, 60 } }
  // ...
  //        0   1   2   3   4   5
  // M = { 10, 20, 30, 40, 50, 60 }
  // pero realmente queremos tratar a M como:
  //            1   2   3
  // M = { 1: { 10, 20, 30 },
  //       2: { 40, 50, 60 } }

  // M se puede indexar con fila i y columna j usando:
  // pos = (i - 1) * n + (j - 1);
  
  int i = 1, j = 2, pos = (i - 1) * n + (j - 1);
  cout << "M[" << i << "," << j << "] = M[" << pos << "] = " << M[pos]
       << endl; // M[1,2] = M[1] = 20

  i = 2, j = 3, pos = (i - 1) * n + (j - 1);
  cout << "M[" << i << "," << j << "] = M[" << pos << "] = " << M[pos]
       << endl; // M[2,3] = M[5] = 60
  
  delete[] M;
}
