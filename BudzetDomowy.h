#ifndef BUDZETDOMOWY_H
#define KBUDZETDOMOWY_H

#include <iostream>

#include "UzytkownikManager.h"
//#include "AdresatMenedzer.h"

using namespace std;

class BudzetDomowy
{
    UzytkownikManager uzytkownikManager;
    //AdresatMenedzer *adresatMenedzer;
    //const string NAZWA_PLIKU_Z_ADRESATAMI;

public:
    /*KsiazkaAdresowa(string nazwaPlikuZUzytkownikami, string nazwaPlikuZAdresatami)
        : uzytkownikMenedzer(nazwaPlikuZUzytkownikami), NAZWA_PLIKU_Z_ADRESATAMI(nazwaPlikuZAdresatami)
         {
        adresatMenedzer = NULL;
    };*/

    /*~BudzetDomowy()
    {
        delete adresatMenedzer;
        adresatMenedzer = NULL;
    }*/

    void rejestracjaUzytkownika();
    void wypiszWszystkichUzytkownikow();
    int logowanieUzytkownika();
    void zmianaHaslaZalogowanegoUzytkownika();
    void wylogowanieUzytkownika();
    void dodajAdresata ();
    void wyswietlWszystkichAdresatow ();
    char wybierzOpcjeZMenuUzytkownika();
    void usunAdresata();
    void edytujAdresata();
};

#endif
