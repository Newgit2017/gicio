#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

// Typ w�z��w drzewa BST
//----------------------

struct BSTNode
{
  BSTNode * up, * left, * right;
  int key;
};

// Zmienne globalne
//-----------------

string cr,cl,cp;      // �a�cuchy do znak�w ramek

// Procedura wypisuje drzewo
//--------------------------
void printBT(string sp, string sn, BSTNode * v)
{
  string s;

  if(v)
  {
    s = sp;
    if(sn == cr) s[s.length() - 2] = ' ';
    printBT(s + cp, cr, v->right);

    s = s.substr(0,sp.length()-2);
    cout << s << sn << v->key << endl;

    s = sp;
    if(sn == cl) s[s.length() - 2] = ' ';
    printBT(s + cp, cl, v->left);
  }
}

// Procedura DFS:postorder usuwaj�ca drzewo
//-----------------------------------------
void DFSRelease(BSTNode * v)
{
  if(v)
  {
    DFSRelease(v->left);   // usuwamy lewe poddrzewo
    DFSRelease(v->right);  // usuwamy prawe poddrzewo
    delete v;              // usuwamy sam w�ze�
  }
}

// Procedura wstawia do drzewa BST w�ze� o kluczu k
//-------------------------------------------------
void insertBST(BSTNode * & root, int k)
{
  BSTNode * w, * p;

  w = new BSTNode;           // Tworzymy dynamicznie nowy w�ze�

  w->left = w->right = NULL; // Zerujemy wskazania syn�w

  p = root;                  // Wyszukujemy miejsce dla w, rozpoczynaj�c od korzenia

  if(!p)                     // Drzewo puste?
    root = w;                // Je�li tak, to w staje si� korzeniem
  else
    while(true)              // P�tla niesko�czona
      if(k < p->key)         // W zale�no�ci od klucza idziemy do lewego lub
      {                      // prawego syna, o ile takowy istnieje
        if(!p->left)         // Je�li lewego syna nie ma,
        {
          p->left = w;       // to w�ze� w staje si� lewym synem
          break;             // Przerywamy p�tl� while
        }
        else p = p->left;
      }
      else
      {
        if(!p->right)        // Je�li prawego syna nie ma,
        {
          p->right = w;      // to w�ze� w staje si� prawym synem
          break;             // Przerywamy p�tl� while
        }
        else p = p->right;
      }

  w->up  = p;                // Ojcem w�z�a w jest zawsze w�ze� wskazywany przez p
  w->key = k;                // Wstawiamy klucz. Operacja jest zako�czona.

}

// Rotacja w lewo
//---------------
void rot_L(BSTNode * & root, BSTNode * A)
{
  BSTNode * B = A->right, * p = A->up;

  if(B)
  {
    A->right = B->left;
    if(A->right) A->right->up = A;

    B->left = A;
    B->up = p;
    A->up = B;

    if(p)
    {
      if(p->left == A) p->left = B; else p->right = B;
    }
    else root = B;
  }
}

// Rotacja w prawo
//----------------
void rot_R(BSTNode * & root, BSTNode * A)
{
  BSTNode * B = A->left, * p = A->up;

  if(B)
  {
    A->left = B->right;
    if(A->left) A->left->up = A;

    B->right = A;
    B->up = p;
    A->up = B;

    if(p)
    {
      if(p->left == A) p->left = B; else p->right = B;
    }
    else root = B;
  }
}

// Procedura Splay
// root - korze� drzewa
// k    - klucz
//---------------------
void splay(BSTNode * & root, int k)
{
  BSTNode * x, *y;

  x = root;                 // Poszukujemy w�z�a o kluczu k, poczynaj�c od korzenia
  if(x)
  {
    do
    {
      if(x->key == k) break;
      y = x;                // Zapami�tujemy adres w�z�a
      x = k < x->key ? x->left: x->right;
    } while(x);

    if(!x) x = y;           // Je�li w drzewie nie ma takiego w�z�a, to za x
                            // bierzemy bezpo�redni nast�pnik lub poprzednik
    while(true)             // W p�tli w�ze� x przesuwamy do korzenia
    {
      if(!x->up) break;     // x jest korzeniem, ko�czymy

      if(!x->up->up)
      {                     // Ojcem x jest korze�. Wykonujemy ZIG
        if(x->up->left == x) rot_R(root,x->up);
        else                 rot_L(root,x->up);
        break;              // Ko�czymy
      }

      if((x->up->up->left == x->up) && (x->up->left == x))
      {                     // prawy ZIG-ZIG
        rot_R(root,x->up->up);
        rot_R(root,x->up);
        continue;
      }

      if((x->up->up->right == x->up) && (x->up->right == x))
      {                    // lewy ZIG-ZIG
        rot_L(root,x->up->up);
        rot_L(root,x->up);
        continue;
      }

      if(x->up->right == x)
      {                    // lewy ZIG, prawy ZAG
        rot_L(root,x->up);
        rot_R(root,x->up);
      }
      else
      {                    // prawy ZIG, lewy ZAG
        rot_R(root,x->up);
        rot_L(root,x->up);
      }
    }
  }
}

// **********************
// *** PROGRAM G��WNY ***
// **********************

int main()
{
  int a,b,c,i;
  BSTNode * root = NULL;

  // ustawiamy �a�cuchy znakowe, poniewa� nie wszystkie edytory pozwalaj�
  // wstawia� znaki konsoli do tworzenia ramek.
  // cr = +--
  //      |

  // cl = |
  //      +--

  // cp = |
  //      |

  cr = cl = cp = "  ";
  cr[0] = 218; cr[1] = 196;
  cl[0] = 192; cl[1] = 196;
  cp[0] = 179;

  srand(time(NULL));        // inicjujemy generator pseudolosowy

  a = c = 8; b = 16;
  for(i = 0; i < 15; i++)   // Drzewo wype�niamy w�z�ami
  {
    insertBST(root,c);
    c += b;
    if(c > 16)
    {
      a >>= 1;
      b >>= 1;
      c = a;
    }
  }

  printBT("","",root);  // Wy�wietlamy drzewo

  cout << endl << endl;

  c = 1 + rand() % 15;  // Losujemy klucz
  cout << c << endl;

  splay(root,c);        // Operacja splay dla wylosowanego klucza

  cout << endl << endl;

  printBT("","",root);  // Wy�wietlamy drzewo

  cout << endl << endl;

  DFSRelease(root);     // Usuwamy drzewo BST z pami�ci

  return 0;
}