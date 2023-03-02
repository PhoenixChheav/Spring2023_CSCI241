#ifndef BANK
#define BANK

class bank{
    
    char bank_name[31];
    bank object[20];
    int number;

    public:
        bank();
        void read_accounts(string);
        void process_transactions(string);
        void print();
}

#endif