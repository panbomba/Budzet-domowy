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
    BudzetDomowy(string nazwaPlikuZUzytkownikami = "users.xml");
    // {uzytkownikManager.wczytajDaneUzytkownikowZPliku();
    //};
        /*: uzytkownikMenedzer(nazwaPlikuZUzytkownikami), NAZWA_PLIKU_Z_ADRESATAMI(nazwaPlikuZAdresatami)
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
    void dodajPrzychod(); //DODAJ PRZYCHOD/WYDATEK
    void dodajWydatek();
    void wyswietlWszystkichAdresatow (); //TO BEDZIE WYSWIETLANIE TRANSAKCJI ZA WYBRANY OKRES
    char wybierzOpcjeZMenuUzytkownika();
    bool czyUzytkownikJestZalogowany();
};

#endif
