#ifndef WYDATEK_H
#define WYDATEK_H

#include <iostream>

using namespace std;

class Wydatek
{
    int idWydatku;
    int idUzytkownika;
    string data, opis; //CZY DATA STRING CZY INT?
    float kwota;

public:
    Adresat(int idWydatku = 0, int idUzytkownika = 0, string data = "", string opis = "", float kwota = 0)
    {
        this->idWydatku = idWydatku;
        this->idUzytkownika = idUzytkownika;
        this->data = data;
        this->opis = opis;
        this->kwota = kwota;
    }
    void ustawIdWydatku(int noweIdWydatku);
    void ustawIdUzytkownika(int IdZalogowanegoUzytkownika);
    void ustawDate(string nowaData);
    void ustawOpis(string nowyOpis);
    void ustawKwote(float nowaKwota);

    int pobierzIdWydatku();
    int pobierzIdUzytkownika();
    string pobierzDate();
    string pobierzOpis();
    float pobierzKwote();
};

#endif
