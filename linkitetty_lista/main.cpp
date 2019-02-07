#include<iostream>

using namespace std;

struct alkio{
    int luku;
    alkio *seur;
};

class Lista{

    private:
        alkio *eka;
        alkio *vika;

    public:
        Lista(int arvo){
            alkio *apu=new alkio;
            apu->luku=arvo;
            apu->seur=nullptr;
            eka=apu;
            vika=apu;
        }

        void lisaaLoppuun(int arvo){
            alkio *apu=new alkio;
            apu->luku=arvo;
            vika->seur=apu;
            apu->seur=eka;
            vika=apu;
        }

        void lisaaAlkuun(int arvo){
            alkio *apu=new alkio;
            apu->luku=arvo;
            vika->seur=apu;
            apu->seur=eka;
            eka=apu;
        }

        // tulostaa i alkiota
        void tulosta(int i){
            alkio *apu=new alkio;
            apu=eka;
            cout << "Alkiot:\n";
            while(i>=0)
            {
                cout<<apu->luku<< "\n";
                apu=apu->seur;
                i--;
            }
            cout << "\n";
        }

        void poistaEka(){
            alkio *apu=new alkio;
            apu=eka;
            eka=eka->seur;
            vika->seur=eka;
            delete apu;
        }

        // Vastaava metodi kuin std::vectorissa,
        // paitsi tämä palauttaa viimeisen osoitteen
        alkio* data(){
            return vika;
        }

};

int main()
{
    Lista lista(11);
    lista.lisaaLoppuun(20);
    lista.lisaaLoppuun(30);
    lista.tulosta(6);

    cout << "Viimeiseksi lisatty alkio: " << lista.data()->luku << "\n\n\n";

    lista.lisaaLoppuun(40);
    lista.tulosta(6);

    cout << "Viimeiseksi lisatty alkio: " << lista.data()->luku << "\n\n\n";

    cout << "Lisataan alkuun 99:\n\n";
    lista.lisaaAlkuun(99);
    lista.tulosta(6);

    cout << "\nPoistetaan eka:\n\n";
    lista.poistaEka();
    lista.tulosta(6);

    return 0;
}
