#include "zadatak.h"
// Ubaciti potrebne include datoteke

#include <iostream>
#include <fstream>
#include <iterator>
#include <string>
#include <algorithm>
#include <iterator>
#include <cmath>
#include <cassert>

using namespace std;

std::vector<int> zadatak1(std::string const & file_name){
  // Implementacija zadatka 1
      // istream_iterator

    /*vector<int> vect();
    ifstream file;
    file.open(file_name);
    if(file.is_open()){
///////////////////////////////////nesto
    }
*/
    ifstream in(file_name);
    istream_iterator<int> isi_in(in);
    istream_iterator<int> isi_end;
    vector<int> vec(isi_in,isi_end);


    replace(vec.begin(), vec.end(), 0,9);
    /*vector<int> vec2(1,9);

    for(auto it = vec.begin(), it2 = vec2.begin(); it != vec.end() ; ++it){
        if(*it == 0) swap(*it, *it2);
        cout<<*it<<",";    vector<int> vec(isi_in,isi_end);

    }
    cout<<endl;*/

    return vec;
}

void zadatak2(std::string const & file_name){
  // Implementacija zadatka 2

    ifstream in(file_name);
    istream_iterator<float> isi_in(in);
    istream_iterator<float> isi_end;
    vector<float> vec;

    std::copy(isi_in, isi_end, std::back_inserter(vec));

    /*  POCETNI ISPIS
     * for (auto x: vec)
        std::cout<< x <<",";
    cout<<"-----"<< vec.size()<<endl;  */

    std::cout.precision(6);

/*
    for(auto x : vec){
        if(x>0)cout<<'+';
        std::cout << std::scientific << x <<' ';
        if(sin(x)>0)cout<<'+';
        std::cout << std::scientific << sin(x) <<' ';
        if(exp(x)>0)cout<<'+';
        std::cout << std::scientific << exp(x) << endl;
    }
*/

    ofstream myfile ("3cols.txt");
    if (myfile.is_open())
      {

        for(auto x : vec){
            if(x>0)myfile<<'+';
            myfile << std::scientific << x <<' ';
            if(sin(x)>0)myfile<<'+';
            myfile << std::scientific << sin(x) <<' ';
            if(exp(x)>0)myfile<<'+';
            myfile << std::scientific << exp(x) << endl;
        }
        myfile.close();

      }
     else cout << "Unable to open file";

    return;
}

std::list<int> zadatak3(){
  // Implementacija zadatka 3
    list<int> l1 {1,2,3,4,5,6,7,8,9},l2{1,2,3,4,5,6,7,8,9};
    bool test=false;

    // INICIJALNI ISPIS
 /*   for (auto x: l1)
        std::cout<< x << ", ";
    std::cout<< endl;
  */  // //////////////////////////

    do{
        std::next_permutation(l1.begin(), l1.end());
    }while(*(l1.begin())!= 5);
    do{
        std::next_permutation(l2.begin(), l2.end());
    }while(*(l2.begin())!= 9);
/*
    cout<<"ispis l1: ";
    for (auto x: l1)
        std::cout<< x << ", ";
    std::cout<< endl;
    cout<<"ispis l2: ";
    for (auto x: l2)
        std::cout<< x << ", ";
    std::cout<< endl;
    */

    auto it_3 = std::find(std::begin(l1), std::end(l1), 3); assert(it_3 != std::end(l1));
    auto it_4 = std::find(std::begin(l2), std::end(l2), 4); assert(it_4 != std::end(l2));
    auto it_7 = std::find(std::begin(l2), std::end(l2), 7); assert(it_7 != std::end(l2));

    //if( it_3 == std::end(l1) ||  it_4 == std::end(l2) ||  it_7 == std::end(l2))

    for(auto it = it_7; it !=l2.end() ; ++it )
        if(*it == 4){
            test=true;
            //auto temp =it_7; it_7=it_4; it_4=temp;break;
        }

    if(test)
        l1.splice(it_3, l2, it_7, it_4);
    else
        l1.splice(it_3, l2, it_4, it_7);
/*
    cout<<"Stanje nakon splicea"<<endl<<"ispis l1: ";
    for (auto x: l1)
        std::cout<< x << ", ";
    std::cout<< endl;
    cout<<"ispis l2: ";
    for (auto x: l2)
        std::cout<< x << ", ";
    std::cout<< endl;
*/
    return l1;
}

