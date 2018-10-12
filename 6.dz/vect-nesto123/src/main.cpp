#include "vect.h"

using namespace std;

int main()
{
    // Vaši testovi dolaze ovdje.    

    Vect<int> v1(1,2), v2(1,4), v3(v1);

    /*cout << v1[0] << ", sze--v1: "<<v1.size()<< ", capacity: "<<v1.capacity()<< endl;
    v2=v1;
    cout<< v2[0]<< ",size--v2: "<<v2.size()<< ", capacity: "<<v2.capacity()<< endl;
    cout<< v3[0]<< ",size--v3: "<<v3.size()<< ", capacity: "<<v3.capacity()<< endl;
*/
    v1.push_back(3);
    v1+=v2;

    cout << v1[2] << ", sze--v1: "<<v1.size()<< ", capacity: "<<v1.capacity()<< endl;




    return 0;
}
