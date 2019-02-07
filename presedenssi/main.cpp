#include <iostream>

class oma_int
{
public:
        oma_int(int luku):luku(luku){}
        oma_int operator+(const oma_int& toinen);
        oma_int operator*(const oma_int& toinen);

private:
        int luku;
};


oma_int oma_int::operator+(const oma_int&  toinen)
{
    int tulos = luku + toinen.luku;
    std::cout << tulos << std::endl;
    return oma_int(tulos);
}

oma_int oma_int::operator*(const oma_int&  toinen)
{
    int tulos = luku * toinen.luku;
    std::cout << tulos;
    return tulos;
}



int main()
{

    oma_int a = 1;
    oma_int b = 2;
    oma_int c = 3;
    oma_int d = 4;
    (a+b)*(c+d);
    std::cout << "\n";
    return 0;
}
