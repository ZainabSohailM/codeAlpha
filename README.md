# Code Alpha Internship Tasks
## CGPA Calculator Deatils

This is a simple console-based GPA (Grade Point Average) and CGPA (Cumulative Grade Point Average) calculator implemented in C++. The program allows users to input their grades, credit hours, and number of courses for multiple semesters, and calculates both the GPA for each semester and the overall CGPA.

**Features**

**• Grade to Grade Point Conversion:** Converts letter grades (e.g., A+, B-, C) into grade points based on a 4.0 scale.

**• Semester-wise GPA Calculation:** Computes the GPA for each semester based on the input grades and credit hours for the courses.

**• Cumulative CGPA Calculation:** Computes the CGPA across all semesters entered.

**• Dynamic Input Handling:** Allows the user to input the number of semesters and the number of courses for each semester.

**Notes**

**• Grade Input:** The program expects grades in the format provided (e.g., A, B+, C-). Any other input will be treated as 0.0 grade points.

**• Credit Hours:** Ensure that the number of credit hours entered for each course is a positive integer.

**Notes**

**• Grade Input:** The program expects grades in the format provided (e.g., A, B+, C-). Any other input will be treated as 0.0 grade points.

**• Credit Hours:** Ensure that the number of credit hours entered for each course is a positive integer.
## Login and Registration System

This C++ project is a basic implementation of a user authentication system. It covers fundamental concepts of user registration, login functionality, and password security.

**Features**

**• Password Hashing:** Passwords are hashed using a simple hexadecimal representation to enhance security.

**• Password Validation:** Ensures passwords meet security criteria including length, uppercase letters, lowercase letters, digits, and special characters.

**• User Management:** Allows users to register new accounts and login with existing credentials.

**Code Explanation**

**• hashPassword:** Converts the input password into a hexadecimal string for storage.

**• checkPassword:** Validates the strength of the password based on predefined criteria.

**• registerUser:** Checks if the username already exists and registers the new user if not.

**• loginUser:** Verifies the provided password against the stored hashed password.

## Banking System

This project implements a basic banking system using C++. It provides functionalities to manage customers, accounts, and transactions. This simple banking system allows for account creation, deposits, withdrawals, transfers, and viewing transaction histories.

**Features**

**• Customer Management:** Create and manage customers.

**• Account Management:** Create accounts, deposit and withdraw funds, and transfer money between accounts.

**• Transaction History:** Keep track of recent transactions for each account.

**Classes**

**• Transaction:** Represents a financial transaction (deposit, withdrawal, transfer) with details and amount.

**• Account:** Represents a bank account with methods for deposit, withdrawal, transfer, and viewing transaction history.

**• Customer:** Represents a customer with multiple accounts and methods to view account information.

**• BankingService:** Manages customers and accounts, providing methods for creating accounts, depositing, withdrawing, transferring, and retrieving account information.

**Usage**

*To use this banking system:*

**• Compile the Code:** Use a C++ compiler to build the project.

**• Run the Application:** Execute the compiled program to interact with the banking system through a menu-driven interface.

**• Follow the Menu:** The menu will guide you through creating customers, managing accounts, and performing transactions.

**Notes**

• The application uses std::unique_ptr for automatic memory management and to avoid memory leaks.

• Ensure that inputs are valid to avoid runtime errors.

• The code assumes a command-line interface for user interaction.
## Contributing

Feel free to open issues or submit pull requests if you find any bugs or have suggestions for improvements. All contributions are welcome!
