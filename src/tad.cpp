#include <iostream>

using namespace std;

#include "tavlporo.h";

int
main(void)
{
  TPoro p(1, 1, 1, "rojo"), q(2, 2, 2, "verde"),r(6, 7, 8, "verde") ;
  TAVLPoro avl;

  avl.Insertar(p);
  
  cout << avl << endl;
}
