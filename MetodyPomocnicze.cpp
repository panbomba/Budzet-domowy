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

string MetodyPomocnicze::pobierzDateZSystemu()
{
    string rokString ="", miesiacString ="", dzienString ="", dzisiejszaData ="";
    int rok = 0, miesiac = 0, dzien = 0, dzienRoku = 0;
    time_t teraz = time(0);
    tm *ltm = localtime(&teraz);

    rok = (1900 + ltm->tm_year);
    rokString = konwerjsaIntNaString(rok);
    miesiac = (1 + ltm->tm_mon);
    miesiacString = konwerjsaIntNaString(miesiac);
    dzien = (ltm->tm_mday);
    dzienString = konwerjsaIntNaString(dzien);

    dzisiejszaData = (rokString + "-" + miesiacString + "-" + dzienString);

    return dzisiejszaData;
}

bool MetodyPomocnicze::sprawdzaniePoprawnegoFormatuDaty(string wpisanaData)
{
    int dlugosc = 0;
    dlugosc = wpisanaData.length();

    if ((dlugosc == 10)&&(wpisanaData[4] == '-') && (wpisanaData[7] == '-')
            && ((wpisanaData[0] >= 48) &&(wpisanaData[0] <=57))
            && ((wpisanaData[1] >= 48) &&(wpisanaData[1] <=57))
            && ((wpisanaData[2] >= 48) &&(wpisanaData[2] <=57))
            && ((wpisanaData[3] >= 48) &&(wpisanaData[3] <=57))
            && ((wpisanaData[5] >= 48) &&(wpisanaData[5] <=57))
            && ((wpisanaData[6] >= 48) &&(wpisanaData[6] <=57))
            && ((wpisanaData[8] >= 48) &&(wpisanaData[8] <=57))
            && ((wpisanaData[9] >= 48) &&(wpisanaData[9] <=57)))
        return true;

    else
        return false;


}

int MetodyPomocnicze::sprawdzMaksymalnaLiczbeDniDlaMiesiaca(int rokWpisanejDatyLiczba, int miesiacWpisanejDatyLiczba)
{
    int ileDniMaDanyMiesiac = 0;
    switch(miesiacWpisanejDatyLiczba)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        ileDniMaDanyMiesiac = 31;
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        ileDniMaDanyMiesiac = 30;
        break;
    case 2:
        if (((rokWpisanejDatyLiczba%4 == 0) && (rokWpisanejDatyLiczba%100 != 0)) || (rokWpisanejDatyLiczba%400 == 0))
        {
            ileDniMaDanyMiesiac = 29;
            break;
        }

        else
            ileDniMaDanyMiesiac = 28;
        break;

    }
    return ileDniMaDanyMiesiac;
}

bool MetodyPomocnicze:: sprawdzaniePoprawnychWartosciWpisanejDaty(string wpisanaData)
{
    time_t teraz = time(0);
    tm *ltm = localtime(&teraz);

    string rokWpisanejDaty = "", miesiacWpisanejDaty = "", dzienWpisanejDaty = "";
    int rokWpisanejDatyLiczba = 0, miesiacWpisanejDatyLiczba = 0, dzienWpisanejDatyLiczba = 0;
    int dzisiajRok = 0, dzisiajMiesiac = 0, dzisiajDzien = 0;
    int maksymalnaLiczbaDniDlaDanegoMiesiaca = 0;
    int maksymalnaLiczbaDniWObecnymMiesiacu = 0;

    rokWpisanejDaty = wpisanaData.substr(0,4);
    miesiacWpisanejDaty = wpisanaData.substr(5,2);
    dzienWpisanejDaty = wpisanaData.substr(8,2);

    // DATA PODANA PRZEZ UZYTKOWNIKA INT
    rokWpisanejDatyLiczba = atoi(rokWpisanejDaty.c_str());
    miesiacWpisanejDatyLiczba = atoi(miesiacWpisanejDaty.c_str());
    dzienWpisanejDatyLiczba = atoi(dzienWpisanejDaty.c_str());

    // DATA Z SYSTEMU INT
    dzisiajRok = (1900 + ltm->tm_year);
    dzisiajMiesiac = (1 + ltm->tm_mon);
    dzisiajDzien = (ltm->tm_mday);

    maksymalnaLiczbaDniDlaDanegoMiesiaca = sprawdzMaksymalnaLiczbeDniDlaMiesiaca(rokWpisanejDatyLiczba, miesiacWpisanejDatyLiczba);
    maksymalnaLiczbaDniWObecnymMiesiacu = sprawdzMaksymalnaLiczbeDniDlaMiesiaca(dzisiajRok, dzisiajMiesiac);

    if ((rokWpisanejDatyLiczba >= 2000) && (rokWpisanejDatyLiczba <= dzisiajRok)
            && (miesiacWpisanejDatyLiczba >= 1) && (miesiacWpisanejDatyLiczba <= 12)
            && (dzienWpisanejDatyLiczba >= 1) && (dzienWpisanejDatyLiczba <= maksymalnaLiczbaDniDlaDanegoMiesiaca)
            && (rokWpisanejDatyLiczba <= dzisiajRok) && (miesiacWpisanejDatyLiczba <= dzisiajMiesiac) && (dzienWpisanejDatyLiczba <= maksymalnaLiczbaDniWObecnymMiesiacu))
        return true;
    else
        return false;
}

string MetodyPomocnicze::zamianaDatyNaSameCyfry(string wpisanaData)
{
    string sformatowanaData = "";
    string tylkoRok = "";
    string tylkoMiesiac = "";
    string tylkoDzien = "";

    tylkoRok = wpisanaData.substr(0,4);
    tylkoMiesiac = wpisanaData.substr(5,2);
    tylkoDzien = wpisanaData.substr(8,2);
    sformatowanaData = tylkoRok + tylkoMiesiac + tylkoDzien;
    return sformatowanaData;
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



