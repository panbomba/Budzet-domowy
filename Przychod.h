#ifndef PRZYCHOD_H
#define PRZYCHOD_H

#include <iostream>

using namespace std;

class Przychod
{
    int idPrzychodu;
    int idUzytkownika;
    string data, opis, kwota; //CZY DATA STRING CZY INT?
    double kwotaLiczbowo;

public:
    Adresat(int idPrzychodu = 0, int idUzytkownika = 0, string data = "", string opis = "", string kwota = "")
    {
        this->idPrzychodu = idPrzychodu;
        this->idUzytkownika = idUzytkownika;
        this->data = data;
        this->opis = opis;
        this->kwota = kwota;
        this->kwotaLiczbowo = kwotaLiczbowo;
    }
    void ustawIdPrzychodu(int noweIdPrzychodu);
    void ustawIdUzytkownika(int IdZalogowanegoUzytkownika);
    void ustawDate(string nowaData);
    void ustawOpis(string nowyOpis);
    void ustawKwote(string nowaKwota);
    void ustawKwoteLiczbowo(double nowaKwotaLiczbowo);

    int pobierzIdPrzychodu();
    int pobierzIdUzytkownika();
    string pobierzDate();
    string pobierzOpis();
    string pobierzKwote();
    double pobierzKwoteLiczbowo();
};

#endif
