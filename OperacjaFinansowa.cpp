#include "OperacjaFinansowa.h"

//void Przychod::ustawIdPrzychodu(int noweIdPrzychodu)
//{
//    if (noweIdPrzychodu >= 0)
//        idPrzychodu = noweIdPrzychodu;
//}

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

//int Przychod::pobierzIdPrzychodu()
//{
//    return idPrzychodu;
//}

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
