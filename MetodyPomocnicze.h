#ifndef METODYPOMOCNICZE_H
#define METODYPOMOCNICZE_H

#include <iostream>
#include <sstream>
using namespace std;

class MetodyPomocnicze
{
public:
    static string konwerjsaIntNaString(int liczba); //OK
    string wczytajLinie(); //OK
    string zamienPierwszaLitereNaDuzaAPozostaleNaMale(string tekst); //MOZE SIE PRZYDAC
    string pobierzLiczbe(string tekst, int pozycjaZnaku); //MOZE SIE PRZYDAC
    int konwersjaStringNaInt(string liczba); //OK
    int pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami); //NARAZIE ZOSTAWIE - MOZE SIE POZNIEJ PRZYDAC
    int pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami); //NARAZIE ZOSTAWIE
    char wczytajZnak(); //OK
    int wczytajLiczbeCalkowita();
    int podajIdWybranegoAdresata(); //ZAMIENIC NA PODAJ ID PRZYCHODU/WYDATKU (TRANSAKCJI)
    char wybierzOpcjeZMenuEdycja();

    // DODAC
    //sprawdzPoprawnoscFormatuDaty
    //zamienPrzecinekNaKropke
    //UstalIleDniJestWSprawdzanymOkresie ??
    //PosortujWynikiWedlugDaty
    //KonwertujDaneNaFormatLiczbowy
};

#endif
