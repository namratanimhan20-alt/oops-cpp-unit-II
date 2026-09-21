//Real-Time Application 3: Vehicle Fleet Management 
//Problem Scenario : A logistics company manages trucks, delivery vans, and delivery bikes. All are vehicles with common identity and fuel 
//attributes, while each has specialized properties


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
// It allows us to store multiple vehicle objects.
#include <vector>

// Allows us to use cout, string, vector, etc.
// without writing std:: before them.
using namespace std;


// =====================================================
// BASE CLASS: Vehicle
// =====================================================

// Define a class named Vehicle.
// This is the base class for different vehicle types.
class Vehicle {

protected:
    // Protected members can be accessed inside this class
    // and inside classes derived from it.

    string vehicleId;
    // Stores the unique ID of the vehicle.
    // Example: "V001"

    string registrationNumber;
    // Stores the registration number of the vehicle.
    // Example: "MH12-AB-1234"

    double fuelLevel;
    // Stores the current fuel level as a percentage.
    // Example: 100.0 means a full tank.


public:
    // Public members can be accessed from outside
    // the class through public functions.


    // Constructor of the Vehicle class.
    //
    // vid -> vehicle ID
    // reg -> registration number
    Vehicle(string vid, string reg)

        // Member initializer list.
        // It initializes the data members.
        : vehicleId(vid),
          registrationNumber(reg),
          fuelLevel(100.0)
    {
        // Constructor body is empty because
        // the members are initialized above.
    }


    // Function to start the vehicle engine.
    // const means this function does not modify the object.
    void startEngine() const
    {
        // Display a message showing that the engine started.
        cout << "Vehicle " << vehicleId
             << " engine started."
             << endl;
    }


    // Function to add fuel to the vehicle.
    // amount represents the quantity of fuel being added.
    void refuel(double amount)
    {
        // Add the given amount to the current fuel level.
        fuelLevel += amount;

        // Check whether the fuel level exceeds 100%.
        if (fuelLevel > 100.0)
        {
            // If it exceeds 100%, set it back to 100%.
            // This prevents the fuel level from exceeding
            // the maximum capacity.
            fuelLevel = 100.0;
        }
    }


    // Virtual function to display vehicle information.
    //
    // virtual allows derived classes to override this function.
    //
    // const means the function does not modify the object.
    virtual void displayInfo() const
    {
        // Display the vehicle ID.
        cout << "Vehicle ID: " << vehicleId

             // Display the registration number.
             << " | Registration: " << registrationNumber

             // Display the fuel level.
             << " | Fuel: " << fuelLevel << "%"

             // Move to the next line.
             << endl;
    }


    // Virtual destructor.
    //
    // It ensures proper destruction of derived objects
    // through a base-class pointer.
    //
    // = default asks the compiler to generate
    // the default destructor.
    virtual ~Vehicle() = default;
};


// =====================================================
// DERIVED CLASS: Truck
// =====================================================

// Truck inherits publicly from Vehicle.
class Truck : public Vehicle {

private:
    // Stores the cargo capacity of the truck.
    double cargoCapacity;


public:
    // Constructor of Truck.
    //
    // vid      -> vehicle ID
    // reg      -> registration number
    // capacity -> cargo capacity
    Truck(string vid, string reg, double capacity)

        // Call the base-class Vehicle constructor
        // to initialize vehicleId, registrationNumber,
        // and fuelLevel.
        //
        // Initialize cargoCapacity using capacity.
        : Vehicle(vid, reg),
          cargoCapacity(capacity)
    {
        // Constructor body.
    }


    // Override the virtual displayInfo() function
    // declared in the Vehicle class.
    //
    // override confirms that this function
    // replaces the base-class virtual function.
    void displayInfo() const override
    {
        // Display the vehicle type.
        cout << "Truck | ";

        // Call the displayInfo() function of the base class.
        // Vehicle:: means we are specifically calling
        // the Vehicle class version of the function.
        Vehicle::displayInfo();

        // Display the truck's cargo capacity.
        cout << "Cargo capacity: " << cargoCapacity
             << " tonnes"
             << endl;
    }
};


// =====================================================
// DERIVED CLASS: DeliveryVan
// =====================================================

// DeliveryVan inherits publicly from Vehicle.
class DeliveryVan : public Vehicle {

private:
    // Stores the number of packages loaded in the van.
    int packageCount;


public:
    // Constructor of DeliveryVan.
    //
    // vid      -> vehicle ID
    // reg      -> registration number
    // packages -> number of packages
    DeliveryVan(string vid, string reg, int packages)

        // Call the base-class Vehicle constructor.
        : Vehicle(vid, reg),

          // Initialize packageCount.
          packageCount(packages)
    {
        // Constructor body.
    }


    // Override the virtual displayInfo() function.
    void displayInfo() const override
    {
        // Display the vehicle type.
        cout << "Delivery Van | ";

        // Call the base-class displayInfo() function.
        Vehicle::displayInfo();

        // Display the number of loaded packages.
        cout << "Packages loaded: " << packageCount
             << endl;
    }
};


// =====================================================
// DERIVED CLASS: Bike
// =====================================================

// Bike inherits publicly from Vehicle.
class Bike : public Vehicle {

private:
    // Stores whether the bike has a delivery box.
    //
    // true  -> has a delivery box
    // false -> does not have a delivery box
    bool hasDeliveryBox;


public:
    // Constructor of Bike.
    //
    // vid    -> vehicle ID
    // reg    -> registration number
    // hasBox -> whether a delivery box is available
    Bike(string vid, string reg, bool hasBox)

        // Call the base-class Vehicle constructor.
        : Vehicle(vid, reg),

          // Initialize hasDeliveryBox.
          hasDeliveryBox(hasBox)
    {
        // Constructor body.
    }


    // Override the virtual displayInfo() function.
    void displayInfo() const override
    {
        // Display the vehicle type.
        cout << "Delivery Bike | ";

        // Call the base-class displayInfo() function.
        Vehicle::displayInfo();

        // Display the delivery-box status.
        //
        // Ternary operator:
        // condition ? value_if_true : value_if_false
        //
        // If hasDeliveryBox is true:
        // display "Available"
        //
        // If hasDeliveryBox is false:
        // display "Not available"
        cout << "Delivery box: "
             << (hasDeliveryBox ? "Available" : "Not available")
             << endl;
    }
};


// =====================================================
// MAIN FUNCTION
// =====================================================

// Program execution starts from main().
int main()
{
    // Create a vector named fleet.
    //
    // unique_ptr<Vehicle> means each element
    // is a smart pointer that owns one Vehicle object.
    //
    // The vector can store objects of derived classes
    // such as Truck, DeliveryVan, and Bike
    // through base-class pointers.
    vector<unique_ptr<Vehicle>> fleet;


    // Create a Truck object dynamically
    // and add it to the fleet vector.
    //
    // "V001"          -> vehicle ID
    // "MH12-AB-1234"  -> registration number
    // 10.5            -> cargo capacity in tonnes
    fleet.push_back(
        make_unique<Truck>(
            "V001", "MH12-AB-1234", 10.5
        )
    );


    // Create a DeliveryVan object and add it to the vector.
    //
    // "V002"          -> vehicle ID
    // "MH12-CD-5678"  -> registration number
    // 50              -> number of packages
    fleet.push_back(
        make_unique<DeliveryVan>(
            "V002", "MH12-CD-5678", 50
        )
    );


    // Create a Bike object and add it to the vector.
    //
    // "V003"          -> vehicle ID
    // "MH12-EF-9012"  -> registration number
    // true            -> delivery box is available
    fleet.push_back(
        make_unique<Bike>(
            "V003", "MH12-EF-9012", true
        )
    );


    // Display the heading.
    cout << "=== Fleet Status ===" << endl;


    // Range-based for loop.
    //
    // const means we will not modify the unique_ptr
    // while accessing it.
    //
    // auto automatically determines the variable type.
    //
    // & means vehicle refers to the existing
    // unique_ptr in the vector instead of copying it.
    for (const auto& vehicle : fleet)
    {
        // Call startEngine() through the smart pointer.
        //
        // -> accesses a member function through a pointer.
        vehicle->startEngine();


        // Call displayInfo() through the smart pointer.
        //
        // Because displayInfo() is virtual,
        // the appropriate derived-class version is called.
        vehicle->displayInfo();


        // Print a blank line after each vehicle's details.
        cout << endl;
    }


    // Return 0 indicates successful program execution.
    //
    // When main() ends, the unique_ptr objects
    // automatically destroy the vehicle objects they own.
    return 0;
}