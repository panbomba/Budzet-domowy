#include "ManagerFinansow.h"
#include "MetodyPomocnicze.h"

void ManagerFinansow::dodajPrzychod(int idZalogowanegoUzytkownika)
{


    //przychod.ustawIdPrzychodu(pobierzIdNowegoUzytkownika()) //TO DOPISAC
    //przychod.pobierzIdUzytkownika(idZalogowanegoUzytkownika);

    system("cls");
    cout << " >>> DODAWANIE NOWEGO PRZYCHODU <<<" << endl << endl;
    Przychod przychod;
    ObslugaPlikowXML ObslugaPlikowXML;
    przychod = podajDanePrzychodu();

    przychody.push_back(przychod);

    ObslugaPlikowXML.dodajPrzychodDoPliku(przychod);

    cout << endl << "TRANSAKCJA DODANA" << endl << endl;
    system("pause");
    //if (plikZAdresatami.dopiszAdresataDoPliku(adresat))
    //    cout << "Nowy adresat zostal dodany" << endl;
    //else
    //cout << "Blad. Nie udalo sie dodac nowego adresata do pliku." << endl;
}

void ManagerFinansow::dodajWydatek()
{
    Wydatek wydatek;

    system("cls");
    cout << " >>> DODAWANIE NOWEGO WYDATKU <<<" << endl << endl;

    wydatek = podajDaneWydatku();

    wydatki.push_back(wydatek);
    //if (plikZAdresatami.dopiszAdresataDoPliku(adresat))
    //    cout << "Nowy adresat zostal dodany" << endl;
    //else
    //cout << "Blad. Nie udalo sie dodac nowego adresata do pliku." << endl;
    system ("pause");
}

Przychod ManagerFinansow::podajDanePrzychodu() //JAK ZROBIC ZEBY ALBO BYL PRZYCHOD ALBO WYDATEK?
{
    MetodyPomocnicze metodyPomocnicze;
    Przychod przychod;
    string data, opis;
    float kwota;

    przychod.ustawIdPrzychodu(pobierzIdNowegoPrzychodu()); //TO DOPISAC
    przychod.ustawIdUzytkownika(idZalogowanegoUzytkownika);

    //adresat.ustawId( (plikZAdresatami.pobierzIdOstatniegoAdresata() + 1) );
    //przychod.ustawIdUzytkownika(ID_ZALOGOWANEGO_UZYTKOWNIKA);
    cin.clear();
    cin.sync();
    cout << "Podaj date transakcji w formacie RRRR-MM-DD: ";
    data = metodyPomocnicze.wczytajLinie();
    //TUTAJ CHECK CZY POPRAWNY FORMAT
    cin.clear();
    cin.sync();
    cout << "Dadaj opis: ";
    opis = metodyPomocnicze.wczytajLinie();
    cin.clear();
    cin.sync();
    cout << "Podaj kwote transakcji: ";
    cin >> kwota;
    //kwota = metodyPomocnicze.wczytajLinie();
    //TUTAJ CHECK CZY PRZECINEK

    przychod.ustawDate(data);
    przychod.ustawOpis(opis);
    przychod.ustawKwote(kwota);

    return przychod; // TUTAJ SIE ZAWIESZA
    cout << "Transakcja zapisana."; system("pause"); //DLACZEGO NIE WYSWIETLA?
}

int ManagerFinansow::pobierzIdNowegoPrzychodu()
{
    if (przychody.empty() == true)
        return 1;
    else
        return przychody.back().pobierzIdPrzychodu() + 1;
}

Wydatek ManagerFinansow::podajDaneWydatku() //JAK ZROBIC ZEBY ALBO BYL PRZYCHOD ALBO WYDATEK?
{
    MetodyPomocnicze metodyPomocnicze;
    Wydatek wydatek;
    string data, opis;
    float kwota;

    //adresat.ustawId( (plikZAdresatami.pobierzIdOstatniegoAdresata() + 1) );
    //przychod.ustawIdUzytkownika(ID_ZALOGOWANEGO_UZYTKOWNIKA);
    cin.clear();
    cin.sync();
    cout << "Podaj date transakcji w formacie RRRR-MM-DD: ";
    data = metodyPomocnicze.wczytajLinie();
    //TUTAJ CHECK CZY POPRAWNY FORMAT
    cin.clear();
    cin.sync();
    cout << "Dadaj opis: ";
    opis = metodyPomocnicze.wczytajLinie();
    cin.clear();
    cin.sync();
    cout << "Podaj kwote transakcji: ";
    cin >> kwota;
    //kwota = metodyPomocnicze.wczytajLinie();
    //TUTAJ CHECK CZY PRZECINEK

    wydatek.ustawDate(data);
    wydatek.ustawOpis(opis);
    wydatek.ustawKwote(kwota);

    return wydatek; // TUTAJ SIE ZAWIESZA
    cout << "Transakcja zapisana.";
}

void ManagerFinansow::wyswietlDanePrzychodu(Przychod przychod)
{
    cout << endl << "Id:                 " << przychod.pobierzIdPrzychodu() << endl;
    cout << "Data:               " << przychod.pobierzDate() << endl;
    cout << "Opis:           " << przychod.pobierzOpis() << endl;
    cout << "Kwota:     " << przychod.pobierzKwote() << endl;
}
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



