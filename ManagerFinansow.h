#ifndef MANAGERFINANSOW_H
#define MANAGERFINANSOW_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <sstream>

#include "Przychod.h"
#include "Wydatek.h"
#include "ObslugaPlikowXML.h"
#include "PlikZPrzychodami.h"
#include "PlikZWydatkami.h"

using namespace std;

class ManagerFinansow
{
    const int ID_ZALOGOWANEGO_UZYTKOWNIKA;
    vector <Przychod> przychody;
    vector <Wydatek> wydatki;
    PlikZPrzychodami plikZPrzychodami;
    PlikZWydatkami plikZWydatkami;

    Przychod podajDanePrzychodu();
    Wydatek podajDaneWydatku();
    //void wyswietlDanePrzychodu(Przychod przychod); // NA POTRZEBY TESTOW
    //void wyswietlDaneWydatku(Wydatek wydatek); // NA POTRZEBY TESTOW

    public:
    ManagerFinansow(string nazwaPlikuZPrzychodami, string nazwaPlikuZWydatkami, int idZalogowanegoUzytkownika)
            : plikZPrzychodami(nazwaPlikuZPrzychodami), plikZWydatkami(nazwaPlikuZWydatkami), ID_ZALOGOWANEGO_UZYTKOWNIKA(idZalogowanegoUzytkownika)
    {
    //adresaci = plikZAdresatami.wczytajAdresatowZalogowanegoUzytkownikaZPliku(ID_ZALOGOWANEGO_UZYTKOWNIKA);
    };

    void dodajPrzychod(); //POPRAWIC ID PRZYCHODU
    void dodajWydatek(); //POPRAWIC ID WYDATKU
    int pobierzIdNowegoPrzychodu();
    int pobierzIdNowegoWydatku();
    //void wyswietlWszystkichAdresatow(); WYSWIETL WSZYSTKIE TRANSAKCJE Z DANEGO OKRESU?
};

#endif
