#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    vector<int> accountnumber;
    vector<string> name, password;
    vector<float> balance;
    string tempname;
    int userchoice, currentaccount = 0;
    string tempPassword = "";

    while (true)
    {

        cout << " 1. Create an account " << endl;
        cout << " 2. Login" << endl;
        cout << " 3. Deposit " << endl;
        cout << " 4. Withdraw" << endl;
        cout << " 5. Transfer " << endl;
        cout << " Choose the action to be performed : ";
        cin >> userchoice;

        switch (userchoice)
        {
        case 1:
        {
            system("cls");
            cout << "Enter Your Name ";
            getline(cin.ignore(), tempname);
            name.push_back(tempname);
        begin:
            cout << " Enter a password ";
            getline(cin, tempPassword);

            if (tempPassword.length() < 7)
            {
                cout << " Password has to be a minimum of 7 characters \n";
                goto begin;
            }
            else
            {
                password.push_back(tempPassword);
            }

        again:
            int randacc = rand();
            // % 900000 + 100000;

            for (int i = 0; i < accountnumber.size(); i++)
            {
                if (accountnumber[i] == randacc)
                {
                    goto again;
                }
            }
            accountnumber.push_back(randacc);
            balance.push_back(0);
            cout << "This is your account number: " << accountnumber[accountnumber.size() - 1] << endl;
            cout << "This is your balance: " << balance[accountnumber.size() - 1] << endl;
            break;
        }
        case 2:
        {
            system("cls");
                }
        }
    }
}
