#ifndef LISTA_H
#define LISTA_H 

#include <cstddef>  // za std::size_t
#include <stdexcept>
#include <cassert>
#include <iostream>

using namespace std;

template <typename> class ListTest;

// Paramtrizirana struktura koja predstavlja čvor u listi.
// Sadrži vrijednost (value) i pokazivače na prethodni i sljedeći
// element u listi.
template <typename T>
struct Node{
	T value{};
	Node * previous = nullptr;
	Node * next = nullptr;
};

/**
 * Dvostruko povezana lista s elementima indeksiranim cjelobrojnim indeksima.
 * Indeksi elemenata počinju s nulom. Sve metode koje uzimaju indeks provjeravaju
 * da li je unutar granica i u suprotnom izbacuju std::runtime_error.  
 **/
template <typename T>
class List{
    friend class ListTest<T>;
	public:
		// Konstruktor
        List() :  mSize(0), mPositionIdx(0), mStart(nullptr), mPosition(nullptr) {}             //nullptr je u c++11
		// Destruktor
		~List() { clear(); }
		// Obriši (dealociraj) sve elemente liste. 
		void clear();
		// Da li je lista prazna?
		bool empty() const;
		// Broj elemenata u listi. 
		std::size_t size() const;
		// Ubaci element "t" na poziciju "i" u listi. Pozicija "i" mora biti važeća 
		// i tada se element ubacuje na to mjesto, a prijašnji "i"-ti element postaje 
		// "i"+1-vi element. Pozicija "i" može biti jednaka size()  i tada se element ubacuje na kraj liste. 
		// Metoda mora ispravno ubacivati i u praznu listu. Metoda pozicionira listu na novom
		// i-tom elementu (pozivom metode setPosition()). 
                // Novi element se alocira dinamički pomoću new operatora.
		void insert(std::size_t i, T const & t);
		// Izbaciti element iz liste i dealocirati ga pomoću delete. Trenutna pozicija
		// nakon izbacivanja pokazuje na prethodni element ako postoji; kada se izabacuje prvi element
		// onda pokazuje na novi prvi element ili lista ostaje prazna. 
		void remove(std::size_t i);
		// Postaviti trenutnu poziciju na i-to mjesto. Dozvoljeni "i" ide od 0 do 
		// size()-1. Inače izbaci izuzetak std::runtime_error.
		void setPosition(std::size_t i) const;
		// Vrati selektirani element. Konstantan verzija.
                T const & current() const;
		// Vrati selektirani element. Nekonstantna verzija.
                T & current();
                // Dodaje element na kraj liste. Listu pozicionira na novom elementu.
		void push_back(T const & t);
                // Sortira listu pomoću operatora <. Implementirati "insertion sort".
                void sort();

        //void print();
	private:
       std::size_t mSize;                   //unsigned int
       mutable std::size_t mPositionIdx;       // sinkronizirana s donjm
           Node<T> * mStart;
       mutable Node<T> * mPosition;                //cvor koji pokazuje na trenutno selektiran dio liste

       // Vrati pokazivač na selektirani node.                                              //trenutno selektiran
	   Node<T> * currentNode() { return mPosition; }
};

/*
template <typename T>
void List<T>::print(){
    auto it = mStart;
    for (  ; it->next != nullptr ; it = it->next )
        cout << it->value << ", ";
    cout << it->value << endl;

}
*/

//koristit new i remove valjda

template <typename T>
bool List<T>::empty() const {                                               //done
  // Implementacija

    if (mSize == 0) return true;
    else return false;
}

template <typename T>
std::size_t List<T>::size() const { return mSize; }

template <typename T>
T const & List<T>::current() const {                                       //done
 // Implementacija
    return mPosition->value;

}

template <typename T>
T & List<T>::current() {                                                  //done
 // Implementacija
    return mPosition->value;
}

template <typename T>
void List<T>::setPosition(std::size_t i) const{                             //done
 // Implementacija
    if( i >= size() || i < 0)
        throw std::runtime_error("ERROR_INDEX");
    mPositionIdx = i;
    mPosition = mStart;
    for ( unsigned j = 0 ; j < i ; j++)
        mPosition = mPosition->next;
}

template <typename T>
void List<T>::insert(std::size_t i, T const & t){                         //done
 // Implementacija

    if( i > size() || i < 0)
        throw std::runtime_error("ERROR_INDEX");

    if( empty() == 1){                   //ubacivanje u braznu listu
        mStart = new Node<T>;
        mStart->value = t; mSize++;
        setPosition(i);
        return ;
    }

    Node<T> *iti, *temp, *prosli = mStart;
    if( i == 0){                        //uvacujemo na 0-to mjesto
        temp = new Node<T>;
        temp->value = t; mSize++;

        temp->next = mStart;
        mStart->previous =temp;
        mStart = temp;

        setPosition(i);
        return;
    }

    unsigned j;
    for( j = 0 ; j < i -1 ; ++j ){
        prosli=prosli->next;
    }

    if( i == size() ){          //ubacujemo na kraj

        temp = new Node<T>;
        temp->value = t; mSize++;

        prosli->next = temp;
        temp->previous = prosli;

        setPosition(i);
        return;
    }

    iti=prosli->next;
    temp = new Node<T>;
    temp->value = t; mSize++;

    temp->next = iti; temp->previous = prosli;
    prosli->next = temp; iti->previous = temp;
    setPosition(i);

}


template <typename T>
void List<T>::remove(std::size_t i){                            //valjda done
 // Implementacija

    if( i >= size() || i < 0)
        throw std::runtime_error("ERROR_INDEX");

    Node<T> *sljedeci, *prethodni, *iti = mStart;
    if( i == 0){                    //izbacujem 1. element
        if(size() != 1){            //ako lista ne sadzi samo 1. element
            sljedeci = mStart->next;
            mPositionIdx = 0;
            mPosition = sljedeci;
            sljedeci->previous = nullptr;
            delete mStart; mSize--;
            mStart=sljedeci; return ;
        }
        else{                     //lista sadrzi samo 1. element
            mStart=mPosition = nullptr;
            mPositionIdx = 0;
            mSize--;
            delete mStart;
            return ;
        }
    }
    unsigned j;
    for( j = 0 ; j < i ; ++j )
        iti=iti->next;

    prethodni = iti->previous;
    if( iti->next == nullptr ){         //brisemo zadnji
        prethodni->next = nullptr;
        mSize--; delete iti;
        mPositionIdx = mSize-1;
        mPosition = prethodni;
        return ;
    }

    sljedeci = iti->next;
    sljedeci->previous = prethodni;
    prethodni->next = sljedeci;
    mSize--;delete iti;
    mPositionIdx = i; mPosition = prethodni;
    return;
}

template <typename T>
void List<T>::clear(){                                                  //done
 // Implementacija
    while(mSize>0){
        remove(0);
    }
}

template <typename T>
void List<T>::push_back(T const & t) {                                    //done
 // Implementacija

    insert(mSize, t);
}

template <typename T>
void List<T>::sort() {
 // Implementacija

    if( mSize <2) return;
    int i=1, j;
    T temp;
    for( auto it1 = mStart->next ; i < size() ; it1 = it1->next, ++i )
    {
        j=i;
        temp = it1->value;
        for( auto it2 = it1 ; j >= 1 && it2->previous->value > it1->value ; it2 = it2->previous, --j){
        }

        insert(j,temp);
        if(j-1 < i) remove(i+1);
        else remove(i);
    }

}

#endif /* LISTA_H */
