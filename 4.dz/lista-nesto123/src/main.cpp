#include "lista.h"

using namespace std;

int main()
{
// Ovdje pišete vlastite testove klase. 

    List<int> a;
    int br;


    cout << a.empty() << endl;

    a.insert(0,5);
    cout << a.size() <<endl;

    a.insert(1,1);
    cout << a.size() <<endl;

    a.insert(2,3);
    cout << a.size() <<endl;


    //a.print();
    a.sort();
   // a.print();
   
  return 0;
}
 
