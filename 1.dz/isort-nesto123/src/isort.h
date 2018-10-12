#ifndef _ISORT_H_ 
#define _ISORT_H_ 
#include <vector>
#include <iterator>
#include <algorithm>

// Verzija s indeksima
template <typename Record>
void insertion_sort_ind(std::vector<Record> & vec)
{
   // Vaša implementacija 
    unsigned i,j;
    Record t;

    for(i=1;i<vec.size();i++){
        t=vec[i];
        for(j=i;j>=1 && vec[j-1] > t; j--)
            vec[j]=vec[j-1];
         vec[j]=t;
    }
}


// Verzija koja uzima iterator range -- koristiti samo std::next i std::prev
template <typename Iter>
void insertion_sort(Iter first, Iter last) {
   // Vaša implementacija 

    auto t=*first;


    Iter it1=first, it2=first;

    for(it1=std::next(first,1) ; it1 != last ; it1 = std::next(it1, 1) ){
        t=(*it1);
        for(it2 = it1 ; it2!=first && (*std::prev(it2,1)) > t; it2=std::prev(it2,1))
           *it2= (*std::prev(it2,1));
         *it2=t;
    }

}

// verzija sa algoritmima std::rotate i std::upper_bound
template <typename Iter>
void insertion_sort1(Iter first, Iter last) {
   // Vaša implementacija 
                                                                    // provjerit !!
    if (first==last) return;

      for (auto && iter = std::next(first); iter != last; ++iter)
      {
        std::rotate(std::upper_bound(first, iter, *iter), iter, std::next(iter));
      }
}


#endif
