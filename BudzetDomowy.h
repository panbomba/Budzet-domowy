#ifndef BUDZETDOMOWY_H
#define KBUDZETDOMOWY_H

#include <iostream>

#include "UzytkownikManager.h"
#include "ManagerFinansow.h"

using namespace std;

class BudzetDomowy
{
    UzytkownikManager uzytkownikManager;
    ManagerFinansow *managerFinansow;
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
    void wypiszWszystkichUzytkownikow(); //TO POTRZEBUJE GLOWNIE DO TESTOW
    int logowanieUzytkownika();
    void zmianaHaslaZalogowanegoUzytkownika();
    void wylogowanieUzytkownika();
    void dodajPrzychod(); //DODAJ PRZYCHOD/WYDATEK
    void dodajWydatek();
    void wyswietlWszystkichAdresatow (); //TO BEDZIE WYSWIETLANIE TRANSAKCJI ZA WYBRANY OKRES
    char wybierzOpcjeZMenuUzytkownika();
};

#endif
