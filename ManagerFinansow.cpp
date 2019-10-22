#include "ManagerFinansow.h"
#include "MetodyPomocnicze.h"
#include "PracaZDatami.h"

void ManagerFinansow::dodajPrzychod()
{
    system("cls");
    cout << " >>> DODAWANIE NOWEGO PRZYCHODU <<<" << endl << endl;
    Przychod przychod;
    przychod = podajDanePrzychodu();

    przychody.push_back(przychod);

    plikZPrzychodami.dodajPrzychodDoPliku(przychod);

    cout << endl << "TRANSAKCJA DODANA" << endl << endl;
    system("pause");
}

void ManagerFinansow::dodajWydatek()
{
    system("cls");
    cout << " >>> DODAWANIE NOWEGO WYDATKU <<<" << endl << endl;
    Wydatek wydatek;
    wydatek = podajDaneWydatku();

    wydatki.push_back(wydatek);

    plikZWydatkami.dodajWydatekDoPliku(wydatek);

    cout << endl << "TRANSAKCJA DODANA" << endl << endl;
    system("pause");
}

Przychod ManagerFinansow::podajDanePrzychodu()
{
    MetodyPomocnicze metodyPomocnicze;
    PracaZDatami pracaZDatami;
    Przychod przychod;
    char wybor;
    string data, opis, kwotaPrzedUsunieciemPrzecinka, kwota;
    int dataLiczbowo;
    double kwotaLiczbowo;

    przychod.ustawIdPrzychodu(plikZPrzychodami.pobierzIdOstatniegoPrzychodu()+1);
    przychod.ustawIdUzytkownika(ID_ZALOGOWANEGO_UZYTKOWNIKA);

    do
    {
        cin.clear();
        cin.sync();
        cout << "Czy chcesz uzyc dzisiejszej daty? (t/n): ";
        cin >> wybor;
        if (wybor == 't')
        {
            data = pracaZDatami.pobierzDateZSystemu();
            break;
        }
        else if (wybor == 'n')
        {
            do
            {
                cin.clear();
                cin.sync();
                cout << "Podaj date transakcji z okresu od 2000-01-01 do konca obecnego miesiaca w formacie RRRR-MM-DD: ";
                data = metodyPomocnicze.wczytajLinie();

                if (pracaZDatami.sprawdzaniePoprawnegoFormatuDaty(data) && pracaZDatami.sprawdzaniePoprawnychWartosciWpisanejDaty(data))
                    break;
            }
            while ((pracaZDatami.sprawdzaniePoprawnegoFormatuDaty(data)!=true) || (pracaZDatami.sprawdzaniePoprawnychWartosciWpisanejDaty(data)!=true));
            break;
        }
        else
        {
            cout << "WYBIERZ 't' LUB 'n':" << endl;;
        }
    }
    while (wybor != 't' || wybor != 'n');

    pracaZDatami.zamianaDatyNaSameCyfry(data);
    dataLiczbowo = atoi(pracaZDatami.zamianaDatyNaSameCyfry(data).c_str());

    cin.clear();
    cin.sync();
    cout << "Dodaj opis: ";
    opis = metodyPomocnicze.wczytajLinie();
    cin.clear();
    cin.sync();
    cout << "Podaj kwote transakcji: ";
    cin >> kwotaPrzedUsunieciemPrzecinka;
    kwota = metodyPomocnicze.zamienPrzecinekNaKropke(kwotaPrzedUsunieciemPrzecinka);
    kwotaLiczbowo = atof(kwota.c_str());

    przychod.ustawDate(data);
    przychod.ustawDateLiczbowo(dataLiczbowo);
    przychod.ustawOpis(opis);
    przychod.ustawKwote(kwota);
    przychod.ustawKwoteLiczbowo(kwotaLiczbowo);

    return przychod;
}

Wydatek ManagerFinansow::podajDaneWydatku()
{
    MetodyPomocnicze metodyPomocnicze;
    PracaZDatami pracaZDatami;
    Wydatek wydatek;
    char wybor;
    string data, opis, kwotaPrzedUsunieciemPrzecinka, kwota;
    string test;
    int dataLiczbowo;
    double kwotaLiczbowo;

    wydatek.ustawIdWydatku(plikZWydatkami.pobierzIdOstatniegoWydatku()+1);
    wydatek.ustawIdUzytkownika(ID_ZALOGOWANEGO_UZYTKOWNIKA);

    do
    {
        cin.clear();
        cin.sync();
        cout << "Czy chcesz uzyc dzisiejszej daty? (t/n): ";
        cin >> wybor;
        if (wybor == 't')
        {
            data = pracaZDatami.pobierzDateZSystemu();
            break;
        }
        else if (wybor == 'n')
        {
            do
            {
                cin.clear();
                cin.sync();
                cout << "Podaj date transakcji z okresu od 2000-01-01 do konca obecnego miesiaca w formacie RRRR-MM-DD: ";
                data = metodyPomocnicze.wczytajLinie();

                if (pracaZDatami.sprawdzaniePoprawnegoFormatuDaty(data) && pracaZDatami.sprawdzaniePoprawnychWartosciWpisanejDaty(data))
                    break;
            }
            while ((pracaZDatami.sprawdzaniePoprawnegoFormatuDaty(data)!=true) || (pracaZDatami.sprawdzaniePoprawnychWartosciWpisanejDaty(data)!=true));
            break;
        }
        else
        {
            cout << "WYBIERZ 't' LUB 'n':" << endl;;
        }
    }
    while (wybor != 't' || wybor != 'n');

    pracaZDatami.zamianaDatyNaSameCyfry(data);
    dataLiczbowo = atoi(pracaZDatami.zamianaDatyNaSameCyfry(data).c_str());

    cin.clear();
    cin.sync();
    cout << "Dadaj opis: ";
    opis = metodyPomocnicze.wczytajLinie();
    cin.clear();
    cin.sync();
    cout << "Podaj kwote transakcji: ";
    cin >> kwotaPrzedUsunieciemPrzecinka;
    kwota = metodyPomocnicze.zamienPrzecinekNaKropke(kwotaPrzedUsunieciemPrzecinka);
    kwotaLiczbowo = atof(kwota.c_str());

    wydatek.ustawDate(data);
    wydatek.ustawDateLiczbowo(dataLiczbowo);
    wydatek.ustawOpis(opis);
    wydatek.ustawKwote(kwota);
    wydatek.ustawKwoteLiczbowo(kwotaLiczbowo);

    return wydatek;
}

void ManagerFinansow::wyswietlBilans(int dataPoczatkowa, int dataKoncowa)
{

    int sumaPrzychodow = 0;
    int sumaWydatkow = 0;
    sort(przychody.begin(), przychody.end(), Przychod());
    sort(wydatki.begin(), wydatki.end(), Wydatek());

    for (vector<Przychod>::iterator itr = przychody.begin(); itr != przychody.end(); ++itr)
    {
        if ((itr->pobierzDateLiczbowo() >= dataPoczatkowa) && (itr->pobierzDateLiczbowo() <= dataKoncowa))
        {
            cout << "DATA TRANSAKCJI: " << itr->pobierzDate() << endl;
            cout << "OPIS: " << itr->pobierzOpis() << endl;
            cout << "KWOTA: " << itr->pobierzKwoteLiczbowo() << endl << endl;
            sumaPrzychodow += itr->pobierzKwoteLiczbowo();
        }
    }

    for (vector<Wydatek>::iterator itr = wydatki.begin(); itr != wydatki.end(); ++itr)
    {
        if ((itr->pobierzDateLiczbowo() >= dataPoczatkowa) && (itr->pobierzDateLiczbowo() <= dataKoncowa))
        {
            cout << "DATA TRANSAKCJI: " << itr->pobierzDate() << endl;
            cout << "OPIS: " << itr->pobierzOpis() << endl;
            cout << "KWOTA: " << itr->pobierzKwoteLiczbowo() << endl << endl;
            sumaWydatkow += itr->pobierzKwoteLiczbowo();
        }
    }
    cout << "SUMA PRZYCHODOW W TYM OKRESIE: " << sumaPrzychodow << endl << endl;
    cout << "SUMA WYDATKOW W TYM OKRESIE: " << sumaWydatkow << endl << endl;
    cout << "BILANS ZA TEN OKRES WYNOSI: " << sumaPrzychodow-sumaWydatkow << endl << endl;
    system("pause");
}

void ManagerFinansow::wyswietlBilansZaObecnyMiesiac()
{
    system("cls");
    cout << " >>> BILANS ZA OBECNY MIESIAC <<<" << endl << endl;

    MetodyPomocnicze metodyPomocnicze;
    PracaZDatami pracaZDatami;
    int dataPoczatkowaLiczbowo = 0, dataKoncowaLiczbowo = 0, iloscDniWObecnymMiesiacu = 0;
    int rok = 0, miesiac = 0, dzien = 0;
    time_t teraz = time(0);
    tm *ltm = localtime(&teraz);

    rok = (1900 + ltm->tm_year);
    miesiac = (1 + ltm->tm_mon);

    iloscDniWObecnymMiesiacu = pracaZDatami.sprawdzMaksymalnaLiczbeDniDlaMiesiaca(rok, miesiac);

    dataPoczatkowaLiczbowo = (1 + 100*miesiac + 10000*rok);
    cout << "DATA POCZATKOWA: " <<dataPoczatkowaLiczbowo << endl;
    dataKoncowaLiczbowo = (iloscDniWObecnymMiesiacu + 100*miesiac + 10000*rok);
    cout << "DATA KONCOWA: " <<dataKoncowaLiczbowo << endl << endl;

    wyswietlBilans(dataPoczatkowaLiczbowo, dataKoncowaLiczbowo);
}

void ManagerFinansow::wyswietlBilansZaPoprzedniMiesiac()
{
    system("cls");
    cout << " >>> BILANS ZA POPRZEDNI MIESIAC <<<" << endl << endl;

    MetodyPomocnicze metodyPomocnicze;
    PracaZDatami pracaZDatami;
    int dataPoczatkowaLiczbowo= 0, dataKoncowaLiczbowo = 0, iloscDniWPoprzednimMiesiacu = 0;
    int rok = 0, miesiac = 0, poprzedniMiesiac = 0, dzien = 0;
    time_t teraz = time(0);
    tm *ltm = localtime(&teraz);

    rok = (1900 + ltm->tm_year);
    miesiac = (1 + ltm->tm_mon);
    poprzedniMiesiac = (miesiac - 1);

    if (poprzedniMiesiac == 0)
    {
        poprzedniMiesiac = 12;
        rok = rok-1;
    }

    iloscDniWPoprzednimMiesiacu = pracaZDatami.sprawdzMaksymalnaLiczbeDniDlaMiesiaca(rok, poprzedniMiesiac);

    dataPoczatkowaLiczbowo = (1 + poprzedniMiesiac*100 + rok*10000);
    cout << "DATA POCZATKOWA: " <<dataPoczatkowaLiczbowo << endl;
    dataKoncowaLiczbowo = (iloscDniWPoprzednimMiesiacu + poprzedniMiesiac*100 + rok*10000);
    cout << "DATA KONCOWA: " <<dataKoncowaLiczbowo << endl << endl;

    wyswietlBilans(dataPoczatkowaLiczbowo, dataKoncowaLiczbowo);
}

void ManagerFinansow::wyswietlBilansZaPodanyOkres()
{
    system("cls");
    cout << " >>> BILANS ZA WYBRANY OKRES <<<" << endl << endl;

    MetodyPomocnicze metodyPomocnicze;
    PracaZDatami pracaZDatami;
    string dataPoczatkowa = "";
    int dataPoczatkowaLiczbowo = 0;
    string dataKoncowa = "";
    int dataKoncowaLiczbowo = 0;

    do
    {
        cin.clear();
        cin.sync();
        cout << "Podaj date POCZATKOWA z okresu od 2000-01-01 do konca obecnego miesiaca w formacie RRRR-MM-DD: ";
        dataPoczatkowa = metodyPomocnicze.wczytajLinie();

        if (pracaZDatami.sprawdzaniePoprawnegoFormatuDaty(dataPoczatkowa) && pracaZDatami.sprawdzaniePoprawnychWartosciWpisanejDaty(dataPoczatkowa))
            break;
    }
    while ((pracaZDatami.sprawdzaniePoprawnegoFormatuDaty(dataPoczatkowa)!=true) || (pracaZDatami.sprawdzaniePoprawnychWartosciWpisanejDaty(dataPoczatkowa)!=true));

    pracaZDatami.zamianaDatyNaSameCyfry(dataPoczatkowa);
    dataPoczatkowaLiczbowo = atoi(pracaZDatami.zamianaDatyNaSameCyfry(dataPoczatkowa).c_str());

    cout << endl;

    do
    {
        cin.clear();
        cin.sync();
        cout << "Podaj date KONCOWA z okresu od 2000-01-01 do konca obecnego miesiaca w formacie RRRR-MM-DD: ";
        dataKoncowa = metodyPomocnicze.wczytajLinie();

        if (pracaZDatami.sprawdzaniePoprawnegoFormatuDaty(dataKoncowa) && pracaZDatami.sprawdzaniePoprawnychWartosciWpisanejDaty(dataKoncowa))
            break;
    }
    while ((pracaZDatami.sprawdzaniePoprawnegoFormatuDaty(dataKoncowa)!=true) || (pracaZDatami.sprawdzaniePoprawnychWartosciWpisanejDaty(dataKoncowa)!=true));

    pracaZDatami.zamianaDatyNaSameCyfry(dataKoncowa);
    cout << "DATA POCZATKOWA: " <<dataPoczatkowaLiczbowo << endl;
    dataKoncowaLiczbowo = atoi(pracaZDatami.zamianaDatyNaSameCyfry(dataKoncowa).c_str());
    cout << "DATA KONCOWA: " <<dataKoncowaLiczbowo << endl << endl;

    wyswietlBilans(dataPoczatkowaLiczbowo, dataKoncowaLiczbowo);
}



