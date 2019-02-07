#include <iostream>

// Operators using only for loops and sum

// n+m
unsigned a(unsigned n, unsigned m){
    for(unsigned i=0; i<m; i++) n++;
    return n;
}

// n*m
unsigned b(unsigned n, unsigned m){
    unsigned apu = 0;
    for(unsigned i=0; i<m; i++){
        for(unsigned j=0; j<n; j++){
            apu++;
        }
    }
    return apu;
}

// n^m
unsigned c(unsigned n, unsigned m){
    if(m == 0) return 1;
    unsigned tulo;
    unsigned uusi = n;

    // toistuu m-1 kertaa (="kertolaskumerkkien määrä")
    for(unsigned k=0; k < m-1; k++){
        tulo = 0;

        // lasketaan n*tulo, jossa tulo on edellinen tulos (1. kierroksella n*tulo = n*n)
        // n*tulo = n*n, n*(n*n), n*[n*(n*n)], ...
        for(unsigned i=0; i < n; i++){
            for(unsigned j=0; j < uusi; j++){
                tulo++;
            }
        }

        // saadaan uusi tulontekijä, joka on edellisten tulo
        uusi = tulo;
    }
    return uusi;
}

// HUOM: HIDAS
// ks. taulukko https://en.wikipedia.org/wiki/Tetration
unsigned tetration(unsigned n, unsigned m){
    if(m == 0) return 1;
    unsigned apu= 0;
    unsigned apu2 = n;
    unsigned apu3 = n;

    for (unsigned k=0; k < m-1; k++){

        apu2 = n;
        for (unsigned k=0; k < apu3; k++){
            apu = 0;
            for (unsigned i=0; i < n; i++){
                for (unsigned j=0; j < apu2; j++){
                    apu++;
                }
            }
            apu2 = apu;
        }
        apu3 = apu;
    }
    return apu;
}


int main()
{
    unsigned m,n;
    std::cout << "Anna eka luku: ";
    std::cin >> n;
    std::cout << "Anna toka luku: ";
    std::cin >> m;
    std::cout << n << "+" << m << "=" << a(n,m) << "\n";
    std::cout << n << "*" << m << "=" << b(n,m) << "\n";   
    std::cout << n << "^" << m << "=" << c(n,m) << "\n";
    std::cout << n << "?" << m << "=" << tetration(n,m) << "\n";

    return 0;
}
