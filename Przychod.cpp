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

void Przychod::ustawKwote(float nowaKwota)
{
    kwota = nowaKwota;
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

float Przychod::pobierzKwote()
{
    return kwota;
}
