#include "zadatak.h"

#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>

using namespace std;


int main()
{
    //std::cout << zadatak(3.0) << std::endl;      ---zadatak

    vector<double> vecd(10, -7.1);
    vecd[3] = 4.1;
    vecd[4] = 4.1;

    // using Tip = vector<double>::iterator;
    //using je isto sto i typedef
        // typedef vector<double>::iterator Tip;

    //for(Tip it=...
    for(auto it = vecd.begin(); it != vecd.end(); ++it){
        //auto it =... -- ne treba pisat tip

        if(*it == 4.1)
            vecd.erase(it--); //-- da se ne preskoći sljedeći el kod brisanja
    }

    //ispis -range-for petlja
    for(auto x : vecd)
        cout << x << ",";
    cout << endl;

    //ekvivalentna petlja
    for(size_t i=0; i<vecd.size();++i){
        double x=vecd[i];
        cout << x << ",";
    }
    cout << endl;

    return 0;
}
