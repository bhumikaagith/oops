#include <iostream>
#include <string>
using namespace std;

class Account {
public:
    char owner[10];
    int accno;
    int balance;
    char type[10];

    Account(int initial_balance) : balance(initial_balance) {}

    void get_details() {
        cout << "Enter the Account holder's name: ";
        cin >> owner;
        cout << "Enter the account number: ";
        cin >> accno;
        cout << "Enter the type of account you have (savings or current): ";
        cin >> type;
    }

    void display_data() {
        cout << "The account holder's name is: " << owner << endl;
        cout << "The account number is: " << accno << endl;
        cout << "The account type is: " << type << endl;
        cout << "The current balance is: Rs" << balance << endl;
    }

    void update_balance(int new_balance) {
        balance = new_balance;
    }
};

class Customer {
public:
    void perform_transactions(Account &account) {
        int choice;
        int amount;

        do {
            cout << "\nCustomer Menu:" << endl;
            cout << "1. Send money" << endl;
            cout << "2. Check balance" << endl;
            cout << "3. Exit" << endl;
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    cout << "Enter the amount to send: ";
                    cin >> amount;
                    if (account.balance < amount) {
                        cout << "Insufficient Funds!" << endl;
                    } else {
                        account.update_balance(account.balance - amount);
                        cout << amount << " sent successfully!" << endl;
                        cout << "Available balance: Rs" << account.balance << endl;
                    }
                    break;
                case 2:
                    cout << "Your current balance is: Rs" << account.balance << endl;
                    break;
                case 3:
                    cout << "Exiting Customer menu..." << endl;
                    break;
                default:
                    cout << "Invalid choice!" << endl;
            }
        } while (choice != 3);
    }
};

class BankTeller {
public:
    void manage_transactions(Account &account) {
        int amount;
        cout << "\nBank Teller - Manage Transactions" << endl;
        cout << "Enter the amount to deposit or withdraw (use negative value for withdrawal): ";
        cin >> amount;
        account.update_balance(account.balance + amount);
        cout << "Transaction completed. New balance is: Rs" << account.balance << endl;
    }

    void process_loan_application() {
        int loan_amount;
        cout << "Enter the loan amount to apply for: ";
        cin >> loan_amount;
        cout << "Processing loan application for Rs" << loan_amount << "..." << endl;
        cout << "Loan approved successfully!" << endl;
    }
};

class Admin {
public:
    void generate_report(Account &account) {
        cout << "\nAdmin - Generating Account Report..." << endl;
        cout << "Account Holder: " << account.owner << endl;
        cout << "Account Number: " << account.accno << endl;
        cout << "Account Type: " << account.type << endl;
        cout << "Balance: Rs" << account.balance << endl;
        cout << "Report generated successfully!" << endl;
    }

    void oversee_transactions(Account &account) {
        cout << "\nAdmin - Overseeing Transactions for Account Number: " << account.accno << endl;
        cout << "Current Balance: Rs" << account.balance << endl;
        cout << "No suspicious activities detected." << endl;
    }
};

int main() {
    Account a(100000); 
    a.get_details();
    a.display_data();

    Customer customer;
    BankTeller teller;
    Admin admin;

    int role;
    cout << "\nChoose your role:" << endl;
    cout << "1. Customer\n2. Bank Teller\n3. Admin\nEnter choice: ";
    cin >> role;

    if (role == 1) {
        customer.perform_transactions(a);
    } else if (role == 2) {
        int operation;
        do {
            cout << "\nBank Teller Menu:" << endl;
            cout << "1. Manage Transactions" << endl;
            cout << "2. Process Loan Application" << endl;
            cout << "3. Exit" << endl;
            cout << "Enter your choice: ";
            cin >> operation;

            switch (operation) {
                case 1:
                    teller.manage_transactions(a);
                    break;
                case 2:
                    teller.process_loan_application();
                    break;
                case 3:
                    cout << "Exiting Bank Teller menu..." << endl;
                    break;
                default:
                    cout << "Invalid choice!" << endl;
            }
        } while (operation != 3);
    } else if (role == 3) {
        int operation;
        do {
            cout << "\nAdmin Menu:" << endl;
            cout << "1. Generate Report" << endl;
            cout << "2. Oversee Transactions" << endl;
            cout << "3. Exit" << endl;
            cout << "Enter your choice: ";
            cin >> operation;

            switch (operation) {
                case 1:
                    admin.generate_report(a);
                    break;
                case 2:
                    admin.oversee_transactions(a);
                    break;
                case 3:
                    cout << "Exiting Admin menu..." << endl;
                    break;
                default:
                    cout << "Invalid choice!" << endl;
            }
        } while (operation != 3);
    } else {
        cout << "Invalid role selected!" << endl;
    }

    return 0;
}
