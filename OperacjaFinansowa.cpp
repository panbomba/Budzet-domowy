#include "OperacjaFinansowa.h"

void OperacjaFinansowa::ustawIdUzytkownika(int idZalogowanegoUzytkownika)
{
    idUzytkownika = idZalogowanegoUzytkownika;
}
void OperacjaFinansowa::ustawDate(string nowaData)
{
    data = nowaData;
}

void OperacjaFinansowa::ustawDateLiczbowo(int nowaDataLiczbowo)
{
    dataLiczbowo = nowaDataLiczbowo;
}

void OperacjaFinansowa::ustawOpis(string nowyOpis)
{
    opis = nowyOpis;
}

void OperacjaFinansowa::ustawKwote(string nowaKwota)
{
    kwota = nowaKwota;
}

void OperacjaFinansowa::ustawKwoteLiczbowo(double nowaKwotaLiczbowo)
{
    kwotaLiczbowo = nowaKwotaLiczbowo;
}

int OperacjaFinansowa::pobierzIdUzytkownika()
{
    return idUzytkownika;
}
string OperacjaFinansowa::pobierzDate()
{
    return data;
}

int OperacjaFinansowa::pobierzDateLiczbowo()
{
    return dataLiczbowo;
}

string OperacjaFinansowa::pobierzOpis()
{
    return opis;
}

string OperacjaFinansowa::pobierzKwote()
{
    return kwota;
}

double OperacjaFinansowa::pobierzKwoteLiczbowo()
{
    return kwotaLiczbowo;
}
