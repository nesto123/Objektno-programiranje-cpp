#include <iostream>
// /////////////////////////////////////////#include "zadatak.h"

#include <set>  //sortiraju elemente po < i ne dozvoljavaju duplikate  -za zo su multiset i multimap
#include <map>
#include <cassert>              //za assert  -- za razvijanje koda
#include <algorithm>
#include <iterator>
#include <string>

using namespace std;


int main()
{

    // Ovdje napisati svoje vlastite testove!








    // /////////////////////////////////////////////////////////////////////////////////////

    pair<double, int> pp;
    pp.first = 1.0;
    pp.second = 9;
    multiset<int, greater<int> > a{3,6,1,9,5,6}; //promjenili smo sa grater operator usporedivanja

    cout << a.count(6) << endl;     //koliko puta se 6 nalazi u spremniku /u setu 0 ili 1

    auto it = a.find(6);    // vraća iterator
        if(it == a.end())
            cout << "Element nije nađen" << endl;
        else
            cout << *it << endl;

    /* //za set
     * auto itm = a.insert(11);
     *cout <<*itm.first << " "<<itm.second<< endl;
     */

     a.erase(9);  // vraća koliko el je izbaćeno

    //za multiset  - trazenje elemenata
       auto it_l = a.lower_bound(6); // 6 <= *it_l
       auto it_u = a.upper_bound(6); //pokazuje na prvi el veći od 6 // 6 < *it_u

       if (it_l == it_u)
           cout << "Element nije nađen";

       copy(it_l, it_u, ostream_iterator<int>(cout,","));
       cout<< endl;

       auto it_er = a.equal_range(6);   //vraća par iteratora

       assert(it_er.first == it_l) ;         //provjera
       assert(it_er.second == it_u);


    for (auto x: a)
        cout<< x << ",";
    cout << endl;

    // ///////////////////////////////// map dio

    map<string, int> a2{{"b", 3}, {"g", 7},{"a", 11}};


    a2.insert(pair<string,int>("r", 7));
    //ili
    auto iit = a2.insert(make_pair("z", 6));
    cout << iit.first->first << endl;  //treba dobit z


    for (auto x: a2)     //x je element mapa tj par
        cout << x.first << " = " << x.second << endl;

    int n = a2.count("b");     // uzima kljuc





    // ////////


    return 0;
}

