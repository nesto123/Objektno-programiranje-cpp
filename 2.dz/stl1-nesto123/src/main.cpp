#include "zadatak.h"

#include <iostream>
#include <fstream>
#include <iterator>
#include <string>
#include <algorithm>
#include <iterator>

using namespace std;

void print_vec(std::vector<int> v){

    for (auto x: v)
        std::cout<< x <<",";
    cout<<"-----"<< v.size()<<endl;
    return;
}

int main()
{
    //          ispis početnog stanja
    ifstream in("../../src/brojevi.txt");
    istream_iterator<int> isi_in(in);
    istream_iterator<int> isi_end;
    vector<int> vec0(isi_in,isi_end);

    print_vec(vec0);
//1. funkvcija
    std::vector<int> vec = zadatak1("../../src/brojevi.txt");
    print_vec(vec);


    cout<<"2. Zadatak"<<endl;
    zadatak2("../../src/fpbrojevi.txt");


    std::list<int> l = zadatak3();

    return 0;
}
