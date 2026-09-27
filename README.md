# C++ Programming Project/Coding – Unit II

## Student Details

- Student Name: Namrata Nimhan
- ZPRN: 125UAD1192
- Class/Division: S.Y/E
- Course Name: Artificial Intelligence & Data Science 
- Unit: Unit II

## Programs Included

### Program 01 – Employee Payroll System

This program implements an employee payroll system using an abstract base class and derived employee classes. 
It handles different employee types such as full-time employees, part-time employees, and interns, with separate salary calculations. 
The program uses inheritance and method overriding to implement employee-specific behavior. 
Runtime polymorphism is achieved through the virtual calculateSalary() function.

Files:
- program_01.cpp
- output.png

### Program 02 – Digital Payment Gateway

This program implements a digital payment gateway that supports multiple payment methods, including Credit Card, UPI, and Net Banking. 
A common abstract PaymentMethod class defines the basic payment structure, while derived classes implement the respective processing methods.
The program demonstrates inheritance, abstraction, and runtime polymorphism. unique_ptr and vector are used to manage the payment objects dynamically.

Files:
- program_02.cpp
- output_02.png

### Program 03 – Vehicle Fleet Management

This program implements a vehicle fleet management system for handling different types of vehicles such as trucks, delivery vans, and bikes. 
A common Vehicle base class provides shared properties and operations, while derived classes provide vehicle-specific information. 
Virtual functions are used to achieve runtime polymorphism when displaying fleet details.
The program also uses unique_ptr and vector for managing the collection of vehicles.

Files:
- program_03.cpp
- output_03.png

## Repository Structure

```text
oops-unit2/
│
├── README.md
├── .gitignore
│
├── Program_01/
│   ├── program_01.cpp
│   └── output.png
│
├── Program_02/
│   ├── program_02.cpp
│   └── output_02.png
│
└── Program_03/
    ├── program_03.cpp
    └── output_03.png
```

## Description

This repository contains the C++ programming programs completed as part of the Unit II programming activity. 
Each program demonstrates the application of object-oriented programming concepts to a real-time problem scenario.
The programs are organized separately along with their corresponding output screenshots for easy reference.
