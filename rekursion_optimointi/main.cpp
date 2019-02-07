#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <stdio.h>

using namespace std;

string A = "It is dif fi cult to solve this problem in either classical or quantum mechanics. In order to simplify the task, two important approximations are usually imposed. First, the sum is only performed over neighboring atoms.";

// i = indeksi josta tekstiä aletaan tutkia
int l = 18; // l = rivin max pituus
int n = A.length(); // tekstin pituus
int h = 0; // h = huonoimman pituus
int k = 0; // rivin pituus
long long unsigned lkm = 0; // funktion suorituskerrat
vector <int> memo(A.length(),-1); // säiliö, johon talletetaan funktion tuottamia arvoja eri i:n arvoilla

int jako2(int i){
    lkm++;
    if(n-i<=l) return l;
    if (memo[i] != -1) return memo[i];
    h=0;
    for(int j=2; j<=(l+1); j++){
        if(A[i+j] == ' '){
            k=jako2(i+j);
            if(k>(j-1)) k=j-1;
            if(k>h) h=k;
        }
    }
    memo[i] = h;
    return h;
}


int jako(int i){
    lkm++;
    if(n-i<=l) return l;
    h=0;
    for(int j=2; j<=(l+1); j++){
        if(A[i+j] == ' '){
            k=jako(i+j);
            if(k>(j-1)) k=j-1;
            if(k>h) h=k;
        }
    }
    return h;
}

int main()
{
    clock_t t = clock();
    cout << "Perus:\nhuonoin rivi: " << jako(0) << "\naika:";
    t = clock() - t;
    cout << double(t)/CLOCKS_PER_SEC << "s.\nfunktion kutsut: " << lkm << "\n\n";

    h=0;
    k=0;
    lkm = 0;

    t = clock();
    cout << "Optimoitu:\nhuonoin rivi: " << jako2(0) << "\naika:";
    t = clock() - t;
    cout << double(t)/CLOCKS_PER_SEC << "s.\nfunktion kutsut: " << lkm << "\n\n";
}

/* OHJELMA TULOSTAA:

Perus:
huonoin rivi: 16
aika:22.502s.
funktion kutsut: 467365110

Optimoitu:
huonoin rivi: 16
aika:0s.
funktion kutsut: 95

*/
