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
    string data, opis, kwota;
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
            cin.clear();
            cin.sync();
            cout << "Podaj date transakcji w formacie RRRR-MM-DD: ";
            data = metodyPomocnicze.wczytajLinie();
            break;
        }
        else
        {
            cout << "WYBIERZ 't' LUB 'n':" << endl;;
        }
    }
    while (wybor != 't' || wybor != 'n');

    //TUTAJ CHECK CZY POPRAWNY FORMAT ORAZ ZAPYTANIE CZY DZISIAJ CZY INNA DATA
    cin.clear();
    cin.sync();
    cout << "Dodaj opis: ";
    opis = metodyPomocnicze.wczytajLinie();
    cin.clear();
    cin.sync();
    cout << "Podaj kwote transakcji: ";
    cin >> kwota;
    kwotaLiczbowo = atof(kwota.c_str());
    //TUTAJ CHECK CZY PRZECINEK

    przychod.ustawDate(data);
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
    string data, opis, kwota;
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
            cin.clear();
            cin.sync();
            cout << "Podaj date transakcji w formacie RRRR-MM-DD: ";
            data = metodyPomocnicze.wczytajLinie();
            break;
        }
        else
        {
            cout << "WYBIERZ 't' LUB 'n':" << endl;;
        }
    }
    while (wybor != 't' || wybor != 'n');

    //TUTAJ CHECK CZY POPRAWNY FORMAT ORAZ ZAPYTANIE CZY DZISIAJ CZY INNA DATA
    cin.clear();
    cin.sync();
    cout << "Dadaj opis: ";
    opis = metodyPomocnicze.wczytajLinie();
    cin.clear();
    cin.sync();
    cout << "Podaj kwote transakcji: ";
    cin >> kwota;
    kwotaLiczbowo = atof(kwota.c_str());
    //TUTAJ CHECK CZY PRZECINEK

    wydatek.ustawDate(data);
    wydatek.ustawOpis(opis);
    wydatek.ustawKwote(kwota);
    wydatek.ustawKwoteLiczbowo(kwotaLiczbowo);

    return wydatek;
}

void ManagerFinansow::wypiszPrzychodyZalogowanegoUzytkownika() //UZYWAM TYLKO DO TESTOW
{
    for (int i=0; i<przychody.size(); i++)
    {
        cout << przychody[i].pobierzIdPrzychodu() << endl;
        cout << przychody[i].pobierzIdUzytkownika() << endl;
        cout << przychody[i].pobierzDate() << endl;
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



