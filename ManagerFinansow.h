#ifndef MANAGERFINANSOW_H
#define  MANAGERFINANSOW_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <sstream>

#include "Przychod.h"
#include "Wydatek.h"
//#include "PlikZAdresatami.h"

using namespace std;

class ManagerFinansow
{
    const int ID_ZALOGOWANEGO_UZYTKOWNIKA; //OK
    vector <Przychod> przychody;
    vector <Wydatek> wydatki;
    //PlikZPrzychodami plikZPrzychodami;
    //PlikZWydatkami plikZWydatkami;

    Przychod podajDanePrzychodu();
    Wydatek podajDaneWydatku();
    void wyswietlDanePrzychodu(Przychod przychod); // NA POTRZEBY TESTOW
    void wyswietlDaneWydatku(Wydatek wydatek); // NA POTRZEBY TESTOW

    public:
    /*ManagerFinansow(string nazwaPlikuZAdresatami, int idZalogowanegoUzytkownika)
        : plikZAdresatami(nazwaPlikuZAdresatami), ID_ZALOGOWANEGO_UZYTKOWNIKA(idZalogowanegoUzytkownika)
    {
    adresaci = plikZAdresatami.wczytajAdresatowZalogowanegoUzytkownikaZPliku(ID_ZALOGOWANEGO_UZYTKOWNIKA);
    };*/
    void dodajPrzychod();
    void dodajWydatek();
    //void wyswietlWszystkichAdresatow(); WYSWIETL WSZYSTKIE TRANSAKCJE Z DANEGO OKRESU?
};

#endif
