#ifndef UZYTKOWNIKMANAGER_H
#define UZYTKOWNIKMANAGER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>

#include "Uzytkownik.h"
#include "PlikZUzytkownikami.h"

using namespace std;

class UzytkownikManager
{
    int idZalogowanegoUzytkownika;
    vector <Uzytkownik> uzytkownicy;

    Uzytkownik podajDaneNowegoUzytkownika();
    int pobierzIdNowegoUzytkownika();
    bool czyIstniejeLogin(string login); //OK


    PlikZUzytkownikami plikZUzytkownikami;

    public:
    UzytkownikManager(string nazwaPlikuZUzytkownikami) : plikZUzytkownikami(nazwaPlikuZUzytkownikami) {
        idZalogowanegoUzytkownika = 0;
        uzytkownicy = plikZUzytkownikami.wczytajUzytkownikowZPliku();
    };
    void rejestracjaUzytkownika(); //OK
    void wypiszWszystkichUzytkownikow(); //OK
    void logowanieUzytkownika(); // OK
    void zmianaHaslaZalogowanegoUzytkownika(); //OK
    bool czyUzytkownikJestZalogowany(); //OK
    int pobierzIdOstatniegoUzytkownika(); //OK
    void wylogowanieUzytkownika(); //OK
    void wczytajUzytkownikowZPliku();
    int pobierzIdZalogowanegoUzytkownika();


};

#endif
