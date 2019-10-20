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

    PlikZWydatkami plikZWydatkami;
    PlikZPrzychodami plikZPrzychodami;

    Przychod podajDanePrzychodu();
    Wydatek podajDaneWydatku();

    public:
    ManagerFinansow(string nazwaPlikuZPrzychodami, string nazwaPlikuZWydatkami, int idZalogowanegoUzytkownika)
            : plikZPrzychodami(nazwaPlikuZPrzychodami), plikZWydatkami(nazwaPlikuZWydatkami), ID_ZALOGOWANEGO_UZYTKOWNIKA(idZalogowanegoUzytkownika)
    {
    przychody = plikZPrzychodami.wczytajPrzychodyZalogowanegoUzytkownikaZPliku(ID_ZALOGOWANEGO_UZYTKOWNIKA);
    wydatki = plikZWydatkami.wczytajWydatkiZalogowanegoUzytkownikaZPliku(ID_ZALOGOWANEGO_UZYTKOWNIKA);
    };

    void dodajPrzychod();
    void dodajWydatek();
    void wypiszPrzychodyZalogowanegoUzytkownika(); //UZYWAM TYLKO DO TESTOW
    void wypiszWydatkiZalogowanegoUzytkownika(); //UZYWAM TYLKO DO TESTO
};

#endif
