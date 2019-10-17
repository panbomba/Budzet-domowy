#ifndef PRZYCHOD_H
#define PRZYCHOD_H

#include <iostream>

using namespace std;

class Przychod
{
    int idPrzychodu;
    int idUzytkownika;
    string data, opis; //CZY DATA STRING CZY INT?
    float kwota;

public:
    Adresat(int idPrzychodu = 0, int idUzytkownika = 0, string data = "", string opis = "", float kwota = 0)
    {
        this->idPrzychodu = idPrzychodu;
        this->idUzytkownika = idUzytkownika;
        this->data = data;
        this->opis = opis;
        this->kwota = kwota;
    }
    void ustawIdPrzychodu(int noweIdPrzychodu);
    void ustawIdUzytkownika(int IdZalogowanegoUzytkownika);
    void ustawDate(string nowaData);
    void ustawOpis(string nowyOpis);
    void ustawKwote(float nowaKwota);

    int pobierzIdPrzychodu();
    int pobierzIdUzytkownika();
    string pobierzDate();
    string pobierzOpis();
    float pobierzKwote();
};

#endif
