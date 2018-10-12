#include <iostream>
#include "operations.h"
#include <chrono>
#include <array>
#include <algorithm>

using namespace std::chrono;
using namespace std;

template <int N>
class Vect{
public:
Vect(double c = 0.0){ mdata.fill(c); }
Vect(Vect const &) = delete;
Vect(Vect &&) = delete;
Vect & operator=(Vect const &) = delete;
Vect & operator=(Vect &&) = delete;
void fill(double c){ mdata.fill(c); }
double operator[](std::size_t i) const { return mdata[i];}
double& operator[](std::size_t i) { return mdata[i];}
private:
std::array<double,N> mdata;
};

template <typename T, size_t dim>
std::array<T,dim> operator+(std::array<T,dim> const& lhs, std::array<T,dim> const& rhs)
{
std::array<T,dim> tmp;
for(size_t i=0; i < dim; ++i)
tmp[i] = lhs[i] + rhs[i];
return tmp;
}
int main()
{
    // Vaši testovi i test brzine

    const size_t dim = 100;
    std::array<double,dim> a;
    std::array<double,dim> b;
    std::array<double,dim> c;

    for(auto & x : a) x = 2.0;
    for(auto & x : b) x = 3.0;

    auto start = system_clock::now();
        for(unsigned int i=0; i < dim; ++i) c[i] = a[i] + b[i];
    auto end = system_clock::now();
    auto duration = duration_cast<milliseconds>(system_clock::now() - start);

    cout<< "C time for " << dim << " additions = "<< duration.count() <<" ms.\n";
    cout << c[dim-1] << endl; // Da spriječi potpunu eliminaciju koda s opcijom -O2


    start = system_clock::now();
    c = a + b;
    end = system_clock::now();
    duration = duration_cast<milliseconds> (system_clock::now() - start);
    cout<< "C++ time for " << dim << " additions = "<< duration.count() <<" ms.\n";
    cout << c[dim-1] << endl;// Da spriječi potpunu eliminaciju koda s opcijom -O2


    Vector<4, Vect<4>> x,z;
    x[0] = 0;
    x[1] = 1;
    x[2] = 2;
    x[3] = 3;

    Matrix<4,4> M;
    M(0,0)=M(1,1)=M(2,2)=1;
    M(3,3)=3;
    M(1,0)=M(2,1)=M(3,2)=0;
    M(3,0)=2;
    M(0,1)=0;
    M(0,2)=M(0,3)=1;
    M(1,2)=2;
    M(1,3)=0;
    M(2,3)=3;
    M(2,0) = 1;
    M(3,1)=0;
    z=M*x;

	return 0;
}
