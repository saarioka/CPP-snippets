#include <iostream>
#include <vector>
#include <ctime>
#include <stdio.h>
#include <list>

using namespace std;

template <class T>
void poista_kopiot( T& sailio){
    typename T::iterator s1,s2;

    s1 = sailio.begin();
    while( s1 != sailio.end() ){
    s2 = s1; ++s2;
    if( s2 != sailio.end() && *s1 == *s2 ){ sailio.erase( s2 ); }
    else{ s1 = s2; }
    }
}

int main()
{
    vector<int> sailio;
    list<int> sailio2;

    // i määrä alkioita
    for (unsigned i = 0; i< 200000; i++){
        sailio.push_back(i);
        sailio.push_back(i);
        sailio2.push_back(i);
        sailio2.push_back(i);
    }

    // Vektori
    clock_t t = clock();
    poista_kopiot(sailio);
    t = clock() - t;

    // tulostetaan muutamia alkioita alusta
    for(unsigned i = 0; i<10; i++){
        cout << sailio.at(i) << "\n";
    }

    cout << "Aikaa meni " << double(t)/CLOCKS_PER_SEC << "s.\n\n";


    // List
    t = clock();
    poista_kopiot(sailio2);
    t = clock() - t;

    // tulostetaan muutamia alkioita alusta
    unsigned apu = 0;
    for(list<int>::const_iterator i = sailio2.begin(); apu<10; ++i){
        cout << *i << "\n";
        apu++;
    }

    cout << "Aikaa meni " << double(t)/CLOCKS_PER_SEC << "s.\n\n";

    return 0;
}
/*
 * OHJELMA TULOSTAA:
 *
 * 0
 * 1
 * 2
 * 3
 * 4
 * 5
 * 6
 * 7
 * 8
 * 9
 * Aikaa meni 13.405s.
 *
 * 0
 * 1
 * 2
 * 3
 * 4
 * 5
 * 6
 * 7
 * 8
 * 9
 * Aikaa meni 0.02s.
 *
 * Press <RETURN> to close this window...
 *
 */

