#include <iostream>
using namespace std;

#include "system.h"


Account:: Account(string name, int account_number, int phone_number, float balance){

    this->name = name;
    this->account_number = account_number;
    this->phone_number = phone_number;
    this->balance = balance;

}

Account:: ~Account(string name, int account_number, int phone_number, float balance){
    delete Account(name, account_number, phone_number, balance);
}

void Account:: update_info(str name, int phone_number){

    this->name = name;
    this->phone_number = phone_number;

}

float Account::get_balance(){

    return this->balance;

}

string Account::deposit(float balance, int amount){

    this->balance+= amount;
    return "Your current balance is "+ to_string(this->balance);
}

string Account::withdraw(float balance, int amount){

    this->balance-=amount;
    return "Your current balance is "+ to_string(this->balance);
}

string Account::transfer(float amount, int account_number1, int account_number2){

    account_number1->withdraw(account_number1->get_balance(),amount);
    account_number2->deposit(account_number2->get_balance(),amount) ;
    return "Your transfer amount of " + to_string(amount) + " was successfull";
}

float Account::interest(int balance, int num_month){
    float total = balance(1+0.07)**(num_month/12);
    return total;
}