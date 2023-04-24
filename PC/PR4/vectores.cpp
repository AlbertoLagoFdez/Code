#include <iostream>
#include <vector>

using namespace std;
int main() 
{
  int maxdim = 40;
  vector<int> V[maxdim];
  for(int i = 0; i < maxdim; i++)
  {
    V[i]; 
  }

  cout << "el vector es" << endl;
  cout << "[ ";
  for(int i = 0; i < maxdim;i++)
  {
    cout << V.at(i) << " "; 
  }
  cout << "]";
}