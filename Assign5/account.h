#ifndef ACCOUNT
#define ACCOUNT

class account{

    //private data member
        char account_number[11];
        char custom_name[21];
        double current_account_balance;

    //member function
    public:
        account(); //constructor
        int get_account_number();
        double get_balance();
        void process_deposit(double); //take deposit amount
        bool process_withdrawal(double); //take withdrawal amount 
        void print();
        

}

#endif