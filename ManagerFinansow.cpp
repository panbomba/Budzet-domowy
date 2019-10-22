#include "ManagerFinansow.h"
#include "MetodyPomocnicze.h"

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
            data = metodyPomocnicze.pobierzDateZSystemu();
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

                if (metodyPomocnicze.sprawdzaniePoprawnegoFormatuDaty(data) && metodyPomocnicze.sprawdzaniePoprawnychWartosciWpisanejDaty(data))
                    break;
            }
            while ((metodyPomocnicze.sprawdzaniePoprawnegoFormatuDaty(data)!=true) || (metodyPomocnicze.sprawdzaniePoprawnychWartosciWpisanejDaty(data)!=true));
            break;
        }
        else
        {
            cout << "WYBIERZ 't' LUB 'n':" << endl;;
        }
    }
    while (wybor != 't' || wybor != 'n');

    metodyPomocnicze.zamianaDatyNaSameCyfry(data); //TRZEBA DODAC TO DO VECTORA
    dataLiczbowo = atoi(metodyPomocnicze.zamianaDatyNaSameCyfry(data).c_str());

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
            data = metodyPomocnicze.pobierzDateZSystemu();
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

                if (metodyPomocnicze.sprawdzaniePoprawnegoFormatuDaty(data) && metodyPomocnicze.sprawdzaniePoprawnychWartosciWpisanejDaty(data))
                    break;
            }
            while ((metodyPomocnicze.sprawdzaniePoprawnegoFormatuDaty(data)!=true) || (metodyPomocnicze.sprawdzaniePoprawnychWartosciWpisanejDaty(data)!=true));
            break;
        }
        else
        {
            cout << "WYBIERZ 't' LUB 'n':" << endl;;
        }
    }
    while (wybor != 't' || wybor != 'n');

    metodyPomocnicze.zamianaDatyNaSameCyfry(data);
    dataLiczbowo = atoi(metodyPomocnicze.zamianaDatyNaSameCyfry(data).c_str());

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

void ManagerFinansow::wypiszPrzychodyZalogowanegoUzytkownika()
{
    for (int i=0; i<przychody.size(); i++)
    {
        cout << przychody[i].pobierzIdPrzychodu() << endl;
        cout << przychody[i].pobierzIdUzytkownika() << endl;
        cout << przychody[i].pobierzDate() << endl;
        cout << przychody[i].pobierzDateLiczbowo() << endl;
        cout << przychody[i].pobierzOpis() << endl;
        cout << przychody[i].pobierzKwoteLiczbowo() << endl;
        cout << endl;
    }
}

void ManagerFinansow::wypiszWydatkiZalogowanegoUzytkownika() //UZYWAM TYLKO DO TESTO
{
    for (int i=0; i<wydatki.size(); i++)
    {
        cout << wydatki[i].pobierzIdWydatku() << endl;
        cout << wydatki[i].pobierzIdUzytkownika() << endl;
        cout << wydatki[i].pobierzDate() << endl;
        cout << wydatki[i].pobierzDateLiczbowo() << endl;
        cout << wydatki[i].pobierzOpis() << endl;
        cout << wydatki[i].pobierzKwoteLiczbowo() << endl;
        cout << endl;
    }
}

void ManagerFinansow::sumaPrzychodowUzytkownika() //NARAZIE DO TESTOW
{
    double suma=0;
    for(int i=0; i<przychody.size(); i++)
    {
        suma += przychody[i].pobierzKwoteLiczbowo();
    }
    cout << suma;
    system ("pause");
}

void ManagerFinansow::sumaWydatkowUzytkownika() //NARAZIE DO TESTOW
{
    double suma=0;
    for(int i=0; i<wydatki.size(); i++)
    {
        suma += wydatki[i].pobierzKwoteLiczbowo();
    }
    cout << suma;
    system ("pause");
}

void ManagerFinansow::wyswietlBilansZaObecnyMiesiac()
{
    system("cls");
    cout << " >>> BILANS ZA OBECNY MIESIAC <<<" << endl << endl;

    MetodyPomocnicze metodyPomocnicze;
    int dataPoczatkowaLiczbowo = 0, dataKoncowaLiczbowo = 0, iloscDniWObecnymMiesiacu = 0;
    int rok = 0, miesiac = 0, dzien = 0;
    time_t teraz = time(0);
    tm *ltm = localtime(&teraz);

    rok = (1900 + ltm->tm_year);
    miesiac = (1 + ltm->tm_mon);

    iloscDniWObecnymMiesiacu = metodyPomocnicze.sprawdzMaksymalnaLiczbeDniDlaMiesiaca(rok, miesiac);

    dataPoczatkowaLiczbowo = (1 + 100*miesiac + 10000*rok);
    cout << dataPoczatkowaLiczbowo;
    system ("pause");
    dataKoncowaLiczbowo = (iloscDniWObecnymMiesiacu + 100*miesiac + 10000*rok);
    cout << dataKoncowaLiczbowo;
    system ("pause");
}

void ManagerFinansow::wyswietlBilansZaPoprzedniMiesiac()
{
    system("cls");
    cout << " >>> BILANS ZA POPRZEDNI MIESIAC <<<" << endl << endl;

    MetodyPomocnicze metodyPomocnicze;
    int dataPoczatkowaLiczbowo= 0, dataKoncowaLiczbowo = 0, iloscDniWPoprzednimMiesiacu = 0;
    int rok = 0, miesiac = 0, poprzedniMiesiac = 0, dzien = 0;
    time_t teraz = time(0);
    tm *ltm = localtime(&teraz);

    rok = (1900 + ltm->tm_year);
    //cout << rok; system("pause");
    miesiac = (1 + ltm->tm_mon);
    //cout << miesiac; system ("pause");
    poprzedniMiesiac = (miesiac - 1);

    if (poprzedniMiesiac == 0)
    {
        poprzedniMiesiac = 12;
        rok = rok-1;
    }
    //cout << poprzedniMiesiac; system("pause");

    iloscDniWPoprzednimMiesiacu = metodyPomocnicze.sprawdzMaksymalnaLiczbeDniDlaMiesiaca(rok, poprzedniMiesiac);

    dataPoczatkowaLiczbowo = (1 + poprzedniMiesiac*100 + rok*10000);
    dataKoncowaLiczbowo = (iloscDniWPoprzednimMiesiacu + poprzedniMiesiac*100 + rok*10000);
    cout << dataPoczatkowaLiczbowo;
    system("pause");
    cout << dataKoncowaLiczbowo;
    system("pause");

}

void ManagerFinansow::wyswietlBilansZaPodanyOkres()
{
    system("cls");
    cout << " >>> BILANS ZA WYBRANY OKRES <<<" << endl << endl;

    MetodyPomocnicze metodyPomocnicze;
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

        if (metodyPomocnicze.sprawdzaniePoprawnegoFormatuDaty(dataPoczatkowa) && metodyPomocnicze.sprawdzaniePoprawnychWartosciWpisanejDaty(dataPoczatkowa))
            break;
    }
    while ((metodyPomocnicze.sprawdzaniePoprawnegoFormatuDaty(dataPoczatkowa)!=true) || (metodyPomocnicze.sprawdzaniePoprawnychWartosciWpisanejDaty(dataPoczatkowa)!=true));

    metodyPomocnicze.zamianaDatyNaSameCyfry(dataPoczatkowa);
    dataPoczatkowaLiczbowo = atoi(metodyPomocnicze.zamianaDatyNaSameCyfry(dataPoczatkowa).c_str());

    cout << endl;

    do
    {
        cin.clear();
        cin.sync();
        cout << "Podaj date KONCOWA z okresu od 2000-01-01 do konca obecnego miesiaca w formacie RRRR-MM-DD: ";
        dataKoncowa = metodyPomocnicze.wczytajLinie();

        if (metodyPomocnicze.sprawdzaniePoprawnegoFormatuDaty(dataKoncowa) && metodyPomocnicze.sprawdzaniePoprawnychWartosciWpisanejDaty(dataKoncowa))
            break;
    }
    while ((metodyPomocnicze.sprawdzaniePoprawnegoFormatuDaty(dataKoncowa)!=true) || (metodyPomocnicze.sprawdzaniePoprawnychWartosciWpisanejDaty(dataKoncowa)!=true));

    metodyPomocnicze.zamianaDatyNaSameCyfry(dataKoncowa);
    dataKoncowaLiczbowo = atoi(metodyPomocnicze.zamianaDatyNaSameCyfry(dataKoncowa).c_str());

    cout << dataPoczatkowaLiczbowo;
    system("pause");
    cout << dataKoncowaLiczbowo;
    system("pause");

}



