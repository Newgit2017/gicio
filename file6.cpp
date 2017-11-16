#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <time.h>

using namespace std;

int main()
{
  int **A,**B,n,m,iw,ik;

  srand((unsigned)time(NULL));

  // losujemy wymiary macierzy

  m = rand() % 7 + 2;
  n = rand() % 7 + 2;

  // tworzymy tablicê wskaŸników

   A = new int * [m];
   B = new int * [n];

  // tworzymy tablice wierszy

  for(iw = 0; iw < m; iw++) A[iw] = new int[n];
  for(iw = 0; iw < n; iw++) B[iw] = new int[m];

  // wype³niamy macierz A losowymi liczbami

  for(iw = 0; iw < m; iw++)
    for(ik = 0; ik < n; ik++) A[iw][ik] = rand() % 199 - 99;

  // wyœwietlamy macierz A

  cout << "m = " << m << endl
       << "n = " << n << endl << endl
       << "Matrix A:" << endl;

  for(iw = 0; iw < m; iw++)
  {
    for(ik = 0; ik < n; ik++) cout << setw(5) << A[iw][ik];
    cout << endl;
  }
  
  // transponujemy macierz A w B
  
  for(iw = 0; iw < m; iw++)
    for(ik = 0; ik < n; ik++) B[ik][iw] = A[iw][ik];

  // wyœwietlamy macierz wynikow¹

  cout << endl << "Matrix B = AT:" << endl;
  
  for(iw = 0; iw < n; iw++)
  {
    for(ik = 0; ik < m; ik++) cout << setw(5) << B[iw][ik];
    cout << endl;
  }

  // koniec, zwalniamy pamiêæ zajêt¹ przez macierze

  for(iw = 0; iw < m; iw++) delete [] A[iw];
  for(iw = 0; iw < n; iw++) delete [] B[iw];
  delete [] A;
  delete [] B;

  return 0;
} 