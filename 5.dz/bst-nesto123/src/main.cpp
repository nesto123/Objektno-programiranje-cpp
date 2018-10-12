#include <iostream>

#include "bin_stablo.h"
#include <vector>

using namespace std;

int main()
{
    // Vlastiti testovi
    BinarySTree<int> t;
    t.insert(7);
    t.insert(5);
    t.insert(6);
    t.insert(9);
    t.insert(8);

    std::vector<int> v;

    t.preOrder([&v](int x){v.push_back(x);} );
    for( auto i : v)
        cout<<i<<", ";
    cout<<endl;

    t.remove(5);
    v.clear();
    t.preOrder([&v](int x){v.push_back(x);} );
    for( auto i : v)
        cout<<i<<", ";
    cout<<endl;

    return 0;
}
