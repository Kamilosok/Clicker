#include <iostream>

using namespace std;
class Klik
{
    int wartosc_klik;
    float mods;
    float money;
    bool achievement[5];
    int piec;
    int bogactwo[9];
    float cns;
    public:
    void nacisk();
    void wypis();
    void menu();
    void sklep();
    void profil();
    Klik(int=1,float=1,float=0,int=0,float=0);
};
