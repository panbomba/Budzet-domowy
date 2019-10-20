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

void dodajPrzychodDoPliku(Przychod przychod);
void dodajWydatekDoPliku(Wydatek wydatek);
void wczytajDaneUzytkownikaZPliku();

};

#endif
