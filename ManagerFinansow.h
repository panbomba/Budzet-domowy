#ifndef MANAGERFINANSOW_H
#define MANAGERFINANSOW_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <sstream>

#include "Przychod.h"
#include "Wydatek.h"
#include "ObslugaPlikowXML.h"

using namespace std;

class ManagerFinansow
{
    //const int ID_ZALOGOWANEGO_UZYTKOWNIKA; //OK
    int idZalogowanegoUzytkownika = 0;

    vector <Przychod> przychody;
    vector <Wydatek> wydatki;
    //PlikZPrzychodami plikZPrzychodami;
    //PlikZWydatkami plikZWydatkami;

    Przychod podajDanePrzychodu();
    Wydatek podajDaneWydatku();
    void wyswietlDanePrzychodu(Przychod przychod); // NA POTRZEBY TESTOW
    void wyswietlDaneWydatku(Wydatek wydatek); // NA POTRZEBY TESTOW

    public:
        //ManagerFinansow(int idZalogowanegoUzytkownika = budzetDomowy.pobierzIdZalogowanegoUzytkownika() );
    /*ManagerFinansow(string nazwaPlikuZAdresatami, int idZalogowanegoUzytkownika)
        : plikZAdresatami(nazwaPlikuZAdresatami), ID_ZALOGOWANEGO_UZYTKOWNIKA(idZalogowanegoUzytkownika)
    {
    adresaci = plikZAdresatami.wczytajAdresatowZalogowanegoUzytkownikaZPliku(ID_ZALOGOWANEGO_UZYTKOWNIKA);
    };*/
    void dodajPrzychod(int idZalogowanegoUzytkownika);
    void dodajWydatek();
    int pobierzIdNowegoPrzychodu();
    //void wyswietlWszystkichAdresatow(); WYSWIETL WSZYSTKIE TRANSAKCJE Z DANEGO OKRESU?
};

#endif
