#include <iostream>

using namespace std;

void vaihda( int &x, int &y ){
    x^=y; // 1010 XOR 0011 = 1001 = x XOR y, välitulos
    y^=x; // 1001 XOR 0011 = 1010 = x
    x^=y; // 1001 XOR 1010 = 0011 = y
}
/*
Kikka toimii, koska XOR:n voi perua tekemällä sen uudestaan
-> rivillä 6 x:n arvoksi tulee x XOR y eli välitulos, josta saadaan y
komennolla XOR x ja x komennolla XOR y
*/

int main()
{
    int a = 10; // 1010
    int b = 3;  // 0011
    vaihda(a,b);
    cout << a << ", " << b << "\n";

    int c = 2;
    vaihda(c,c);
    cout << c << ", " << c << "\n";

    return 0;
}
