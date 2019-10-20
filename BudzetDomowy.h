#ifndef BUDZETDOMOWY_H
#define BUDZETDOMOWY_H

#include <iostream>

#include "UzytkownikManager.h"
#include "ManagerFinansow.h"

using namespace std;

class BudzetDomowy
{
    UzytkownikManager uzytkownikManager;
    ManagerFinansow *managerFinansow; //w tym momencie tworzy sie obiekt
    const string NAZWA_PLIKU_Z_PRZYCHODAMI;
    const string NAZWA_PLIKU_Z_WYDATKAMI;

public:
    BudzetDomowy(string nazwaPlikuZUzytkownikami, string nazwaPlikuZPrzychodami, string nazwaPlikuZWydatkami)
        : uzytkownikManager(nazwaPlikuZUzytkownikami), NAZWA_PLIKU_Z_PRZYCHODAMI(nazwaPlikuZPrzychodami), NAZWA_PLIKU_Z_WYDATKAMI(nazwaPlikuZWydatkami)
    {
        managerFinansow = NULL;
    };

    ~BudzetDomowy()
    {
        delete managerFinansow;
        managerFinansow = NULL;
    }

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
    int pobierzIdZalogowanegoUzytkownika();
};

#endif
