#ifndef OPERACJAFINANSOWA_H
#define OPERACJAFINANSOWA_H

#include <iostream>

using namespace std;

class OperacjaFinansowa
{
    public:
    int idUzytkownika;
    string data, opis, kwota;
    int dataLiczbowo;
    double kwotaLiczbowo;

    void ustawIdUzytkownika(int IdZalogowanegoUzytkownika);
    void ustawDate(string nowaData);
    void ustawDateLiczbowo(int dataLiczbowo);
    void ustawOpis(string nowyOpis);
    void ustawKwote(string nowaKwota);
    void ustawKwoteLiczbowo(double nowaKwotaLiczbowo);

    int pobierzIdUzytkownika();
    string pobierzDate();
    int pobierzDateLiczbowo();
    string pobierzOpis();
    string pobierzKwote();
    double pobierzKwoteLiczbowo();
};

#endif
