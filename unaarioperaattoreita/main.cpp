#include <iostream>

int main()
{
    int i = 5;
    int j = 3;

    std::cout << i-j << ", i=" << i << " j=" << j
              << "   -> tulostuu i-j" << std::endl;

    i=5;j=3;
    std::cout << i-- -j << ", i=" << i << " j=" << j
              << "   -> tulostuu i-j, i pienenee laskun jalkeen" << std::endl;

    i=5;j=3;
    std::cout << i- --j << ", i=" << i << " j=" << j
              << "   -> tulostuu i-(j-1), j pienenee ennen laskua" << std::endl;

    i=5;j=3;
    std::cout << i-- - --j << ", i=" << i << " j=" << j
              << "   -> tulostuu i-(j-1), j pienenee ennen laskua ja i laskun jalkeen" << std::endl;

    i=5;j=3;
    std::cout << i - - j << ", i=" << i << " j=" << j
              << "   -> tulostuu i+j" << std::endl;
    i=5;j=3;

    std::cout << i-- - - j << ", i=" << i << " j=" << j
              << "   -> tulostuu i-(-j), i pienenee laskun jalkeen" << std::endl;

    i=5;j=3;
    std::cout << i - - --j << ", i=" << i << " j=" << j
              << "   -> tulostuu i+(j-1), j pienenee ennen laskua" << std::endl;

    i=5;j=3;
    std::cout << i-- - - --j << ", i=" << i << " j=" << j
              << "   -> tulostuu i+(j-1), j pienenee ennen laskua ja i laskun jalkeen" << std::endl << std::endl;

    i=5;j=3;
    std::cout << "Keskella olevien miinusten maara kertoo, tehdaanko yhteen, vai vahennyslasku" << std::endl
              << "(Pariton -> miinus, parillinen -> plus)" << std::endl << std::endl;

    std::cout << i - - - - - - - - - - j << ", i=" << i << " j=" << j
              << "   -> tulostuu i+j" << std::endl;

    i=5;j=3;
    std::cout << i - - - - - - - - - j << ", i=" << i << " j=" << j
              << "   -> tulostuu i-j" << std::endl << std::endl;

    i=5;j=3;
    std::cout << "Erilaisia lopputulemia on 8 kpl." << std::endl;

    return 0;
}
