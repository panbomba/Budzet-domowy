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

void Wydatek::ustawDateLiczbowo(int nowaDataLiczbowo)
{
    dataLiczbowo = nowaDataLiczbowo;
}

void Wydatek::ustawOpis(string nowyOpis)
{
    opis = nowyOpis;
}

void Wydatek::ustawKwote(string nowaKwota)
{
    kwota = nowaKwota;
}

void Wydatek::ustawKwoteLiczbowo(double nowaKwotaLiczbowo)
{
    kwotaLiczbowo = nowaKwotaLiczbowo;
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

int Wydatek::pobierzDateLiczbowo()
{
    return dataLiczbowo;
}

string Wydatek::pobierzOpis()
{
    return opis;
}

string Wydatek::pobierzKwote()
{
    return kwota;
}

double Wydatek::pobierzKwoteLiczbowo()
{
    return kwotaLiczbowo;
}
