#include <string>
#include "isort.h"
#include <iostream>
#include <list>


using namespace std;

int main()
{
    // Testirajte vaše algoritme na vektoru i listi. 
    vector<int> vect {17,31,3,43,11,24,8};
    vector<string> vect1 {"zui", "rtz", "jkh", "dft", "qwe","aaa"};
    list<int> vect2 {17,31,3,43,11,24,8};

    for(auto x : vect )
        cout << x << ", ";
    cout << endl;

    /*
    insertion_sort_ind(vect);

    for(auto x : vect )
        cout << x << ", ";
    cout << endl;
    */

    cout << "2. funkcija:" << endl;
    insertion_sort(vect.begin(), vect.end());

    for(auto x : vect )
        cout << x << ", ";
    cout << endl;

    cout << "2. funkcija (lista):" << endl;
    insertion_sort(vect2.begin(), vect2.end());

    for(auto x : vect2 )
        cout << x << ", ";
    cout << endl;

    cout << "3. funkcija (vector):" << endl;
    insertion_sort1(vect1.begin(), vect1.end());

    for(auto x : vect1 )
        cout << x << ", ";
    cout << endl;



    return 0;
}
