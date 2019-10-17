#ifndef UZYTKOWNIK_H
#define UZYTKOWNIK_H

#include <iostream>

using namespace std;

class Uzytkownik
{
    int idUzytkownika;
    string login;
    string haslo;
    string imie;
    string nazwisko;

public:
    void ustawIdUzytkownika(int noweIdUzytkownika);
    void ustawLogin(string nowyLogin);
    void ustawHaslo(string noweHaslo);
    void ustawImie(string noweImie);
    void ustawNazwisko(string noweNazwisko);

    int pobierzIdUzytkownika();
    string pobierzLogin();
    string pobierzHaslo();
    string pobierzImie();
    string pobierzNazwisko();
};

#endif
