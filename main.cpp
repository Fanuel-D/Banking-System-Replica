
#include <iostream> 
#include <unordered_map>


#include "system.h"
using namespace std;



int main(){
    
    
    string tempname;
    string tempPassword = "";
    int userchoice;
    unordered_map<int, Account*> my_dict;
    int user_num;
    
    while (true)
    {

        cout << " 1. Create an account " << endl;
        cout << " 2. Login" << endl;
        cout << " Choose the action to be performed : ";
        cin >> userchoice;

        
        if (userchoice == 1){
             system("cls");
            cout << "Enter Your Name: ";
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
        }else{

        start:
            cout << "Enter Your account number: ";
            cin >> user_num;
            
            int choice;
            auto it = my_dict.find(user_num);
            if (it != my_dict.end()) {
            // Key found, use the iterator to access the value
            Account* curr_account = it->second;
            
                cout << " 1. Deposit " << endl;
                cout << " 2. Withdraw" << endl;
                cout << " 3. Transfer " << endl;
                cout << " Choose the action to be performed : ";
                cin >> choice; 
                    if (choice == 1){

                    }else if (choice == 2){

                    }else if (choice == 3){

                    }
                } else {
                // Key not found
                cout << "Key not found in the unordered_map." << endl;
                goto start;
                }

        }
        }
        
        return 0;
        }


    

  
