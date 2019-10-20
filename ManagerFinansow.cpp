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

    przychod.ustawIdPrzychodu(pobierzIdNowegoPrzychodu()); //TO DOPISAC
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

    wydatek.ustawIdWydatku(pobierzIdNowegoWydatku()); //TO DOPISAC
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

int ManagerFinansow::pobierzIdNowegoPrzychodu()
{
    if (przychody.empty() == true)
        return 1;
    else
        return przychody.back().pobierzIdPrzychodu() + 1;
}

int ManagerFinansow::pobierzIdNowegoWydatku()
{
    if (wydatki.empty() == true)
        return 1;
    else
        return wydatki.back().pobierzIdWydatku() + 1;
}


/*void ManagerFinansow::wyswietlDanePrzychodu(Przychod przychod) //TO DO TESTOW / BILANSU
{
    cout << endl << "Id:                 " << przychod.pobierzIdPrzychodu() << endl;
    cout << "Data:               " << przychod.pobierzDate() << endl;
    cout << "Opis:           " << przychod.pobierzOpis() << endl;
    cout << "Kwota:     " << przychod.pobierzKwote() << endl;
}*/
/*void ManagerFinansow::wyswietlWszystkichAdresatow() //ZAMIENIC NA WYSWIETL WSZYSTKIE TRANSAKCJE
{
    system("cls");
    if (!adresaci.empty())
    {
        cout << "             >>> ADRESACI <<<" << endl;
        cout << "-----------------------------------------------" << endl;
        for (vector <Adresat> :: iterator itr = adresaci.begin(); itr != adresaci.end(); itr++)
        {
            wyswietlDaneAdresata(*itr);
        }
        cout << endl;
    }
    else
    {
        cout << endl << "Ksiazka adresowa jest pusta." << endl << endl;
    }
    system("pause");
}*/



