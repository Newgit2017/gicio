#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <time.h>

using namespace std;

const int N = 40;

int main()
{
  int Z[N],i,j,k,x,minZ,minp;

  srand((unsigned)time(NULL));

  // Inicjujemy tablicê Z[]

  for(i = 0; i < N; i++) Z[i] = rand() % 1000;

  // Losujemy k

  k = (rand() % 10) + 1;

  // Wyœwietlamy zawartoœæ Z[]

  for(i = 0; i < N; i++) cout << setw(4) << Z[i];
  cout << endl << endl;

  // Sortujemy Z[]

  for(i = 0; i < N - 1; i++)
  {
    minZ = Z[i];
    minp = i;
    for(j = i + 1; j < N; j++)
      if(Z[j] < minZ)
      {
        minZ = Z[j]; minp = j;
      }
    x = Z[i]; Z[i] = Z[minp]; Z[minp] = x;
  }

  // Wyœwietlamy zawartoœæ Z[]

  for(i = 0; i < N; i++) cout << setw(4) << Z[i];
  cout << endl << endl;

  // Wyœwietlamy k oraz Z[N-k]

  cout << k << " : " << Z[N - k] << endl << endl;
  return 0;
} 