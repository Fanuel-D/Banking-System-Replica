
#include <iostream> 
#include <unordered_map>


#include "system.h"
using namespace std;



int main(){
    
    
    string tempname;
    string tempPassword = "";
    int userchoice;
    unordered_map<int, Account*> my_dict;
    
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

        begin:
            cout << " Enter a password ";
            getline(cin, tempPassword);

            if (tempPassword.length() < 7)
            {
                cout << " Password has to be a minimum of 7 characters \n";
                goto begin;
            }
            
        again:
            int randacc = rand();
            // % 900000 + 100000;
            if (my_dict.count(randacc) > 0){
                goto again;
            }
            float balance = 0;
            Account* account = new Account(tempname, randacc, balance);
            my_dict.insert(make_pair(randacc, account));
           

            cout << "This is your account number: " << account->get_accountNumber() << endl;
            cout << "This is your balance: " << account->get_balance() << endl;
        }


    

    return 0;
}
}
}