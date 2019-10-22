#include <sstream>
#include <algorithm>
#include "MetodyPomocnicze.h"
#include <ctime>

string MetodyPomocnicze::wczytajLinie()
{
    string wejscie = "";
    getline(cin, wejscie);
    return wejscie;
}

char MetodyPomocnicze::wczytajZnak()
{
    cin.clear();
    cin.sync();
    string wejscie = "";
    char znak  = {0};

    while (true)
    {
        getline(cin, wejscie);

        if (wejscie.length() == 1)
        {
            znak = wejscie[0];
            break;
        }
        cout << "To nie jest pojedynczy znak. Wpisz ponownie." << endl;
    }
    return znak;
}

string MetodyPomocnicze::konwerjsaIntNaString(int liczba)
{
    ostringstream ss;
    ss << liczba;
    string str = ss.str();
    return str;
}

string MetodyPomocnicze::zamienPrzecinekNaKropke(string wpisanaKwota)
{
    for (int i=0; i<wpisanaKwota.length(); i++)
    {
        if (wpisanaKwota[i] == ',')
        {
            wpisanaKwota[i] = '.';
        }
    }
    return wpisanaKwota;
}



