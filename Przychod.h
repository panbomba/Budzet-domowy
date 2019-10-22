#ifndef PRZYCHOD_H
#define PRZYCHOD_H

#include <iostream>

using namespace std;

class Przychod
{
    int idPrzychodu;
    int idUzytkownika;
    string data, opis, kwota;
    int dataLiczbowo;
    double kwotaLiczbowo;

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
    void ustawIdUzytkownika(int IdZalogowanegoUzytkownika);
    void ustawDate(string nowaData);
    void ustawDateLiczbowo(int dataLiczbowo);
    void ustawOpis(string nowyOpis);
    void ustawKwote(string nowaKwota);
    void ustawKwoteLiczbowo(double nowaKwotaLiczbowo);

    int pobierzIdPrzychodu();
    int pobierzIdUzytkownika();
    string pobierzDate();
    int pobierzDateLiczbowo();
    string pobierzOpis();
    string pobierzKwote();
    double pobierzKwoteLiczbowo();
};

#endif
