#ifndef PLIKZUZYTKOWNIKAMI_H
#define PLIKZUZYTKOWNIKAMI_H

#include <iostream>
#include <vector>
#include <cstdlib>

#include "Uzytkownik.h"
#include "MetodyPomocnicze.h"
#include "PlikXML.h"

using namespace std;

class PlikZUzytkownikami :public PlikXML
{

public:
    PlikZUzytkownikami(string nazwaPliku) : PlikXML(nazwaPliku) {};

    void dodajUzytkownikaDoPliku(Uzytkownik uzytkownik);
    vector<Uzytkownik> wczytajUzytkownikowZPliku();
    void zapiszNoweHasloDoPliku(int idZalogowanegoUzytkownika, string noweHaslo);
};

#endif
