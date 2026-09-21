//Real-Time Application 2: Digital Payment Gateway 
//Problem Scenario :  A payment gateway supports credit-card, UPI, net-banking, and wallet payments. All payment modes implement a common 
//processing interface. 

// Include the input-output stream library.
// It provides cout and endl for displaying output.
#include <iostream>

// Include the memory library.
// It provides smart pointers such as unique_ptr
// and the function make_unique().
#include <memory>

// Include the string library.
// It allows us to use the string data type.
#include <string>

// Include the vector library.
// It allows us to store multiple payment objects.
#include <vector>

// Allows us to use cout, string, vector, etc.
// without writing std:: before them.
using namespace std;


// =====================================================
// BASE CLASS: PaymentMethod
// =====================================================

// Define a class named PaymentMethod.
// This is the base class for different payment methods.
class PaymentMethod {

protected:
    // Protected members can be accessed inside this class
    // and inside classes derived from it.

    string transactionId;
    // Stores the unique transaction ID.
    // Example: "TXN001"

    double amount;
    // Stores the payment amount.
    // Example: 2500


public:
    // Public members can be accessed from outside
    // the class through public functions.


    // Constructor of PaymentMethod.
    //
    // tid -> transaction ID
    // amt -> payment amount
    PaymentMethod(string tid, double amt)

        // Member initializer list.
        // It initializes the data members.
        : transactionId(tid),
          amount(amt)
    {
        // Constructor body is empty because
        // the members are initialized above.
    }


    // Pure virtual function.
    //
    // virtual allows derived classes to provide
    // their own implementation.
    //
    // bool means the function returns true or false.
    //
    // const means the function does not modify the object.
    //
    // = 0 makes this a pure virtual function.
    // Therefore, PaymentMethod is an abstract class.
    virtual bool processPayment() const = 0;


    // Virtual destructor.
    //
    // It allows proper destruction of derived objects
    // through a base-class pointer.
    //
    // = default asks the compiler to generate
    // the default destructor.
    virtual ~PaymentMethod() = default;
};


// =====================================================
// DERIVED CLASS: CreditCardPayment
// =====================================================

// CreditCardPayment inherits publicly from PaymentMethod.
class CreditCardPayment : public PaymentMethod {

private:
    // Stores a masked card number.
    // Example: "XXXX-XXXX1234"
    //
    // Masking helps avoid displaying the complete
    // card number.
    string maskedCardNumber;


public:
    // Constructor of CreditCardPayment.
    //
    // tid  -> transaction ID
    // amt  -> payment amount
    // card -> masked card number
    CreditCardPayment(string tid, double amt, string card)

        // Call the base-class constructor
        // to initialize transactionId and amount.
        //
        // Initialize maskedCardNumber using card.
        : PaymentMethod(tid, amt),
          maskedCardNumber(card)
    {
        // Constructor body.
    }


    // Override the pure virtual function
    // declared in PaymentMethod.
    //
    // override confirms that this function
    // replaces the base-class virtual function.
    bool processPayment() const override
    {
        // Display the credit-card transaction details.
        //
        // << sends values to cout.
        // transactionId stores the transaction ID.
        // amount stores the payment amount.
        // maskedCardNumber stores the masked card.
        cout << "Credit-card transaction " << transactionId
             << " for Rs. " << amount
             << " using " << maskedCardNumber
             << " completed." << endl;

        // Return true to indicate successful processing.
        return true;
    }
};


// =====================================================
// DERIVED CLASS: UPIPayment
// =====================================================

// UPIPayment inherits publicly from PaymentMethod.
class UPIPayment : public PaymentMethod {

private:
    // Stores the UPI ID.
    // Example: "student@upi"
    string upiId;


public:
    // Constructor of UPIPayment.
    //
    // tid -> transaction ID
    // amt -> payment amount
    // upi -> UPI ID
    UPIPayment(string tid, double amt, string upi)

        // Call the base-class constructor.
        : PaymentMethod(tid, amt),

          // Initialize the UPI ID.
          upiId(upi)
    {
        // Constructor body.
    }


    // Override the pure virtual function
    // from PaymentMethod.
    bool processPayment() const override
    {
        // Display the UPI transaction details.
        cout << "UPI transaction " << transactionId
             << " for Rs. " << amount
             << " from " << upiId
             << " completed." << endl;

        // Return true to indicate successful processing.
        return true;
    }
};


// =====================================================
// DERIVED CLASS: NetBankingPayment
// =====================================================

// NetBankingPayment inherits publicly from PaymentMethod.
class NetBankingPayment : public PaymentMethod {

private:
    // Stores the bank name.
    // Example: "Example Bank"
    string bankName;


public:
    // Constructor of NetBankingPayment.
    //
    // tid  -> transaction ID
    // amt  -> payment amount
    // bank -> bank name
    NetBankingPayment(string tid, double amt, string bank)

        // Call the base-class constructor.
        : PaymentMethod(tid, amt),

          // Initialize the bank name.
          bankName(bank)
    {
        // Constructor body.
    }


    // Override the pure virtual function
    // from PaymentMethod.
    bool processPayment() const override
    {
        // Display the net-banking transaction details.
        cout << "Net-banking transaction " << transactionId
             << " for Rs. " << amount
             << " through " << bankName
             << " completed." << endl;

        // Return true to indicate successful processing.
        return true;
    }
};


// =====================================================
// MAIN FUNCTION
// =====================================================

// Program execution starts from main().
int main()
{
    // Create a vector named payments.
    //
    // unique_ptr<PaymentMethod> means each element
    // is a smart pointer that owns one PaymentMethod object.
    //
    // The vector can store objects of derived classes
    // such as CreditCardPayment, UPIPayment,
    // and NetBankingPayment through base-class pointers.
    vector<unique_ptr<PaymentMethod>> payments;


    // Create a CreditCardPayment object dynamically
    // and add it to the vector.
    //
    // make_unique() creates a unique_ptr safely.
    //
    // "TXN001"         -> transaction ID
    // 2500             -> amount
    // "XXXX-XXXX1234"  -> masked card number
    payments.push_back(
        make_unique<CreditCardPayment>(
            "TXN001", 2500, "XXXX-XXXX1234"
        )
    );


    // Create a UPIPayment object and add it to the vector.
    //
    // "TXN002"        -> transaction ID
    // 1200            -> amount
    // "student@upi"   -> UPI ID
    payments.push_back(
        make_unique<UPIPayment>(
            "TXN002", 1200, "student@upi"
        )
    );


    // Create a NetBankingPayment object and add it
    // to the vector.
    //
    // "TXN003"       -> transaction ID
    // 5000           -> amount
    // "Example Bank" -> bank name
    payments.push_back(
        make_unique<NetBankingPayment>(
            "TXN003", 5000, "Example Bank"
        )
    );


    // Display the heading.
    cout << "=== Payment Gateway ===" << endl;


    // Range-based for loop.
    //
    // const means we will not modify the unique_ptr
    // while accessing it.
    //
    // auto automatically determines the variable type.
    //
    // & means payment refers to each existing
    // unique_ptr in the vector instead of copying it.
    for (const auto& payment : payments)
    {
        // -> is the arrow operator.
        //
        // payment is a unique_ptr.
        // payment->processPayment() calls the function
        // of the object managed by the pointer.
        //
        // Because processPayment() is virtual,
        // the correct derived-class version is called.
        payment->processPayment();
    }


    // Return 0 indicates successful program execution.
    //
    // When main() ends, the unique_ptr objects
    // automatically destroy the payment objects
    // they own.
    return 0;
}