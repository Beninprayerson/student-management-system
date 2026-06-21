#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Bank {
public:
    int accNo;
    string name;
    float balance;

    void createAccount() {
        cout << "Enter Account Number: ";
        cin >> accNo;

        cin.ignore();

        cout << "Enter Name: ";
        getline(cin, name);

        cout << "Enter Initial Balance: ";
        cin >> balance;

        saveToFile();

        cout << "\nAccount Created Successfully\n";
    }

    void saveToFile() {
        ofstream file("bank.txt", ios::app);

        file << accNo << endl;
        file << name << endl;
        file << balance << endl;

        file.close();
    }

    void deposit() {
        float amount;

        cout << "Enter Deposit Amount: ";
        cin >> amount;

        balance += amount;

        cout << "Updated Balance: " << balance << endl;
    }

    void withdraw() {
        float amount;

        cout << "Enter Withdraw Amount: ";
        cin >> amount;

        if (amount <= balance) {
            balance -= amount;
            cout << "Withdrawal Successful\n";
        } else {
            cout << "Insufficient Balance\n";
        }
    }

    void showBalance() {
        cout << "\nCurrent Balance: " << balance << endl;
    }
};

int main() {

    Bank user;

    int choice;

    do {

        cout << "\n===== BANK MANAGEMENT =====";

        cout << "\n1. Create Account";
        cout << "\n2. Deposit";
        cout << "\n3. Withdraw";
        cout << "\n4. Check Balance";
        cout << "\n0. Exit";

        cout << "\nEnter Choice: ";
        cin >> choice;

        switch(choice) {

        case 1:
            user.createAccount();
            break;

        case 2:
            user.deposit();
            break;

        case 3:
            user.withdraw();
            break;

        case 4:
            user.showBalance();
            break;

        case 0:
            cout << "\nProgram Closed";
            break;

        default:
            cout << "\nInvalid Choice";
        }

    } while(choice != 0);

    return 0;
}