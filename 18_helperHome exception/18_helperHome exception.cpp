#include <iostream>
#include <string>
#include "SocialNetwork.h"
using namespace std;


int main()
{
    SocialNetwork insta;
    while (true)
    {
        int choice;
        cout << " 1 - Register; \n 2 - Sign in; \n Enter :: ";
        cin >> choice;
        if (choice == 0) break;

        switch (choice)
        {
        case 1:
        {
            try
            {
                string login, password;
                cin.ignore();
                cout << "Enter login :: ";
                getline(cin,login);
                cout << "Enter password :: ";
                getline(cin,password);
                insta.register_(login, password);
            }
            catch (const std::exception& ex)
            {
                cout << typeid(ex).name() << " \t " << ex.what() << endl;
            }

        }
        case 2: 
        {

        }
        }
    }
    
}
