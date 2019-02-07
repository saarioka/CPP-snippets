#include <iostream>
#include <ctime>
#include <algorithm> // random_shuffle
#include <vector>
#include <ctime>
#include <stdio.h>
#include <chrono>

using namespace std;

// quicksort
template <class T>
void quicksort(T &A, int a1, int y1){
    if(a1 >= y1) return;
    int x = A[(a1+y1)/2];
    int a = a1-1;
    int y = y1 + 1;
    int apu;
    while(a < y){
        a++;
        y--;
        while(A[a] < x) a++;
        while(A[y] > x) y--;
        if(a < y){
            apu = A[a];
            A[a] = A[y];
            A[y] = apu;
        }
    }
    if(a == a1) a++;
    quicksort(A,a1,a-1);
    quicksort(A,a,y1);
}

// insertion sort
template <class T>
void insertionsort(T &A, unsigned koko){
    int apu, j;
    for(unsigned i = 1; i<koko; i++){
        apu = A[i];
        j = i-1;
        while(j >= 0 && (A[j] > apu)){
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = apu;
    }
}

// tulosta sailio
template <class T>
void tulosta(T &A, unsigned koko){
    for(unsigned i=0; i < koko; i++)
        cout << A[i] << " ";
    cout << "\n";
}

int main()
{
    const unsigned koko = 19;
    vector <int> A(koko);

    // sailion taytto
    srand (time(NULL));
    for(unsigned i = 0; i<koko; i++){
        A[i] = i+1;
    }
    random_shuffle(&A[0], &A[koko-1]);
    tulosta(A,20);
    cout << "\n";

    // quicksort
    auto alku = chrono::high_resolution_clock::now();
    for(unsigned i = 0; i<1000; i++){
        srand (time(NULL));
        random_shuffle(&A[0], &A[koko-1]);
        quicksort(A,0,koko-1);
    }
    auto loppu = chrono::high_resolution_clock::now();
    auto kesto = chrono::duration_cast<std::chrono::nanoseconds>(loppu - alku).count();
    tulosta(A,20);
    cout <<"Quick sort: koko " << koko << " ,kesto " << kesto << "ns.\n\n";

    // sailion sekoitus
    random_shuffle(&A[0], &A[koko-1]);
    tulosta(A,20);
    cout << "\n";

    // insertion sort
    alku = chrono::high_resolution_clock::now();
    for(unsigned i = 0; i<1000; i++){
        srand (time(NULL));
        random_shuffle(&A[0], &A[koko-1]);
        insertionsort(A,koko);
    }
    loppu = chrono::high_resolution_clock::now();
    kesto = chrono::duration_cast<std::chrono::nanoseconds>(loppu - alku).count();
    tulosta(A, 20);
    cout <<"Insertion sort: koko " << koko << " ,kesto " << kesto << "ns.\n\n";
    return 0;
}
/*
 * T. 59
 * a) n^2 on pienillä n arvoilla pienempi, kuin 10*n*log n + 2*n
 *
 *
 * b) matemaattisesti: n on väh. 62
 *    ks. kuva
 *
 *    kokeellisesti: n on n. 20
 *    ks. T. 60
 *
 *
 *
 * T. 60
 *
 * 4 2 16 17 11 10 13 1 5 6 15 3 14 12 19 8 7 9 18 20
 *
 * 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
 * Quick sort: koko 20 ,kesto 12000700ns.
 *
 * 12 4 10 19 17 6 7 5 16 11 1 14 3 9 2 18 15 8 13 20
 *
 * 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
 * Insertion sort: koko 20 ,kesto 12000100ns.
 *
 * Press <RETURN> to close this window...
 *
 *
 */

