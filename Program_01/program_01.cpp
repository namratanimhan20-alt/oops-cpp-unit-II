//Real-Time Application 1: Employee Payroll System 
//Problem Scenario : A company employs full-time employees, part-time employees, and interns. All employees share common information, 
//but salary calculations vary by employment type. 

// Include the input-output stream library.
// It provides cout and endl for displaying output.
#include <iostream>

// Include the string library.
// It allows us to use the string data type.
#include <string>

// Allows us to use cout, string, etc.
// without writing std:: before them.
using namespace std;


// =====================================================
// BASE CLASS: Employee
// =====================================================

// Define a class named Employee.
// This is the base class from which other employee
// classes will inherit.
class Employee {

protected:
    // Protected members can be accessed inside this class
    // and inside classes derived from it.

    int empId;
    // Stores the employee ID.

    string name;
    // Stores the employee's name.

    string department;
    // Stores the employee's department.


public:
    // Public members can be accessed from outside
    // the class through objects.


    // Constructor of the Employee class.
    //
    // id   -> employee ID
    // n    -> employee name
    // dept -> employee department
    Employee(int id, string n, string dept)

        // Member initializer list.
        // It initializes the data members.
        : empId(id),
          name(n),
          department(dept)
    {
        // Constructor body is empty because
        // the members are initialized above.
    }


    // Function to display common employee information.
    // const means this function does not modify the object.
    void displayBasicInfo() const
    {
        // Display employee ID.
        cout << "ID: " << empId

             // Display employee name.
             << " | Name: " << name

             // Display department.
             << " | Department: " << department;
    }


    // Pure virtual function.
    //
    // virtual allows derived classes to provide
    // their own implementation.
    //
    // double means the function returns a decimal value.
    //
    // const means it does not modify the object.
    //
    // = 0 makes this a pure virtual function.
    // It means Employee is an abstract class,
    // and derived classes must implement this function.
    virtual double calculateSalary() const = 0;


    // Virtual destructor.
    //
    // virtual ensures proper destruction when a derived
    // object is deleted through a base-class pointer.
    //
    // = default asks the compiler to generate
    // the default destructor automatically.
    virtual ~Employee() = default;
};


// =====================================================
// DERIVED CLASS: FullTimeEmployee
// =====================================================

// FullTimeEmployee inherits publicly from Employee.
//
// public Employee means public members of Employee
// remain public in FullTimeEmployee.
class FullTimeEmployee : public Employee {

private:
    // Private member of FullTimeEmployee.
    // It stores the monthly salary.

    double monthlySalary;


public:
    // Constructor of FullTimeEmployee.
    //
    // It receives employee details and monthly salary.
    FullTimeEmployee(int id, string n, string dept, double salary)

        // Call the base-class Employee constructor
        // to initialize empId, name, and department.
        //
        // monthlySalary(salary) initializes the salary.
        : Employee(id, n, dept),
          monthlySalary(salary)
    {
        // Constructor body.
    }


    // Override the pure virtual function
    // declared in the Employee class.
    //
    // override tells the compiler that this function
    // is intended to replace a virtual function
    // from the base class.
    double calculateSalary() const override
    {
        // Return the monthly salary.
        return monthlySalary;
    }


    // Function to display full-time employee details.
    void display() const
    {
        // Call the inherited function
        // to display common employee information.
        displayBasicInfo();

        // Display employee type and salary.
        cout << " | Type: Full-Time | Salary: Rs. "
             << calculateSalary()
             << endl;
    }
};


// =====================================================
// DERIVED CLASS: PartTimeEmployee
// =====================================================

// PartTimeEmployee inherits from Employee.
class PartTimeEmployee : public Employee {

private:
    // Stores the payment received per hour.
    double hourlyRate;

    // Stores the number of hours worked.
    int hoursWorked;


public:
    // Constructor of PartTimeEmployee.
    //
    // rate  -> payment per hour
    // hours -> number of hours worked
    PartTimeEmployee(int id, string n, string dept,
                     double rate, int hours)

        // Call the base-class constructor.
        : Employee(id, n, dept),

          // Initialize hourly rate.
          hourlyRate(rate),

          // Initialize hours worked.
          hoursWorked(hours)
    {
        // Constructor body.
    }


    // Override the pure virtual function
    // from the Employee class.
    double calculateSalary() const override
    {
        // Calculate salary using:
        // hourly rate × hours worked.
        return hourlyRate * hoursWorked;
    }


    // Function to display part-time employee details.
    void display() const
    {
        // Display common employee information.
        displayBasicInfo();

        // Display employee type and calculated salary.
        cout << " | Type: Part-Time | Salary: Rs. "
             << calculateSalary()
             << endl;
    }
};


// =====================================================
// DERIVED CLASS: Intern
// =====================================================

// Intern inherits from Employee.
class Intern : public Employee {

private:
    // Stores the stipend received by the intern.
    double stipend;


public:
    // Constructor of Intern.
    //
    // stipendAmount -> amount paid to the intern
    Intern(int id, string n, string dept,
           double stipendAmount)

        // Call the base-class Employee constructor.
        : Employee(id, n, dept),

          // Initialize stipend.
          stipend(stipendAmount)
    {
        // Constructor body.
    }


    // Override the pure virtual function
    // from the Employee class.
    double calculateSalary() const override
    {
        // Return the intern's stipend.
        return stipend;
    }


    // Function to display intern details.
    void display() const
    {
        // Display common employee information.
        displayBasicInfo();

        // Display employee type and stipend.
        cout << " | Type: Intern | Stipend: Rs. "
             << calculateSalary()
             << endl;
    }
};


// =====================================================
// MAIN FUNCTION
// =====================================================

// Program execution starts from main().
int main()
{
    // Create a FullTimeEmployee object named f1.
    //
    // 101       -> employee ID
    // "Amit"    -> name
    // "IT"      -> department
    // 65000     -> monthly salary
    FullTimeEmployee f1(101, "Amit", "IT", 65000);


    // Create a PartTimeEmployee object named p1.
    //
    // 102       -> employee ID
    // "Sneha"   -> name
    // "HR"      -> department
    // 250       -> hourly rate
    // 120       -> hours worked
    PartTimeEmployee p1(102, "Sneha", "HR", 250, 120);


    // Create an Intern object named i1.
    //
    // 103          -> employee ID
    // "Rohan"      -> name
    // "Marketing"  -> department
    // 15000        -> stipend
    Intern i1(103, "Rohan", "Marketing", 15000);


    // Display the heading.
    cout << "=== Employee Payroll ===" << endl;


    // Display FullTimeEmployee details.
    f1.display();


    // Display PartTimeEmployee details.
    p1.display();


    // Display Intern details.
    i1.display();


    // Return 0 indicates successful program execution.
    return 0;
}