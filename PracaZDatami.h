#ifndef PRACAZDATAMI_H
#define PRACAZDATAMI_H

#include <iostream>
#include <sstream>
#include "MetodyPomocnicze.h"

using namespace std;

class PracaZDatami
{
public:

    string pobierzDateZSystemu();
    int sprawdzMaksymalnaLiczbeDniDlaMiesiaca(int rokWpisanejDatyLiczba, int miesiacWpisanejDatyLiczba);
    bool sprawdzaniePoprawnegoFormatuDaty(string wpisanaData);
    bool sprawdzaniePoprawnychWartosciWpisanejDaty(string wpisanaData);
    string zamianaDatyNaSameCyfry(string wpisanaData);
};

#endif
