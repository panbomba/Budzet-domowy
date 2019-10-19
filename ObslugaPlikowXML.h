#ifndef OBSLUGAPLIKOWXML_H
#define OBSLUGAPLIKOWXML_H
#include "UzytkownikManager.h"
#include <iostream>
#include <vector>

#include "Markup.h"

using namespace std;

class ObslugaPlikowXML
{

CMarkup xml;

public:

void dodajUzytkownikaDoPliku(Uzytkownik uzytkownik);
void wczytajDaneUzytkownikaZPliku();
int wczytajIdOstatniegoUzytkownikaZPliku();
vector<Uzytkownik> wczytajUzytkownikowZPliku();

};

#endif
