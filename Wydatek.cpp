#include "Wydatek.h"

void Wydatek::ustawIdWydatku(int noweIdWydatku)
{
    if (noweIdWydatku >= 0)
        idWydatku = noweIdWydatku;
}

void Wydatek::ustawIdUzytkownika(int idZalogowanegoUzytkownika)
{
    idUzytkownika = idZalogowanegoUzytkownika;
}
void Wydatek::ustawDate(string nowaData)
{
    data = nowaData;
}

void Wydatek::ustawOpis(string nowyOpis)
{
    opis = nowyOpis;
}

void Wydatek::ustawKwote(float nowaKwota)
{
    kwota = nowaKwota;
}

int Wydatek::pobierzIdWydatku()
{
    return idWydatku;
}
int Wydatek::pobierzIdUzytkownika()
{
    return idUzytkownika;
}
string Wydatek::pobierzDate()
{
    return data;
}

string Wydatek::pobierzOpis()
{
    return opis;
}

float Wydatek::pobierzKwote()
{
    return kwota;
}
