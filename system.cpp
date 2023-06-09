#include <iostream>
using namespace std;

#include "system.h"


Account:: Account(string name, int account_number, float balance){

    this->name = name;
    this->account_number = account_number;
    this->balance = balance;

}

Account:: ~Account(){
    
}

void Account:: update_info(string name){

    this->name = name;


}

float Account::get_balance(){

    return this->balance;

}

string Account::deposit(float balance, float amount){
    this->balance+= amount;
    return "Your current balance is "+ to_string(this->balance);
}

string Account::withdraw(float balance, float amount){

    this->balance-=amount;
    return "Your current balance is "+ to_string(this->balance);
}

// string Account::transfer(float amount, int account_number1, int account_number2){

//     account_number1->withdraw(account_number1->get_balance(),amount);
//     account_number2->deposit(account_number2->get_balance(),amount) ;
//     return "Your transfer amount of " + to_string(amount) + " was successfull";
// }

float Account::interest(float balance, int num_month){
    float total;
    total = pow(balance * (1.07),(num_month/12));
    return total;
}

int Account::get_accountNumber(){
    return this->account_number;
}
// string Account::history(){


// }