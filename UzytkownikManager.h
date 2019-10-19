#ifndef UZYTKOWNIKMENEDZER_H
#define UZYTKOWNIKMENEDZER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>

#include "Uzytkownik.h"
#include "ObslugaPlikowXML.h"
//#include "UzytkownikManager.h"
//#include "PlikZUzytkownikami.h"

using namespace std;

class UzytkownikManager
{
    //ObslugaPlikowXML obslugaPlikowXML;
    int idZalogowanegoUzytkownika;
    vector <Uzytkownik> uzytkownicy;


    Uzytkownik podajDaneNowegoUzytkownika();

    int pobierzIdNowegoUzytkownika();
    bool czyIstniejeLogin(string login); //OK
//        PlikZUzytkownikami plikZUzytkownikami;

    public:
   // UzytkownikManager//(string nazwaPlikuZUzytkownikami) : plikZUzytkownikami(nazwaPlikuZUzytkownikami) {
Uzytkownik wczytajDaneUzytkownikowZPliku();
    //uzytkownicy = wczytajUzytkownikowZPliku();
    //};
    void rejestracjaUzytkownika(); //OK
    void wypiszWszystkichUzytkownikow(); //OK
    int logowanieUzytkownika(); // OK
    void zmianaHaslaZalogowanegoUzytkownika(); //OK
    bool czyUzytkownikJestZalogowany(); //OK
    int pobierzIdZalogowanegoUzytkownika(); //OK
    void wylogowanieUzytkownika(); //OK

};

#endif
