#include <vector>
#include <iostream>
#include <algorithm>

using iteraattori = std::vector<unsigned>::iterator;

// Tavoitteena on muodostaa koko ajan suurempia kombinaatioita siten, että tehty
// korotus on mahdollisimman pieni. (kombinaation koko tarkoittaa nyt vektorissa
// olevia lukuja peräkkäin: Esim {1,2,3,4} -> 1234. Tähän pienin korotus olisi 1243.
// ALKUEHTO: säiliö on ensimmäisellä suorituskerralla suuruusjärjestyksessä
// pienimmästä suurimpaan, eikä taulukkoa saa muokata suorituskertojen välissä.
//
bool seur(iteraattori alku, iteraattori loppu){
    if (alku == loppu) return false;
    iteraattori i = alku;
    i++;
    if (i == loppu) return false;
    i = loppu;
    i--;
    while (true)
    {
        iteraattori j = i;
        --i;
        if (*i < *j)
        {
            iteraattori k = loppu;
            while (!(*i < *--k)){}
            iter_swap(i, k);
            reverse(j, loppu); // Kääntää alkioden järjestyksen välillä j, loppu
            return true;
        }
        if (i == alku)
        {
            reverse(alku, loppu);
            return false;
        }
    }
}

int main()
{
    std::vector<unsigned> vektori = { 1, 2, 3, 4 };
    do
    {
        for (unsigned i = 0; i < 4; i++)
        {
            std::cout << vektori[i] << " ";
        }
        std::cout << "\n";
    }
    while (seur(vektori.begin(), vektori.end()));
}
