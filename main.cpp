#include <iostream>
//#include "HomeBudget.h"

using namespace std;

int main()
{
    char wybor;
    //HomeBudget HomeBudget("Users.xml", "Incomes.xml", "Expenses.xml");

    while (true)
    {
        system("cls");
        cout << "BUDZET DOMOWY" << endl << endl;
        cout << "1. Rejestracja" << endl;
        cout << "2. Logowanie" << endl;
        cout << "3. Wyscie" << endl << endl;

        cout << endl << "Twoj wybor: ";
        cin >> wybor;

        if (wybor == '1')
        {
            system("cls");
            //HomeBudget.rejestracjaUzytkownika();
        }
        else if (wybor == '2')
        {
            system("cls");
            //if (KsiazkaAdresowa.logowanieUzytkownika())
            //{
            //    KsiazkaAdresowa.wybierzOpcjeZMenuUzytkownika();
            //}
        }
        else if (wybor == '3')
        {
            exit(0);
        }
    }
    return 0;
}
