#ifndef OBSLUGAPLIKOWXML_H
#define OBSLUGAPLIKOWXML_H
#include "UzytkownikManager.h"
#include "ManagerFinansow.h"
#include <iostream>
#include <vector>

#include "Markup.h"

using namespace std;

class ObslugaPlikowXML
{

CMarkup xml;

public:

void dodajUzytkownikaDoPliku(Uzytkownik uzytkownik);
void dodajPrzychodDoPliku(Przychod przychod);
void wczytajDaneUzytkownikaZPliku();
vector<Uzytkownik> wczytajUzytkownikowZPliku();
void zapiszNoweHasloDoPliku(int idZalogowanegoUzytkownika, string noweHaslo);
};

#endif
