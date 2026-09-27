//Mini-Project Problem Statement :
//Banking System with Account Hierarchy : Create a base Account class and derived classes SavingsAccount, CurrentAccount, and FixedDepositAccount. 
//Include account number, holder name, balance, deposit, withdrawal, and interest-calculation features. Use virtual functions for account-specific behavior. 

#include <iostream>      // Provides input and output functions such as cin and cout.
#include <iomanip>       // Provides formatting functions such as fixed and setprecision.
#include <memory>        // Provides smart pointers such as unique_ptr and make_unique.
#include <string>        // Provides the string data type.
#include <vector>        // Provides the vector container.

using namespace std;     // Allows us to use standard library names without writing std::.


// Base class representing a general bank account.
class Account {
protected:
    string accountNumber;    // Stores the unique account number.
    string holderName;       // Stores the name of the account holder.
    double balance;          // Stores the current account balance.

public:

    // Constructor initializes the account details.
    Account(string accNo, string name, double initialBalance)
        : accountNumber(accNo), holderName(name), balance(initialBalance) {
    }

    // Virtual destructor allows proper destruction of derived class objects.
    virtual ~Account() = default;

    // Function to deposit money into the account.
    void deposit(double amount) {

        // Check whether the deposit amount is positive.
        if (amount > 0) {

            // Add the deposit amount to the current balance.
            balance += amount;

            // Display a successful deposit message.
            cout << "Deposit of Rs. " << amount << " successful.\n";

        } else {

            // Display an error message for an invalid amount.
            cout << "Invalid deposit amount.\n";
        }
    }

    // Virtual function to withdraw money from the account.
    // Derived classes can override this function if required.
    virtual void withdraw(double amount) {

        // Check whether the withdrawal amount is positive.
        if (amount <= 0) {

            // Display an error message for an invalid amount.
            cout << "Invalid withdrawal amount.\n";

        // Check whether the withdrawal amount is greater than the balance.
        } else if (amount > balance) {

            // Display an insufficient balance message.
            cout << "Insufficient balance.\n";

        } else {

            // Subtract the withdrawal amount from the balance.
            balance -= amount;

            // Display a successful withdrawal message.
            cout << "Withdrawal of Rs. " << amount << " successful.\n";
        }
    }

    // Pure virtual function for calculating account-specific interest.
    virtual double calculateInterest() const = 0;

    // Pure virtual function for displaying the account type.
    virtual void displayAccountType() const = 0;

    // Function to display common account information.
    void displayBasicInfo() const {

        // Display the account number.
        cout << "Account Number : " << accountNumber << endl;

        // Display the account holder name.
        cout << "Holder Name    : " << holderName << endl;

        // Display the current balance with two decimal places.
        cout << "Balance        : Rs. "
             << fixed << setprecision(2)
             << balance << endl;
    }

    // Function to display the calculated interest.
    void displayInterest() const {

        // Calculate and display the interest amount.
        cout << "Interest       : Rs. "
             << fixed << setprecision(2)
             << calculateInterest() << endl;
    }
};


// Derived class representing a Savings Account.
class SavingsAccount : public Account {
private:

    // Stores the annual interest rate for the savings account.
    const double interestRate = 4.0;

public:

    // Constructor initializes the Savings Account.
    SavingsAccount(string accNo, string name, double initialBalance)
        : Account(accNo, name, initialBalance) {
    }

    // Override the interest calculation for a Savings Account.
    double calculateInterest() const override {

        // Calculate interest using the balance and interest rate.
        return balance * interestRate / 100;
    }

    // Override the function to display the account type.
    void displayAccountType() const override {

        // Display Savings Account as the account type.
        cout << "Account Type   : Savings Account" << endl;
    }
};


// Derived class representing a Current Account.
class CurrentAccount : public Account {
private:

    // Current Account has no interest in this example.
    const double interestRate = 0.0;

public:

    // Constructor initializes the Current Account.
    CurrentAccount(string accNo, string name, double initialBalance)
        : Account(accNo, name, initialBalance) {
    }

    // Override the interest calculation for a Current Account.
    double calculateInterest() const override {

        // Calculate interest using the current account interest rate.
        return balance * interestRate / 100;
    }

    // Override the function to display the account type.
    void displayAccountType() const override {

        // Display Current Account as the account type.
        cout << "Account Type   : Current Account" << endl;
    }
};


// Derived class representing a Fixed Deposit Account.
class FixedDepositAccount : public Account {
private:

    // Stores the annual interest rate for the fixed deposit account.
    const double interestRate = 7.0;

public:

    // Constructor initializes the Fixed Deposit Account.
    FixedDepositAccount(string accNo, string name, double initialBalance)
        : Account(accNo, name, initialBalance) {
    }

    // Override the interest calculation for a Fixed Deposit Account.
    double calculateInterest() const override {

        // Calculate interest using the balance and interest rate.
        return balance * interestRate / 100;
    }

    // Override the function to display the account type.
    void displayAccountType() const override {

        // Display Fixed Deposit Account as the account type.
        cout << "Account Type   : Fixed Deposit Account" << endl;
    }
};


// Function to display complete information of an account.
void displayAccount(const Account& account) {

    // Display a separator line.
    cout << "----------------------------------------" << endl;

    // Display the specific account type.
    account.displayAccountType();

    // Display common account details.
    account.displayBasicInfo();

    // Display calculated interest.
    account.displayInterest();

    // Display another separator line.
    cout << "----------------------------------------" << endl;
}


// Main function where program execution begins.
int main() {

    // Display the title of the banking system.
    cout << "========================================" << endl;
    cout << "        BANKING SYSTEM" << endl;
    cout << "========================================" << endl;

    // Create a Savings Account object.
    SavingsAccount savings("SA1001", "Amit", 50000);

    // Create a Current Account object.
    CurrentAccount current("CA2001", "Sneha", 75000);

    // Create a Fixed Deposit Account object.
    FixedDepositAccount fixedDeposit("FD3001", "Rohan", 100000);

    // Deposit money into the Savings Account.
    cout << "\nSavings Account Transaction:" << endl;
    savings.deposit(5000);

    // Withdraw money from the Savings Account.
    savings.withdraw(2000);

    // Display the updated Savings Account details.
    displayAccount(savings);


    // Deposit money into the Current Account.
    cout << "\nCurrent Account Transaction:" << endl;
    current.deposit(10000);

    // Withdraw money from the Current Account.
    current.withdraw(5000);

    // Display the updated Current Account details.
    displayAccount(current);


    // Deposit money into the Fixed Deposit Account.
    cout << "\nFixed Deposit Account Transaction:" << endl;
    fixedDeposit.deposit(20000);

    // Withdraw money from the Fixed Deposit Account.
    fixedDeposit.withdraw(10000);

    // Display the updated Fixed Deposit Account details.
    displayAccount(fixedDeposit);


    // Display a message indicating the use of polymorphism.
    cout << "\nPolymorphism Demonstration:" << endl;

    // Create a vector of unique pointers to the base Account class.
    vector<unique_ptr<Account>> accounts;

    // Add a Savings Account object to the vector.
    accounts.push_back(
        make_unique<SavingsAccount>("SA1002", "Priya", 60000)
    );

    // Add a Current Account object to the vector.
    accounts.push_back(
        make_unique<CurrentAccount>("CA2002", "Rahul", 80000)
    );

    // Add a Fixed Deposit Account object to the vector.
    accounts.push_back(
        make_unique<FixedDepositAccount>("FD3002", "Neha", 120000)
    );

    // Traverse through all account objects.
    for (const auto& account : accounts) {

        // Display account information using the base class pointer.
        // Virtual functions call the appropriate derived class functions.
        displayAccount(*account);
    }

    // Display the end message.
    cout << "\nBanking System execution completed successfully." << endl;

    // Return 0 to indicate successful program execution.
    return 0;
}
