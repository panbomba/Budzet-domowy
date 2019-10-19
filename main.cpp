#include <iostream>
#include "BudzetDomowy.h"

using namespace std;

int main()
{
    char wybor;
    BudzetDomowy budzetDomowy ("users.xml"); //("Users.xml", "Incomes.xml", "Expenses.xml");

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
            budzetDomowy.rejestracjaUzytkownika();
        }
        else if (wybor == '2')
        {
            system("cls");
            if (budzetDomowy.logowanieUzytkownika())
            {
                budzetDomowy.wybierzOpcjeZMenuUzytkownika();
            }
        }
        else if (wybor == '3')
        {
            exit(0);
        }
    }
    return 0;
}
