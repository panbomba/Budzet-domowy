#include "BudzetDomowy.h"

void BudzetDomowy::rejestracjaUzytkownika()
{
    uzytkownikManager.rejestracjaUzytkownika();
}

void BudzetDomowy::wypiszWszystkichUzytkownikow()
{
    uzytkownikManager.wypiszWszystkichUzytkownikow();
}

int BudzetDomowy::logowanieUzytkownika()
{
    uzytkownikManager.logowanieUzytkownika();
    if (uzytkownikManager.czyUzytkownikJestZalogowany())
    {
        managerFinansow = new ManagerFinansow(NAZWA_PLIKU_Z_PRZYCHODAMI, NAZWA_PLIKU_Z_WYDATKAMI, uzytkownikManager.pobierzIdZalogowanegoUzytkownika());
    }
}

void BudzetDomowy::zmianaHaslaZalogowanegoUzytkownika()
{
    uzytkownikManager.zmianaHaslaZalogowanegoUzytkownika();
}

void BudzetDomowy::wylogowanieUzytkownika()
{
    uzytkownikManager.wylogowanieUzytkownika();
    delete managerFinansow;
    managerFinansow = NULL;
}

void BudzetDomowy::dodajPrzychod()
{
      if (uzytkownikManager.czyUzytkownikJestZalogowany())
      {
          managerFinansow->dodajPrzychod();
      }
}

void BudzetDomowy::dodajWydatek()
{
      if (uzytkownikManager.czyUzytkownikJestZalogowany())
      {
          managerFinansow->dodajWydatek();
      }
}

char BudzetDomowy::wybierzOpcjeZMenuUzytkownika()
{
    char wybor;
    while (uzytkownikManager.czyUzytkownikJestZalogowany())
    {
        //managerFinansow->wypiszPrzychodyZalogowanegoUzytkownika(); system("pause");
        //managerFinansow->sumaPrzychodowUzytkownika();
        managerFinansow->wypiszWydatkiZalogowanegoUzytkownika(); system("pause");
        managerFinansow->sumaWydatkowUzytkownika(); system("pause");

    system("cls");
    cout << " >>> MENU UZYTKOWNIKA <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Dodaj Przychod" << endl;
    cout << "2. Dodaj Wydatek" << endl;
    cout << "3. Bilans z biezacego miesiaca" << endl;
    cout << "4. Bilans z poprzedniego miesiaca" << endl;
    cout << "5. Bilans z wybranego okresu" << endl;
    cout << "---------------------------" << endl;
    cout << "6. Zmien haslo" << endl;
    cout << "7. Wyloguj sie" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    cin >> wybor;
                   switch (wybor)
            {
            case '1':
                dodajPrzychod();
        managerFinansow->wypiszWydatkiZalogowanegoUzytkownika(); system("pause");
        managerFinansow->sumaWydatkowUzytkownika();
                break;
            case '2':
                dodajWydatek();
                break;
            case '3':
                ;
                break;
            case '4':
                ;
                break;
            case '5':
                ;
                break;
            case '6':
                zmianaHaslaZalogowanegoUzytkownika();
                break;
            case '7':
                wylogowanieUzytkownika();
            }
    }
    return 0;
}

bool BudzetDomowy::czyUzytkownikJestZalogowany()
{
    uzytkownikManager.czyUzytkownikJestZalogowany();
}

int BudzetDomowy::pobierzIdZalogowanegoUzytkownika()
{
    uzytkownikManager.pobierzIdZalogowanegoUzytkownika();
}


