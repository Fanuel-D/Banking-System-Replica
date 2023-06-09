
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
    bool flip= true;
    while (flip)
    {

        cout << " 1. Create an account " << endl;
        cout << " 2. Login" << endl;
        cout << " 3. Quit" << endl;
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
            if (my_dict.count(randacc) > 0){
                goto again;
            }
            float balance = 0;
            Account* account = new Account(tempname, randacc, balance);
            my_dict.insert(make_pair(randacc, account));
           

            cout << "This is your account number: " << account->get_accountNumber() << endl;
            cout << "This is your balance: " << account->get_balance() << endl;
        }else if (userchoice == 2){

        start:
            cout << "Enter Your account number: ";
            cin >> user_num;
            
            int choice;
            auto it = my_dict.find(user_num);
            if (it != my_dict.end()) {
            // Key found, use the iterator to access the value
            Account* curr_account = it->second;
            end:
                cout << " 1. Deposit " << endl;
                cout << " 2. Withdraw" << endl;
                cout << " 3. Transfer " << endl;
                cout<< " 4. Calculate my intreset "<< endl;
                cout << " Choose the action to be performed : ";
                cin >> choice; 
                    if (choice == 1){
                        float amount;
                        cout<< "Please, enter amount: ";
                        cin>> amount;
                        curr_account->deposit(curr_account->get_balance(), amount);
                        goto end;
                    }else if (choice == 2){
                        float amount;
                        cout<< "Please, enter amount: ";
                        cin>> amount;
                        while(amount > curr_account->get_balance()){
                            cout<< "You don't have enough funds to make this withdrawal";
                            cout<< "Please, input an appropriate amount";
                            cin>> amount;
                        }
                        curr_account->withdraw(curr_account->get_balance(), amount);
                        goto end;
                    }else if (choice == 3){
                        int acc_num;
                        float amount;
                        cout<<"Enter account number to which you want to transfer the funds to: ";
                        cin>> acc_num;
                        auto it = my_dict.find(acc_num);
                        

                        while(it == my_dict.end()){
                            cout<<"Account number not found, re-enter the account number: ";
                            cin>> acc_num;
                        }
                        Account* trans_account = it->second;
                        cout<< "Please, enter amount: ";
                        cin>> amount;
                        while(amount > curr_account->get_balance()){
                            cout<< "You don't have enough funds to make this withdrawal";
                            cout<< "Please, input an appropriate amount";
                            cin>> amount;
                        }
                        curr_account->withdraw(curr_account->get_balance(), amount);
                        trans_account->deposit(trans_account->get_balance(),amount);
                        goto end;
                    }else if (choice == 4){
                        float months;
                        cout<<"How many months ahead do you want to calculate your interest";
                        cin>> months;
                        float total= curr_account->interest(curr_account->get_balance(),months);
                        cout<<"This is your compounded total amount"<<total<<endl;
                        goto end;

                    }
                } else {
                // Key not found
                cout << "Key not found in the unordered_map." << endl;
                goto start;
                }
        }else {
            flip = false;
            cout<< "Good Bye!"<<endl;
        }
        
    return 0;
}
}
    

    

  
