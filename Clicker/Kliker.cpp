#include <iostream>
#include <windows.h>
#include <cmath>
#include <limits>
#include "Kliker.h"
using namespace std;
void Klik::nacisk()
{
    if(piec>=10)
    {
        money=money+(wartosc_klik*mods);
        cout<<"Zdobyles "<<wartosc_klik*mods<<" ciastek"<<endl;
        piec=0;
        money=money+mods*cns/4;
        Sleep(200);

        menu();
    }
    else
    {
        piec=piec+1;
        cout<<"Piec sie laduje..."<<endl<<piec*10<<"% naladowania";
        money=money+mods*cns/8;
        Sleep(100);
        menu();
    }
}
void Klik::wypis()
{
    cout<<wartosc_klik<<" "<<mods<<" "<<money;
}
void Klik::menu()
{
    system("CLS");
    money=ceil(money*100)/100;
    cout<<"Obecnie masz -"<<money<<"- ciastek"<<endl;
    cout<<"Aby otworzyc sklep kliknij 1"<<endl;
    cout<<"Aby pokazac moc pieca i modyfikatory kliknij 2"<<endl;
    cout<<"-------------------------------------------------------------"<<endl;
    if(money>=1000&&!achievement[0])
        {
            achievement[0]=1;
            wartosc_klik+=10;
            cout<<"Zdobyles osiagniecie 1! Twoja moc zwiekszyla sie o 10!"<<endl;
            money=money+mods*cns*3;
            Sleep(2500);
        }
        if(money>=100000&&!achievement[1])
        {
            achievement[1]=1;
            wartosc_klik+=100;
            cout<<"Zdobyles osiagniecie 2! Twoja moc zwiekszyla sie o 100!"<<endl;
            money=money+mods*cns*3;
            Sleep(2500);
        }
        if(cns>=1000&&!achievement[2])
        {
            achievement[2]=1;
            cns+=10;
            cout<<"Zdobyles osiagniecie 3! Twoja ciastka na sekunde zwiekszyly sie o 10!"<<endl;
            money=money+mods*cns*3;
            Sleep(2500);
        }
        if(money>=std::numeric_limits<float>::max()&&!achievement[3])
        {
            achievement[3]=1;
            wartosc_klik+=10;
            cout<<"Zdobyles osiagniecie 4! Masz nieskonczona ilosc ciastek!"<<endl;
            money=money+mods*cns*3;
            Sleep(2500);
        }
    if(GetAsyncKeyState('1'))
    {
        sklep();
    }

    if(GetAsyncKeyState('2'))
    {
        profil();
    }
    if(GetAsyncKeyState('A'))
        nacisk();
    money=money+(mods*cns/7);
    Sleep(100);
    menu();
}
void Klik::sklep()
{
    system("CLS");
    cout<<"SKLEP"<<endl;
    cout<<"1.Dmuchawa do pieca (+1 mocy pieca) -"<<(8+(bogactwo[0]*4))<<"-"<<endl;
    cout<<"2.Mocna dmuchawa do pieca (+11 mocy pieca) -"<<(80+(bogactwo[1]*40))<<"-"<<endl;
    cout<<"3.Hiper dmuchawa do pieca (+111  mocy pieca) -"<<(800+(bogactwo[2]*300))<<"-"<<endl;
    cout<<"-------------------------------------------------------------"<<endl;
    cout<<"4.Wiekszy piec (1.01x ilosc ciastek) -"<<(20+(bogactwo[3]*20))<<"-"<<endl;
    cout<<"5.Zdecydowanie wiekszy piec (1.05x ilosc ciastek) -"<<(200+(bogactwo[4]*100))<<"-"<<endl;
    cout<<"6.Obszerniejszy piec (1.2x ilosc ciastek) -"<<(2000+(bogactwo[5]*800))<<"-"<<endl;
    cout<<"-------------------------------------------------------------"<<endl;
    cout<<"7.Dziadek do pomocy (1 ciastko/s) -"<<(30+(bogactwo[6]*8))<<"-"<<endl;
    cout<<"8.Babcia do pomocy (10 ciastek/s) -"<<(300+(bogactwo[7]*80))<<"-"<<endl;
    cout<<"9.Mama do pomocy (100 ciastek/s) -"<<(3000+(bogactwo[8]*500))<<"-"<<endl;
    cout<<"-------------------------------------------------------------"<<endl;
    cout<<"0.Wyjscie"<<endl<<endl;
    cout<<"Obecnie masz -"<<money<<"- ciastek"<<endl;
    cout<<"Obecnie masz -"<<wartosc_klik<<"- mocy pieca"<<endl;
    cout<<"Obecnie masz modyfikatory -"<<mods<<"x-"<<endl;
    cout<<"Obecnie na sekunde dostajesz -"<<cns*mods<<"- ciastek"<<endl;
    cout<<"-------------------------------------------------------------"<<endl;
    money=money+mods*cns/2;
    money=ceil(money*100)/100;
    Sleep(500);
    if(GetAsyncKeyState('1'))
    {
        if(money>=(8+(bogactwo[0]*4)))
        {
            money=money-(8+(bogactwo[0]*4));
            bogactwo[0]++;
            wartosc_klik+=1;
            sklep();
        }
        else
            cout<<"Brakuje ci -"<<(8+(bogactwo[0]*4))-money<<"- ciastek";
        Sleep(1500);
        sklep();
    }
    if(GetAsyncKeyState('2'))
    {
        if(money>=(80+(bogactwo[1]*40)))
        {
            money=money-(80+(bogactwo[1]*40));
            bogactwo[1]++;
            wartosc_klik+=11;
            sklep();
        }
        else
            cout<<"Brakuje ci -"<<(80+(bogactwo[1]*40))-money<<"- ciastek";
        Sleep(1500);
        sklep();
    }
    if(GetAsyncKeyState('3'))
    {
        if(money>=(800+(bogactwo[2]*300)))
        {
            money=money-(800+(bogactwo[2]*300));
            bogactwo[2]++;
            wartosc_klik+=111;
            sklep();
        }
        else
            cout<<"Brakuje ci -"<<(800+(bogactwo[2]*300))-money<<"- ciastek";
        Sleep(1500);
        sklep();
    }
    if(GetAsyncKeyState('4'))
    {
        if(money>=(20+(bogactwo[3]*20)))
        {
            money=money-(20+(bogactwo[3]*20));
            bogactwo[3]++;
            mods*=1.01;
            sklep();
        }
        else
            cout<<"Brakuje ci -"<<(20+(bogactwo[3]*20))-money<<"- ciastek";
        Sleep(1500);
        sklep();
    }
    if(GetAsyncKeyState('5'))
    {
        if(money>=(200+(bogactwo[4]*100)))
        {
            money=money-(200+(bogactwo[4]*100));
            bogactwo[4]++;
            mods*=1.1;
            sklep();
        }
        else
            cout<<"Brakuje ci -"<<(200+(bogactwo[4]*60))-money<<"- ciastek";
        Sleep(1500);
        sklep();
    }
    if(GetAsyncKeyState('6'))
    {
        if(money>=(2000+(bogactwo[5]*800)))
        {
            money=money-(2000+(bogactwo[5]*800));
            bogactwo[5]++;
            mods*=1.2;
            sklep();
        }
        else
            cout<<"Brakuje ci -"<<(2000+(bogactwo[5]*800))-money<<"- ciastek";
        Sleep(1500);
        sklep();

    }
    if(GetAsyncKeyState('7'))
    {
        if(money>=(30+(bogactwo[6]*8)))
        {
            money=money-(30+(bogactwo[6]*8));
            bogactwo[6]++;
            cns+=1;
            sklep();
        }
        else
            cout<<"Brakuje ci -"<<(30+(bogactwo[6]*8))-money<<"- ciastek";
        Sleep(1500);
        sklep();

    }
    if(GetAsyncKeyState('8'))
    {
        if(money>=(300+(bogactwo[7]*80)))
        {
            money=money-(300+(bogactwo[7]*80));
            bogactwo[7]++;
            cns+=10;
            sklep();
        }
        else
            cout<<"Brakuje ci -"<<(300+(bogactwo[7]*80))-money<<"- ciastek";
        Sleep(1500);
        sklep();

    }
    if(GetAsyncKeyState('9'))
    {
        if(money>=(3000+(bogactwo[8]*500)))
        {
            money=money-(3000+(bogactwo[8]*500));
            bogactwo[8]++;
            cns+=100;
            sklep();
        }
        else
            cout<<"Brakuje ci -"<<(3000+(bogactwo[8]*500))-money<<"- ciastek";
        Sleep(1500);
        sklep();

    }
    if(GetAsyncKeyState('0'))
        menu();
    if(GetAsyncKeyState('A')&&!achievement[4])
    {
        achievement[4]=1;
        cout<<"Zdobyles sekretne osiagniecie!";
        Sleep(2500);
    }
    sklep();
}
void Klik::profil()
{
    system("CLS");
    cout<<"Twoja moc pieca to -"<<wartosc_klik<<"-"<<endl;
    cout<<"A modyfikatory to -"<<mods<<"x-"<<endl;
    cout<<"A ciastka na sekunde to -"<<cns*mods<<"-"<<endl;
    if(achievement[0])
        cout<<"Zdobyles osiagniecie 1!"<<endl;
    else
        cout<<"Zdobadz 1k ciastek aby zdobyc osiagniecie"<<endl;
    cout<<"-------------------------------------------------------------"<<endl;
    if(achievement[1])
        cout<<"Zdobyles osiagniecie 2!"<<endl;
    else
        cout<<"Zdobadz 100k ciastek aby zdobyc osiagniecie"<<endl;
    cout<<"-------------------------------------------------------------"<<endl;
    if(achievement[2])
        cout<<"Zdobyles osiagniecie 3!"<<endl;
    else
        cout<<"Zarabiaj 1k ciastek na sekunde aby zdobyc osiagniecie"<<endl;
    cout<<"-------------------------------------------------------------"<<endl;
    if(achievement[3])
        cout<<"Zdobyles osiagniecie 4!"<<endl;
    else
        cout<<"Zdobadz nieskonczonosc ciastek aby zdobyc osiagniecie"<<endl;
    cout<<"-------------------------------------------------------------"<<endl;
    if(achievement[4])
        cout<<"Zdobyles sekretne osiagniecie!"<<endl;
    else
        cout<<"Sekretne osiagniecie"<<endl;
    cout<<"-------------------------------------------------------------"<<endl;
    system("PAUSE");
    menu();
}
Klik::Klik(int w,float mod,float m,int p, float cn)
{
    wartosc_klik=w;
    money=m;
    mods=mod;
    for(int a=0;a<5;a++)
        achievement[a]=0;
    piec=p;
    for(int a=0;a<9;a++)
        bogactwo[a]=0;
    cns=cn;
    cout<<"Aby ladowac piec ktory piecze ciastka trzymaj klawisz A"<<endl;
    Sleep(2500);
    menu();
}
