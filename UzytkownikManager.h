#ifndef UZYTKOWNIKMENEDZER_H
#define UZYTKOWNIKMENEDZER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>

#include "Uzytkownik.h"
//#include "PlikZUzytkownikami.h"

using namespace std;

class UzytkownikManager
{
    int idZalogowanegoUzytkownika;
    vector <Uzytkownik> uzytkownicy;

    Uzytkownik podajDaneNowegoUzytkownika();
    int pobierzIdNowegoUzytkownika();
    bool czyIstniejeLogin(string login); //OK
//        PlikZUzytkownikami plikZUzytkownikami;

    public:
    /*UzytkownikMenedzer(string nazwaPlikuZUzytkownikami) : plikZUzytkownikami(nazwaPlikuZUzytkownikami) {
        idZalogowanegoUzytkownika = 0;
        uzytkownicy = plikZUzytkownikami.wczytajUzytkownikowZPliku();
    };*/
    void rejestracjaUzytkownika(); //OK
    void wypiszWszystkichUzytkownikow(); //OK
    int logowanieUzytkownika(); // OK
    void zmianaHaslaZalogowanegoUzytkownika(); //OK
    bool czyUzytkownikJestZalogowany(); //OK
    int pobierzIdZalogowanegoUzytkownika(); //OK
    void wylogowanieUzytkownika(); //OK
};

#endif
