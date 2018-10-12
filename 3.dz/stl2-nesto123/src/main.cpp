#include <iostream>
#include "zadatak.h"

#include <set>  //sortiraju elemente po < i ne dozvoljavaju duplikate  -za zo su multiset i multimap
#include <map>
#include <cassert>              //za assert  -- za razvijanje koda
#include <algorithm>
#include <iterator>
#include <string>

using namespace std;

void print_map(map<string, int> M){
    cout << "ispis map:" << endl;
    for (auto x : M)
        cout << x.first << " , " << x.second << endl;
    cout << endl;
}

void print_naj(pair<list<string>, int> p){
    cout << "ispis liste najvećih:" << "--br. pojavljivanja:" << p.second << endl;
    for (auto x : p.first)
        cout << x << " , ";
    cout << endl;
}

int main()
{
    // Ovdje napisati svoje vlastite testove!

    map<string, int> mapa;
    pair<list<string>, int> p;
    vector<int> vec;
    std::multimap<std::string, std::string> grupe;


    procitaj_datoteku("../test/4.txt", mapa);
    print_map(mapa);
    p=naj(mapa);
    print_naj(p);

    grupe.insert(pair<string,string>("Grupa1", "b"));
    grupe.insert(pair<string,string>("Grupa1", "f"));
    grupe.insert(pair<string,string>("Grupa2", "a"));
    grupe.insert(pair<string,string>("Grupa2", "c"));


    vec = broj_iz_grupe(mapa, grupe);

    cout << "Print vector: ";
    for ( auto x : vec )
        cout << x << ", ";
    cout << endl;

    return 0;
}
