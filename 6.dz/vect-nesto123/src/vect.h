#ifndef _VECT_H_IS_INCLUDED_
#define _VECT_H_IS_INCLUDED_

#include <iostream>
#include <string>
#include <memory>
#include <cstddef>  // za std::size_t
#include <stdexcept>
#include <cassert>
#include <cmath>
using namespace std;

// deklaracija potrebna za testiranje
template <typename> class VectTest;

template <typename T>
class Vect
{
    friend class VectTest<T>;  // da testovi mogu dohvatiti privatne varijable
public:
    explicit Vect(size_t n = 0, T v= {});  // Ctor
    // Kontrola kopiranja dolazi ovdje
    // CCtor  --copy-constructor
    Vect(const Vect& obj);
    // MCtor
    Vect(Vect && v) noexcept;
    // OP
    Vect& operator=(const Vect & v);
    // MOP
    Vect& operator=(Vect && v) noexcept;
    // DTOR
    ~Vect(){free();}

    // dohvat elemenata (operator []) /////////////////////////////////////fali!!!!
    T operator[](unsigned int i) const /*{ return data[i]; }*/;
    T& operator[](unsigned int i) /*{ return data[i]; }*/ ;

    // push_back metoda
    void push_back( T var);
     // info rutine size() i capacity()
    size_t size() const {return mfirst_free-mdata;}
    size_t capacity() const {return mend - mdata;}

     // operatori +=, -=, *=
    Vect & operator+=(const Vect & second);
    Vect & operator-=(const Vect & second);


    Vect & operator*=(const int i);
     // euklidska norma vraća double !
     double two_norm() const;



private:
        T *mdata;       // pokazivač na prvi element
        T *mfirst_free; // pokazivač na prvo slobodno mjesto
        T *mend;        // pokazivač na kraj alociranog prostora
                             // (jedno mjesto iza posljednjeg)
  
        // Oslobodi zauzeti prostor (pomoću alokatora)
        void free();

      	// realociraj na novu lokaciju. Povećaj dimenziju vektora 2 puta; ako je 
        // vektor prazan alociraj jedan element.                            ///pomoću alokatora, izbjeći new i delete
        void reallocate();

        // dodati vlastite privatne metode.
	
        // alokator ne mora imati pristup varijablama članicama klase pa ga činimo 
        // statičkim. Ne zaboraviti definirati ga.
        static std::allocator<T> alloc;
};

// Deklaracija operator +, - i << 
template <typename T>
Vect<T> operator+(const Vect<T> & first, const Vect<T> & second);
template <typename T>
Vect<T> operator-(const Vect<T> & first, const Vect<T> & second);
template <typename T>
std::ostream & operator<<(std::ostream & out, Vect<T> const & first);

// Implementacija je u posebnoj .h datoteci
#include "vect_impl.h"

#endif
