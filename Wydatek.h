#ifndef WYDATEK_H
#define WYDATEK_H

#include <iostream>
#include "OperacjaFinansowa.h"

using namespace std;

class Wydatek : public OperacjaFinansowa
{
    int idWydatku;

public:
    Wydatek(int idWydatku = 0, int idUzytkownika = 0, string data = "", int dataLiczbowo=0, string opis = "", string kwota = "", double kwotaLiczbowo=0)
    {
        this->idWydatku = idWydatku;
        this->idUzytkownika = idUzytkownika;
        this->data = data;
        this->dataLiczbowo = dataLiczbowo;
        this->opis = opis;
        this->kwota = kwota;
        this->kwotaLiczbowo = kwotaLiczbowo;
    }
    bool operator () (const Wydatek& w1, const Wydatek& w2)
    {
        return (w1.dataLiczbowo < w2.dataLiczbowo) ? true : false;
    }
    void ustawIdWydatku(int noweIdWydatku);
    int pobierzIdWydatku();
};

#endif
