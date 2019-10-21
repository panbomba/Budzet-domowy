#ifndef WYDATEK_H
#define WYDATEK_H

#include <iostream>

using namespace std;

class Wydatek
{
    int idWydatku;
    int idUzytkownika;
    string data, opis, kwota; //CZY DATA STRING CZY INT?
    double kwotaLiczbowo;

public:
    Adresat(int idWydatku = 0, int idUzytkownika = 0, string data = "", string opis = "", string kwota = "")
    {
        this->idWydatku = idWydatku;
        this->idUzytkownika = idUzytkownika;
        this->data = data;
        this->opis = opis;
        this->kwota = kwota;
        this->kwotaLiczbowo = kwotaLiczbowo;
    }
    void ustawIdWydatku(int noweIdWydatku);
    void ustawIdUzytkownika(int IdZalogowanegoUzytkownika);
    void ustawDate(string nowaData);
    void ustawOpis(string nowyOpis);
    void ustawKwote(string nowaKwota);
    void ustawKwoteLiczbowo (double nowaKwotaLiczbowo);

    int pobierzIdWydatku();
    int pobierzIdUzytkownika();
    string pobierzDate();
    string pobierzOpis();
    string pobierzKwote();
    double pobierzKwoteLiczbowo();
};

#endif
