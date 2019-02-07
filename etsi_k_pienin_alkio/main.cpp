#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

void vaihda(unsigned &a, unsigned &b){
    unsigned apu = a;
    a = b;
    b = apu;
}

unsigned ositus(vector<unsigned> &sailio, unsigned vasen, unsigned oikea, unsigned pivot_index){
    unsigned pivot = sailio[pivot_index];
    vaihda(sailio[pivot_index], sailio[oikea]);
    unsigned apu = vasen;
    for (unsigned i = vasen; i<oikea; i++){
        if (sailio[i] < pivot){
            vaihda(sailio[apu], sailio[i]);
            ++apu;
        }
    }
    vaihda(sailio[oikea], sailio[apu]);
    return apu;
}

unsigned etsik(vector<unsigned> &sailio, unsigned vasen, unsigned oikea, unsigned k){
    unsigned pivot;
    while (true){
        srand (time(NULL));
        if (vasen == oikea) return sailio[vasen];
        pivot = (vasen + (rand() % (oikea - vasen + 1)));
        pivot = ositus(sailio, vasen, oikea, pivot);
        if (k == pivot) return sailio[k];
        else if (k < pivot) oikea = pivot -1;
        else vasen = pivot + 1;
    }
    return pivot;
}


int main()
{
    srand (time(NULL));
    vector<unsigned> vektori;
    unsigned a;

    cout << "Sisalto:\n";
    for (unsigned i = 0; i<10; i++){
        a = rand() % 100 + 1;
        vektori.push_back(a);
        cout << a << "\n";
    }

    unsigned paluuarvo;
    paluuarvo = etsik(vektori, 0, vektori.size() -1, 3); // k = 3 eli 4. alkio
    cout << "\nk: " << paluuarvo << "\n\nSisalto:\n";
    for (unsigned i = 0; i<10; i++){
        cout << vektori.at(i) << "\n";
    }
    return 0;
}
/*
 * OHJELMA TULOSTAA:
 *

Sisalto:
69
46
15
91
45
58
15
11
41
58

k: 41

Sisalto:
15
15
11
41
45
58
46
69
58
91
Press <RETURN> to close this window...

 */
