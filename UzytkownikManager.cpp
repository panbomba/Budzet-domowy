#include "UzytkownikManager.h"
#include "MetodyPomocnicze.h"
#include "ObslugaPlikowXML.h"

void UzytkownikManager::rejestracjaUzytkownika()
{
    ObslugaPlikowXML ObslugaPlikowXML;
    Uzytkownik uzytkownik = podajDaneNowegoUzytkownika();

    uzytkownicy.push_back(uzytkownik);

    ObslugaPlikowXML.dodajUzytkownikaDoPliku(uzytkownik);

    cout << endl << "Konto zalozono pomyslnie" << endl << endl;
    system("pause");
}

Uzytkownik UzytkownikManager::podajDaneNowegoUzytkownika()
{
    Uzytkownik uzytkownik;
    ObslugaPlikowXML ObslugaPlikowXML;

    uzytkownik.ustawIdUzytkownika(ObslugaPlikowXML.wczytajIdOstatniegoUzytkownikaZPliku()+1);

    string imie;
        cout << "Podaj imie: ";
        cin >> imie;
        uzytkownik.ustawImie(imie);

    string nazwisko;
    cout << "Podaj nazwisko: ";
    cin >> nazwisko;
    uzytkownik.ustawNazwisko(nazwisko);

    string login;
    do
    {
    cout << "Podaj login: ";
    cin >> login;
    uzytkownik.ustawLogin(login);
    }
    while (czyIstniejeLogin(uzytkownik.pobierzLogin()) == true);

    string haslo;
    cout << "Podaj haslo: ";
    cin >> haslo;
    uzytkownik.ustawHaslo(haslo);

    return uzytkownik;
}

int UzytkownikManager::pobierzIdNowegoUzytkownika()
{
    if (uzytkownicy.empty() == true)
        return 1;
    else
        return uzytkownicy.back().pobierzIdUzytkownika() + 1;
}

bool UzytkownikManager::czyIstniejeLogin(string login)
{
    for (int i=0; i<uzytkownicy.size(); i++)
    {
        if (uzytkownicy[i].pobierzLogin() == login)
        {
            cout << endl << "Istnieje uzytkownik o takim loginie." << endl;
            return true;
        }
    }
    return false;
}

void UzytkownikManager::wypiszWszystkichUzytkownikow()
{
    for (int i=0; i<uzytkownicy.size(); i++)
    {
            cout << uzytkownicy[i].pobierzIdUzytkownika() << endl;
            cout << uzytkownicy[i].pobierzImie() << endl;
            cout << uzytkownicy[i].pobierzNazwisko() << endl;
            cout << uzytkownicy[i].pobierzLogin() << endl;
            cout << uzytkownicy[i].pobierzHaslo() << endl;
    }
    system("pause");
}

int UzytkownikManager::logowanieUzytkownika()
{
    Uzytkownik uzytkownik;

    string login1 = "", haslo1 = "";

    cout << endl << "Podaj login: ";
    cin >> login1;

    vector <Uzytkownik>::iterator itr = uzytkownicy.begin();
    while (itr != uzytkownicy.end())
    {
        if (itr -> pobierzLogin() == login1)
        {
            for (int iloscProb = 3; iloscProb > 0; iloscProb--)
            {
                cout << "Podaj haslo. Pozostalo prob: " << iloscProb << ": ";
                cin >> haslo1;

                if (itr -> pobierzHaslo() == haslo1)
                {
                    cout << endl << "Zalogowales sie." << endl << endl;
                    system("pause");
                    idZalogowanegoUzytkownika = itr -> pobierzIdUzytkownika();
                    return idZalogowanegoUzytkownika;
                    cout << idZalogowanegoUzytkownika; system ("pause");
                }
            }
            cout << "Wprowadzono 3 razy bledne haslo." << endl;
            system("pause");
            return 0;
        }
        itr++;
    }
    cout << "Nie ma uzytkownika z takim loginem" << endl << endl;
    system("pause");
    return 0;
}

void UzytkownikManager::zmianaHaslaZalogowanegoUzytkownika()
{
    MetodyPomocnicze metodyPomocnicze;
    Uzytkownik uzytkownik;
    string noweHaslo = "";
    cout << "Podaj nowe haslo: ";
    cin >> noweHaslo;

    for (vector <Uzytkownik>::iterator itr = uzytkownicy.begin(); itr != uzytkownicy.end(); itr++)
    {
        if (itr -> pobierzIdUzytkownika() == idZalogowanegoUzytkownika)
        {
            itr -> ustawHaslo(noweHaslo);
            cout << "Haslo zostalo zmienione." << endl << endl;
            system("pause");
        }
    }
//    plikZUzytkownikami.zapiszWszystkichUzytkownikowDoPliku(uzytkownicy);
}

bool UzytkownikManager::czyUzytkownikJestZalogowany()
{
    if (idZalogowanegoUzytkownika > 0)
        return true;
    else
        return false;
}

int UzytkownikManager::pobierzIdZalogowanegoUzytkownika()
{
    ObslugaPlikowXML obslugaPlikowXML;
    int idZalogowanegoUzytkownika = obslugaPlikowXML.wczytajIdOstatniegoUzytkownikaZPliku();
    return idZalogowanegoUzytkownika;
}

void UzytkownikManager::wylogowanieUzytkownika()
{
    idZalogowanegoUzytkownika = 0;
}

void UzytkownikManager::wczytajUzytkownikowZPliku()
{
    ObslugaPlikowXML ObslugaPlikowXML;
    uzytkownicy = ObslugaPlikowXML.wczytajUzytkownikowZPliku();
}
