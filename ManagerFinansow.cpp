#include "ManagerFinansow.h"
#include "MetodyPomocnicze.h"

void ManagerFinansow::dodajPrzychod()
{
    system("cls");
    cout << " >>> DODAWANIE NOWEGO PRZYCHODU <<<" << endl << endl;
    Przychod przychod;
    ObslugaPlikowXML obslugaPlikowXML;
    przychod = podajDanePrzychodu();

    przychody.push_back(przychod);

    obslugaPlikowXML.dodajPrzychodDoPliku(przychod);

    cout << endl << "TRANSAKCJA DODANA" << endl << endl;
    system("pause");
}

void ManagerFinansow::dodajWydatek()
{
    system("cls");
    cout << " >>> DODAWANIE NOWEGO WYDATKU <<<" << endl << endl;
    Wydatek wydatek;
    ObslugaPlikowXML obslugaPlikowXML;
    wydatek = podajDaneWydatku();

    wydatki.push_back(wydatek);

    obslugaPlikowXML.dodajWydatekDoPliku(wydatek);

    cout << endl << "TRANSAKCJA DODANA" << endl << endl;
    system("pause");
}

Przychod ManagerFinansow::podajDanePrzychodu() //JAK ZROBIC ZEBY ALBO BYL PRZYCHOD ALBO WYDATEK?
{
    MetodyPomocnicze metodyPomocnicze;
    Przychod przychod;
    string data, opis;
    float kwota;

    przychod.ustawIdPrzychodu(plikZPrzychodami.pobierzIdOstatniegoPrzychodu()+1);
    przychod.ustawIdUzytkownika(ID_ZALOGOWANEGO_UZYTKOWNIKA);

    cin.clear();
    cin.sync();
    cout << "Podaj date transakcji w formacie RRRR-MM-DD: ";
    data = metodyPomocnicze.wczytajLinie();
    //TUTAJ CHECK CZY POPRAWNY FORMAT ORAZ ZAPYTANIE CZY DZISIAJ CZY INNA DATA
    cin.clear();
    cin.sync();
    cout << "Dadaj opis: ";
    opis = metodyPomocnicze.wczytajLinie();
    cin.clear();
    cin.sync();
    cout << "Podaj kwote transakcji: ";
    cin >> kwota;
    //TUTAJ CHECK CZY PRZECINEK

    przychod.ustawDate(data);
    przychod.ustawOpis(opis);
    przychod.ustawKwote(kwota);


    return przychod;
}

Wydatek ManagerFinansow::podajDaneWydatku() //JAK ZROBIC ZEBY ALBO BYL PRZYCHOD ALBO WYDATEK?
{
    MetodyPomocnicze metodyPomocnicze;
    Wydatek wydatek;
    string data, opis;
    float kwota;

    wydatek.ustawIdWydatku(plikZWydatkami.pobierzIdOstatniegoWydatku()+1); //TO DOPISAC
    wydatek.ustawIdUzytkownika(ID_ZALOGOWANEGO_UZYTKOWNIKA);

    cin.clear();
    cin.sync();
    cout << "Podaj date transakcji w formacie RRRR-MM-DD: ";
    data = metodyPomocnicze.wczytajLinie();
    //TUTAJ CHECK CZY POPRAWNY FORMAT ORAZ ZAPYTANIE CZY DZISIAJ CZY INNA DATA
    cin.clear();
    cin.sync();
    cout << "Dadaj opis: ";
    opis = metodyPomocnicze.wczytajLinie();
    cin.clear();
    cin.sync();
    cout << "Podaj kwote transakcji: ";
    cin >> kwota;
    //TUTAJ CHECK CZY PRZECINEK

    wydatek.ustawDate(data);
    wydatek.ustawOpis(opis);
    wydatek.ustawKwote(kwota);

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
            cout << przychody[i].pobierzKwote() << endl;
            cout << endl;
    }
}

void ManagerFinansow::wypiszWydatkiZalogowanegoUzytkownika() //UZYWAM TYLKO DO TESTO
{
        for (int i=0; i<przychody.size(); i++)
    {
            cout << wydatki[i].pobierzIdWydatku() << endl;
            cout << wydatki[i].pobierzIdUzytkownika() << endl;
            cout << wydatki[i].pobierzDate() << endl;
            cout << wydatki[i].pobierzOpis() << endl;
            cout << wydatki[i].pobierzKwote() << endl;
            cout << endl;
    }
}



