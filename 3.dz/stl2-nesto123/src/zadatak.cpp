#include "zadatak.h"
// Ubaciti potrebne include datoteke
#include <iostream>
#include <fstream>
#include <string>
#include <iterator>
#include <algorithm>
#include <map>

using namespace std;



// Zadan je raspon iteratora unutar stringa. Pročitati i vratiti prvu riječ iz stringa.
// Postaviti iterator it na prvu interpunkciju/bjelinu iza pročitane riječi ili na itend
// (end-iterator) ako takve nema.
// Riječi su cjeline međusobno odvojene bjelinama i/ili interpunkcijama: ,.!?:;()
// Bjeline su  \n\t\v.
std::string procitaj_rijec(std::string::const_iterator & it, std::string::const_iterator itend)
{
  // implementacija   
    string str="";

    while ( *it == '"' || *it == ' ' || *it == ',' || *it == '.' || *it == '!' || *it == '?' ||
               *it == ':' || *it == ';' || *it == '(' || *it == ')' || *it == '\t' ||
               *it == '\n' || *it == '\v'
           )it++;
    for ( ; it!=itend ; ++it ){

        if( *it == '"' || *it == ' ' || *it == ',' || *it == '.' || *it == '!' || *it == '?' ||
                *it == ':' || *it == ';' || *it == '(' || *it == ')' || *it == '\t' ||
                *it == '\n' || *it == '\v')

            break;
        else
            str.push_back( *it );
    }
    //if(str=="")str="PRAZNO";cout<< "---"  << str << "----------" << endl;
    return str;

}



// Otvoriti datoteku file_name za čitanje, učitati tekst (npr. liniju po liniju)
// i smjestiti riječi u mapu. Riječ je ključ, a vrijednost je broj pnavljanja riječi.
// Riječ se učitava pomoću rutine ucitaj_rijec.
void procitaj_datoteku(std::string file_name, std::map<std::string,int> & word_list){
  // implementacija

    string line, rjec;
    //int i=0;

        ifstream myfile (file_name);
          if (myfile.is_open())
          {
            while ( getline (myfile,line) )
            {
//cout <<"ispis ucitane linije" << line << '\n';
              auto it_first=line.cbegin(); auto it_last=line.cend();
//cout << *it_first<< endl;
              do{
                  rjec = procitaj_rijec( it_first, it_last );
                  if(rjec != ""){
//cout << *it_first << endl;
                 auto it = word_list.find(rjec);
                 if( it == word_list.end() )
                     word_list.insert(pair<string, int> (rjec, 1));
                 else it->second += 1;
//++i;if(i==7)break;
                    }
              }while (it_first != it_last);


            }
            myfile.close();
          }

          else cout << "Unable to open file";
          //print_map(word_list);


}


// Vrati listu riječi koje se najčešće pojavljuju u mapi (std::list) i broj ponavljanja (int).
std::pair<std::list<std::string>, int> naj(std::map<std::string,int> const & word_list){
  // implementacija   


    list<string> l;
    pair<list<string>, int> p;

    for ( auto x : word_list ){
        if ( x.second > p.second ) p.second = x.second;
    }
    for ( auto x : word_list)
        if ( x.second == p.second)
            p.first.push_back(x.first);
//print_naj(p);
    return p;


}

// Argument grupe sadrži grupe riječi (ključ je ime grupe, a vrijednosti
// su riječi koje pripadaju grupi).
// Funkcija treba za svaku grupu riječi sumirati broj pojavljivanja svih riječi
// iz grupe u tekstu te vratiti vrijednosti u vektoru. Na i-tom mjestu u povratnom vektoru
// je broj pojavljivanja riječi iz i-te grupe (prema uređaju u multimap varijabli).
// Argument word_list je std::map svih riječi s brojem njihovih pojavljivanja.
std::vector<int>
broj_iz_grupe(std::map<std::string,int> const & word_list,
              std::multimap<std::string, std::string> const & grupe){

  // implementacija  

    vector<int> vec;
    string  prethodna;
    int i=-1;

    for ( auto x : grupe ){
        if ( prethodna != x.first ){
            auto it = word_list.find(x.second);
            vec.push_back(it->second);
            prethodna = x.first;
            ++i;
        }
        else {
            auto it2 = word_list.find(x.second);
            vec[i] += (it2->second);
        }

    }
    //print_map(word_list);

    return vec;
}
