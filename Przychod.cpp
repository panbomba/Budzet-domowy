#include "Przychod.h"

void Przychod::ustawIdPrzychodu(int noweIdPrzychodu)
{
    if (noweIdPrzychodu >= 0)
        idPrzychodu = noweIdPrzychodu;
}

void Przychod::ustawIdUzytkownika(int idZalogowanegoUzytkownika)
{
    idUzytkownika = idZalogowanegoUzytkownika;
}
void Przychod::ustawDate(string nowaData)
{
    data = nowaData;
}

void Przychod::ustawOpis(string nowyOpis)
{
    opis = nowyOpis;
}

void Przychod::ustawKwote(string nowaKwota)
{
    kwota = nowaKwota;
}

void Przychod::ustawKwoteLiczbowo(double nowaKwotaLiczbowo)
{
    kwotaLiczbowo = nowaKwotaLiczbowo;
}

int Przychod::pobierzIdPrzychodu()
{
    return idPrzychodu;
}
int Przychod::pobierzIdUzytkownika()
{
    return idUzytkownika;
}
string Przychod::pobierzDate()
{
    return data;
}

string Przychod::pobierzOpis()
{
    return opis;
}

string Przychod::pobierzKwote()
{
    return kwota;
}

double Przychod::pobierzKwoteLiczbowo()
{
    return kwotaLiczbowo;
}
