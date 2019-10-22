#include "Uzytkownik.h"

void Uzytkownik::ustawIdUzytkownika(int noweIdUzytkownika)
{
    if (noweIdUzytkownika >= 0)
        idUzytkownika = noweIdUzytkownika;
}
void Uzytkownik::ustawLogin(string nowyLogin)
{
    login = nowyLogin;
}
void Uzytkownik::ustawHaslo(string noweHaslo)
{
    haslo = noweHaslo;
}
void Uzytkownik::ustawImie(string noweImie)
{
    imie = noweImie;
}
void Uzytkownik::ustawNazwisko(string noweNazwisko)
{
    nazwisko = noweNazwisko;
}

int Uzytkownik::pobierzIdUzytkownika()
{
    return idUzytkownika;
}
string Uzytkownik::pobierzLogin()
{
    return login;
}
string Uzytkownik::pobierzHaslo()
{
    return haslo;
}
string Uzytkownik::pobierzImie()
{
    return imie;
}
string Uzytkownik::pobierzNazwisko()
{
    return nazwisko;
}
