// Vaša implementacija dolazi ovdje.

template <typename T>
std::allocator<T> Vect<T>::alloc;

template <typename T>
Vect<T>::Vect(size_t n, T v) : mdata(nullptr), mend(nullptr), mfirst_free(nullptr){     ///test

    if( n > 0){
        mdata = alloc.allocate(n);
        for( size_t i=0 ; i < n ; ++i)
            alloc.construct(mdata + i, v);
        mfirst_free = mend = mdata + n;
    }
}

// CCtor  --copy-constructor
template <typename T>
Vect<T>::Vect(const Vect& obj) {                                            //done
    //treba mi free prije ovog
    //cout<<"CCtor"<</*" size:"<<size()<<", capacity:"<<capacity()<<*/endl;
    //*this = obj;
    mdata = alloc.allocate( obj.capacity() );
    uninitialized_copy(obj.mdata, obj.mend, mdata);
    mfirst_free = mdata + obj.size();
    mend = mdata + obj.capacity();

}

// MCtor
template <typename T>
Vect<T>::Vect(Vect && v) noexcept : mdata(v.mdata), mfirst_free(v.mfirst_free), mend(v.mend){                                      ///provjera
//cout<<"MCtor"<<endl;
    v.mfirst_free=v.mdata = v.mend = nullptr;
//cout<<"prolaz-MCtor"<<endl;
}

// OP
template <typename T>
Vect<T>& Vect<T>::operator=(const Vect<T> & v){ //cout<<"OP "<</*" size:"<<size()<<", capacity:"<<capacity()<<*/endl;           //valjda radi
    free();
//cout << "izaso--op ="<<endl;
    mdata = alloc.allocate( v.capacity() );
    uninitialized_copy(v.mdata, v.mend, mdata);
    mfirst_free = mdata + v.size();
    mend = mdata + v.capacity();
    return *this;
}


// MOP
template <typename T>
Vect<T>& Vect<T>::operator=(Vect<T> && v) noexcept{                     ///provjera
//cout<<"MOP"<<endl;
    if( this != &v ){
    free();
    mdata = v.mdata;
    mfirst_free = v.mfirst_free;
    mend = v.mend;
    v.mdata = v.mend = v.mfirst_free = nullptr;
    }
//*this = v;
    //v.free();
    return *this;
}


// Oslobodi zauzeti prostor (pomoću alokatora)
template <typename T>
void Vect<T>::free() {                                      ////test
//cout<<"-----free:"<<endl;
    if( mdata != nullptr ){
       // auto temp = mfirst_free;
        //cout<< "mdata="<<*mdata<< ",  mfirst_free-1="<<*(mfirst_free-1)<< " size="<<size()<<" ,capacity="<<capacity()<<endl;
        //if(1)throw runtime_error("bok");
        //if(mfirst_free-1 != mdata)
        for (int i=0 ; mfirst_free != mdata ; ++i){
            //temp=mfirst_free;
            //--mfirst_free;
            alloc.destroy(mfirst_free--);
           //cout<<"vrti se";
            //if (i == 10)throw runtime_error("bok");
        }
        alloc.destroy(mfirst_free);
        alloc.deallocate(mdata, mend-mdata);
        mdata = mend = mfirst_free = nullptr;
    }
}

template <typename T>
// realociraj na novu lokaciju. Povećaj dimenziju vektora 2 puta; ako je
// vektor prazan alociraj jedan element.                            ///pomoću alokatora, izbjeći new i delete
void Vect<T>::reallocate(){
//cout<< "uso u reall"<<" size:"<<size()<<", capacity:"<<capacity()<<endl;
    Vect<T> temp(*this);
    //temp=*this;
//cout<<"proso u reallu"<<endl;
    mdata = alloc.allocate(2 * temp.capacity());
    for( size_t i=0 ; i < temp.capacity() ; ++i){
        alloc.construct(mdata + i, temp[i]);/*cout<<i<<endl;*/
    }
    mfirst_free = mdata + temp.size();
    mend = mdata + 2 * temp.capacity();
}

// dohvat elemenata (operator [])
template <typename T>
T Vect<T>::operator[](unsigned int i) const{                //fali provjera jesu li uvjeti zadovoljeni
    //for ( int i = 0 ; mdata + j != mfirst_free ; ++i)
    //cout<<"zagrada1"<<endl;
    if( i > size()-1 || i < 0)
            throw std::runtime_error("ERROR_INDEX");
    return *(mdata+i);
}

template <typename T>
T& Vect<T>::operator[](unsigned int i) {                //fali provjera jesu li uvjeti zadovoljeni
    //for ( int i = 0 ; mdata + j != mfirst_free ; ++i)
    //cout<<"zagrada2"<<endl;
    if( i > size()-1 || i < 0)
            throw std::runtime_error("ERROR_INDEX");
    return *(mdata+i);
}

// push_back metoda
template <typename T>
void Vect<T>::push_back( T var){                                        //done
//cout<<"uso u push_back"<<" , size: "<<size()<<", capacity:"<<capacity()<<endl;
    if ( mdata == nullptr ){
        Vect<T> temp(1,var);
        *this = temp;
        return;
    }
    if( capacity() == size() )
        reallocate();
//cout<<"prosla realokacija"<<endl;
    *mfirst_free = var;        //(*this)[size()] = var;
    mfirst_free += 1;
}

// operatori +=, -=, *=
template <typename T>
Vect<T> & Vect<T>::operator+=(const Vect<T> & second){
    //krivo implementirano

    if( size() == second.size())
        for ( unsigned i = 0 ; i < second.size() ; ++i){
            (*this)[i] += second[i];
        }
    return *this;
}

template <typename T>
Vect<T> & Vect<T>::operator-=(const Vect<T> & second){
    if( size() == second.size())
        for ( unsigned i = 0 ; i < second.size() ; ++i){
            (*this)[i] -= second[i];
        }
    return *this;
}

template <typename T>
Vect<T> & Vect<T>::operator*=(const int i){}

// euklidska norma vraća double !
template <typename T>
double Vect<T>::two_norm() const{
    double sum = 0;
    for( unsigned i = 0 ; i < size() ; ++i )
        sum += (*this)[i] *(*this)[i];
    return sqrt(sum);
}

/////////////////////////////////////////////////////////////////////////////////////

template <typename T>
Vect<T> operator+(const Vect<T> & first, const Vect<T> & second){
    Vect<T> temp(first.capacity(), first[0]);
    if( first.size() == second.size() ){
        for ( unsigned i = 0 ;  i < first.size() ; ++i)
             temp[i] = first[i] + second[i];
    }
    return temp;
}

template <typename T>
Vect<T> operator-(const Vect<T> & first, const Vect<T> & second){
    Vect<T> temp(first.capacity(), first[0]);
    if( first.size() == second.size() ){
        for ( unsigned i = 0 ;  i < first.size() ; ++i)
             temp[i] = first[i] - second[i];
    }
    return temp;
}

template <typename T>
std::ostream & operator<<(std::ostream & out, Vect<T> const & first){
    out << "[";
    for ( unsigned i = 0 ; i < first.size() ; ++i )
    {
        out << first[i];
        if ( i + 1 < first.size() )
            out << ",";
    }
    out << "]";
    return out;
}

