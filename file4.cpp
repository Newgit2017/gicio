#include <iostream>

using namespace std;

int main()
{
  unsigned int i,k,p,q,n,m;
  bool * S;

  cin >> n;
  if(n & 1) n++;
  m = n >> 1;
  S = new bool[m + 1];
  for(i = 1; i < m; i++) S[i] = true;
  i = 1; p = 3; q = 4;
  do
  {
    if(S[i])
    {
      k = q;
      while(k < m)
      {
        S[k] = false; k += p;
      }
    }
    i++; p += 2;
    q += (p << 1) - 2;
  } while(q < m);
  cout << 2 << " ";
  for(i = 1; i < m; i++) if(S[i]) cout << (i << 1)+1 << " ";
  cout << endl;
  delete [] S;
  return 0;
} 