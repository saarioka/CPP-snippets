/*
 * Lähde
 * https://stackoverflow.com/questions/15940978/what-is-the-size-of-each-element-in-stdlist
 *
 * luotu main & lisätty määrittely OmaSet
 * muokattu tulostukset allocate ja deallocate
 * lisätty kommentteja
 * poistettu osia
 *
 */

#include <iostream>
#include <limits>
#include <memory>
#include <set>

// Määritellään oma allocator joka tulostaa varaamansa muistin
template <typename T>
struct MyAllocator {
    typedef T value_type;
    typedef T* pointer;
    typedef std::size_t size_type;

    MyAllocator() = default;

    template <typename U>
    MyAllocator(MyAllocator<U> const&) {}

    pointer allocate(size_type n, void const* = 0) {
        pointer p = reinterpret_cast<pointer>(malloc(n * sizeof(value_type)));
        std::cout << sizeof(value_type) << " tavua\n";
        return p;
    }

    void deallocate(pointer p, size_type n) {
        if(n){}; // "unused parameter"
        free(p);
    }

    template <typename U, typename... Args>
    void construct(U* p, Args&&... args) { ::new ((void*)p) U (std::forward<Args>(args)...); }

    template <typename U>
    void destroy(U* p) { p->~U(); }

};

/* Itse luotu set, jossa allocatorina toimii äsken luotu allocator
 *
 * http://en.cppreference.com/w/cpp/container/set:
 *
 * template<
 *    class Key,
 *    class Compare = std::less<Key>,
 *    class Allocator = std::allocator<Key>
 * > class set;
 *
*/
template <typename T>
using OmaSet = std::set<T, std::less<T>, MyAllocator<T>>;

int main() {

    // char 1 tavu
    OmaSet<char> shari;
    std::cout << "char (" << sizeof(char) <<" tavua) -> ";
    shari.insert('a');

    // integer 4 tavua
    OmaSet<int> intti;
    std::cout << "integer (" << sizeof(int) <<" tavua) -> "; intti.insert(1);

    // double 8 tavua
    OmaSet<double> tupla;
    std::cout << "double (" << sizeof(double) <<" tavua) -> "; tupla.insert(1);

    // long double 12 tavua
    OmaSet<long double> pitkatupla;
    std::cout << "long double (" << sizeof(long double) <<" tavua) -> "; pitkatupla.insert(1);



    // set on toteutettu binääripuuna -> osoittimia
    std::cout << "\n\nYksi osoitin vie tilaa " << sizeof(char*) << " tavua\n";
    // Tilankäyttö voidaan selittää data alignmentilla.
    // tietueisiin kuuluu osoittimia, joiden koko on 4
}


/*
 * OHJELMA TULOSTAA:
 *
 *
char (1 tavua) -> 20 tavua
integer (4 tavua) -> 20 tavua
double (8 tavua) -> 24 tavua
long double (12 tavua) -> 28 tavua


Yksi osoitin vie tilaa 4 tavua
Press <RETURN> to close this window...

*/
