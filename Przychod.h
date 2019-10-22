#ifndef PRZYCHOD_H
#define PRZYCHOD_H

#include <iostream>
#include "OperacjaFinansowa.h"

using namespace std;

class Przychod : public OperacjaFinansowa
{
    int idPrzychodu;

public:
    Przychod(int idPrzychodu = 0, int idUzytkownika = 0, string data = "", int dataLiczbowo=0, string opis = "", string kwota = "", double kwotaLiczbowo=0)
    {
        this->idPrzychodu = idPrzychodu;
        this->idUzytkownika = idUzytkownika;
        this->data = data;
        this->dataLiczbowo = dataLiczbowo;
        this->opis = opis;
        this->kwota = kwota;
        this->kwotaLiczbowo = kwotaLiczbowo;
    }
    bool operator () (const Przychod& p1, const Przychod& p2)
    {
        return (p1.dataLiczbowo < p2.dataLiczbowo) ? true : false;
    }
    void ustawIdPrzychodu(int noweIdPrzychodu);
    int pobierzIdPrzychodu();
};

#endif
