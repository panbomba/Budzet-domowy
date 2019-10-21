#ifndef WYDATEK_H
#define WYDATEK_H

#include <iostream>

using namespace std;

class Wydatek
{
    int idWydatku;
    int idUzytkownika;
    string data, opis, kwota;
    int dataLiczbowo;
    double kwotaLiczbowo;

public:
    Adresat(int idWydatku = 0, int idUzytkownika = 0, string data = "", int dataLiczbowo=0, string opis = "", string kwota = "", double kwotaLiczbowo=0)
    {
        this->idWydatku = idWydatku;
        this->idUzytkownika = idUzytkownika;
        this->data = data;
        this->dataLiczbowo = dataLiczbowo;
        this->opis = opis;
        this->kwota = kwota;
        this->kwotaLiczbowo = kwotaLiczbowo;
    }
    void ustawIdWydatku(int noweIdWydatku);
    void ustawIdUzytkownika(int IdZalogowanegoUzytkownika);
    void ustawDate(string nowaData);
    void ustawDateLiczbowo(int dataLiczbowo);
    void ustawOpis(string nowyOpis);
    void ustawKwote(string nowaKwota);
    void ustawKwoteLiczbowo (double nowaKwotaLiczbowo);

    int pobierzIdWydatku();
    int pobierzIdUzytkownika();
    string pobierzDate();
    int pobierzDateLiczbowo();
    string pobierzOpis();
    string pobierzKwote();
    double pobierzKwoteLiczbowo();
};

#endif
