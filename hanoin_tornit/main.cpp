#include <iostream>
#include <vector>
#include <cstdio>
#include <stdio.h>

using namespace std;

/*
 * Hanoin tornit
 *
 * kiekot ovat lukuja joiden suuruus = kiekon koko
 *
 */

unsigned long long lkm = 0;
void hanoi(unsigned koko, char poisto, char laitto, char skippaa){
    lkm++;
    if (koko == 1)
    {
        cout << "Siirra kiekko " << koko << " puikosta " << poisto << " puikkoon " << laitto << ".\n";
        return;
    }
    hanoi(koko-1, poisto, skippaa, laitto);
    cout << "Siirra kiekko " << koko << " puikosta " << poisto << " puikkoon " << laitto << ".\n";
    hanoi(koko-1, skippaa, laitto, poisto);
}

int main()
{
    const unsigned koko = 10;
    hanoi(koko, 'A', 'B', 'C');
    cout << "Siirtoja kulunut: " << lkm << "\n";
    return 0;
}
