#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <unistd.h>
#include <stdlib.h>

using namespace std;

// Function prototypes
void login(string username, string password);
void adminMenu();
void staffMenu();
void displayInventory();
void addInventory();
void removeInventory();
void addEmployee();
void removeEmployee();
void updateSalary();
void updateBonus();
void takeOrder();
void viewSalesReport();
void placeOrder();
void exitProgram();

int main() {
    // Code for main function
    cout << "Welcome to the Inventory Management System!" << endl;
    cout << "Please login to continue." << endl;
    string username, password;
    cout << "Username: ";
    cin >> username;
    cout << "Password: ";
    cin >> password;
    system("cls");
    while (username != "admin" && username != "staff" && password != "admin" && password != "staff") {
        cout << "Invalid login. Please try again." << endl;
        cout << "Username: ";
        cin >> username;
        cout << "Password: ";
        cin >> password;
    }
    system("cls");
    while (true){
        login(username, password);
    }
    // login(username, password);
    return 0;
}

void login(string username, string password) {
    // Code for login screen and verification of credentials
    // If admin, call adminMenu() function
    // If staff, call staffMenu() function
    // If invalid login, display error message and prompt for login again
    if (username == "admin" && password == "admin") {
        adminMenu();
    } else if (username == "staff" && password == "staff") {
        staffMenu();
    } else {
        cout << "Invalid login. Please try again." << endl;
        cout << "Username: ";
        cin >> username;
        cout << "Password: ";
        cin >> password;
        login(username, password);
    }
}

void adminMenu() {
    // Code for admin menu
    // Options include managing inventory, managing staff, viewing sales report, and exiting program
    cout << "Welcome, admin!" << endl;
    cout << "Please select an option below." << endl;
    cout << endl;
    
    int choice;
    cout << "1. Manage inventory" << endl;
    cout << "2. Manage staff" << endl;
    cout << "3. View sales report" << endl;
    cout << "4. Exit program" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    if (choice == 1) {
        int choice;
        cout << "1. Display inventory" << endl;
        cout << "2. Add item to inventory" << endl;
        cout << "3. Remove item from inventory" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            displayInventory();
        } else if (choice == 2) {
            addInventory();
        } else if (choice == 3) {
            removeInventory();
        } else {
            cout << "Invalid choice. Please try again." << endl;
        }
    } else if (choice == 2) {
        int choice;
        cout << "1. Add employee" << endl;
        cout << "2. Remove employee" << endl;
        cout << "3. Update salary" << endl;
        cout << "4. Update bonus" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            addEmployee();
        } else if (choice == 2) {
            removeEmployee();
        } else if (choice == 3) {
            updateSalary();
        } else if (choice == 4) {
            updateBonus();
        } else {
            cout << "Invalid choice. Please try again." << endl;
        }
    } else if (choice == 3) {
        viewSalesReport();
    } else if (choice == 4) {
        exitProgram();
    } else {
        cout << "Invalid choice. Please try again." << endl;
    }

}

void staffMenu() {
    // Code for staff menu
    // Options include taking orders, viewing sales report, and exiting program
    cout << "Welcome, staff!" << endl;
    cout << "Please select an option below." << endl;
    cout << endl;

    int choice;
    cout << "1. Take order" << endl;
    cout << "2. View sales report" << endl;
    cout << "3. Exit program" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    if (choice == 1) {
        takeOrder();
    } else if (choice == 2) {
        viewSalesReport();
    } else if (choice == 3) {
        exitProgram();
    } else {
        cout << "Invalid choice. Please try again." << endl;
    }
}

void displayInventory() {
    // Code for displaying current inventory
    
    // Open inventory file
    ifstream inventoryFile;
    inventoryFile.open("inventory.txt");

    if (inventoryFile.is_open()) {
        // Read item name, quantity, and price from inventory file
        string name;
        int quantity;
        double price;
        while (inventoryFile >> name >> quantity >> price) {
            // Display item name, quantity, and price
            cout << name << " " << quantity << " " << price << endl;
            cout << "--------------------------------------------------" << endl;
        }
        cout << endl;
        cout << "Inventory displayed successfully!" << endl;
    } else {
        cout << "Error opening file." << endl;
    }
}

void addInventory() {
    // Code for adding new items to inventory
    string itemName;
    int itemQuantity;
    double itemPrice;

    // Prompt user for item name, quantity, and price
    cout << "Enter item name: ";
    cin >> itemName;
    cout << "Enter item quantity: ";
    cin >> itemQuantity;
    cout << "Enter item price: ";
    cin >> itemPrice;

    // Open inventory file
    ofstream inventoryFile;
    inventoryFile.open("inventory.txt", ios::app);

    if (inventoryFile.is_open()) {
        // Write item name, quantity, and price to inventory file
        inventoryFile << itemName << " " << itemQuantity << " " << itemPrice << endl;
        cout << "Item added successfully!" << endl;
    } else {
        cout << "Error opening file." << endl;
    }
}

void removeInventory() {
    // Code for removing items from inventory
    string itemName;
    cin >> itemName;

    // Open inventory file
    ifstream inventoryFile;
    inventoryFile.open("inventory.txt");

    // Create temporary file
    ofstream tempFile;
    tempFile.open("temp.txt");

    if (inventoryFile.is_open()) {
        // Read item name, quantity, and price from inventory file
        string name;
        int quantity;
        double price;
        while (inventoryFile >> name >> quantity >> price) {
            // If item name matches, do not write to temporary file
            if (name == itemName) {
                cout << "Item removed successfully!" << endl;
            } else {
                // Write item name, quantity, and price to temporary file
                tempFile << name << " " << quantity << " " << price << endl;
            }
        }
    } else {
        cout << "Error opening file." << endl;
    }

}

void addEmployee() {
    // Code for adding new employees
    string employeeName;
    double employeeSalary;
    double employeeBonus;

    // Prompt user for employee name, salary, and bonus
    cout << "Enter employee name: ";
    cin >> employeeName;
    cout << "Enter employee salary: ";
    cin >> employeeSalary;
    cout << "Enter employee bonus: ";
    cin >> employeeBonus;

    // Open employee file
    ofstream employeeFile;
    employeeFile.open("employee.txt", ios::app);

    if (employeeFile.is_open()) {
        // Write employee name, salary, and bonus to employee file
        employeeFile << employeeName << " " << employeeSalary << " " << employeeBonus << endl;
        cout << "Employee added successfully!" << endl;
    } else {
        cout << "Error opening file." << endl;
    }
  
}

void removeEmployee() {
    // Code for removing employees
    string employeeName;
    cout << "Enter employee name: ";
    cin >> employeeName;

    // Open employee file
    ifstream employeeFile;
    employeeFile.open("employee.txt");

    // Create temporary file
    ofstream tempFile;
    tempFile.open("temp.txt");

    if (employeeFile.is_open()) {
        // Read employee name, salary, and bonus from employee file
        string name;
        double salary;
        double bonus;
        while (employeeFile >> name >> salary >> bonus) {
            // If employee name matches, do not write to temporary file
            if (name == employeeName) {
                cout << "Employee removed successfully!" << endl;
            } else {
                // Write employee name, salary, and bonus to temporary file
                tempFile << name << " " << salary << " " << bonus << endl;
            }
        }
    } else {
        cout << "Error opening file." << endl;
    }
}

void updateSalary() {
    // Code for updating employee salary
    string employeeName;
    cout << "Enter employee name: ";
    cin >> employeeName;
    
    // Open employee file
    ifstream employeeFile;
    employeeFile.open("employee.txt");

    // Create temporary file
    ofstream tempFile;
    tempFile.open("temp.txt");

    if (employeeFile.is_open()) {
        // Read employee name, salary, and bonus from employee file
        string name;
        double salary;
        double bonus;
        while (employeeFile >> name >> salary >> bonus) {
            // If employee name matches, update salary
            if (name == employeeName) {
                cout << "Enter new salary: ";
                cin >> salary;
                cout << "Salary updated successfully!" << endl;
            }
            // Write employee name, salary, and bonus to temporary file
            tempFile << name << " " << salary << " " << bonus << endl;
        }
    } else {
        cout << "Error opening file." << endl;
    }
}

void updateBonus() {
    // Code for updating employee bonus
    string employeeName;
    cout << "Enter employee name: ";
    cin >> employeeName;

    // Open employee file
    ifstream employeeFile;
    employeeFile.open("employee.txt");

    // Create temporary file
    ofstream tempFile;
    tempFile.open("temp.txt");

    if (employeeFile.is_open()) {
        // Read employee name, salary, and bonus from employee file
        string name;
        double salary;
        double bonus;
        while (employeeFile >> name >> salary >> bonus) {
            // If employee name matches, update bonus
            if (name == employeeName) {
                cout << "Enter new bonus: ";
                cin >> bonus;
                cout << "Bonus updated successfully!" << endl;
            }
            // Write employee name, salary, and bonus to temporary file
            tempFile << name << " " << salary << " " << bonus << endl;
        }
    } else {
        cout << "Error opening file." << endl;
    }

}

void takeOrder() {
    // Code for taking customer orders

    // Open inventory file
    ifstream inventoryFile;
    inventoryFile.open("inventory.txt");

    // Create temporary file
    ofstream tempFile;
    tempFile.open("temp.txt");

    if (inventoryFile.is_open()) {
        // Read item name, quantity, and price from inventory file
        string name;
        int quantity;
        double price;
        while (inventoryFile >> name >> quantity >> price) {
            // Prompt user for item name and quantity
            string itemName;
            int itemQuantity;
            cout << "Enter item name: ";
            cin >> itemName;
            cout << "Enter item quantity: ";
            cin >> itemQuantity;

            // If item name matches, update quantity
            if (name == itemName) {
                quantity -= itemQuantity;
                cout << "Order placed successfully!" << endl;
            }
            // Write item name, quantity, and price to temporary file
            tempFile << name << " " << quantity << " " << price << endl;
        }
    } else {
        cout << "Error opening file." << endl;
    }
}

void viewSalesReport() {
    // Code for displaying sales report for specified date range
    string startDate;
    string endDate;
    cout << "Enter start date (MM/DD/YYYY): ";
    cin >> startDate;
    cout << "Enter end date (MM/DD/YYYY): ";
    cin >> endDate;

    // Open sales file
    ifstream salesFile;
    salesFile.open("sales.txt");

    if (salesFile.is_open()) {
        // Read date, item name, quantity, and price from sales file
        string date;
        string name;
        int quantity;
        double price;
        while (salesFile >> date >> name >> quantity >> price) {
            // If date is within specified range, display sales report
            if (date >= startDate && date <= endDate) {
                cout << date << " " << name << " " << quantity << " " << price << endl;
            }
        }
    } else {
        cout << "Error opening file." << endl;
    }

}

void placeOrder() {
    // Code for placing orders for more inventory
    string itemName;

    // Prompt user for item name
    cout << "Enter item name: ";
    cin >> itemName;

    // Open inventory file
    ifstream inventoryFile;
    inventoryFile.open("inventory.txt");

    // Create temporary file
    ofstream tempFile;
    tempFile.open("temp.txt");

    if (inventoryFile.is_open()) {
        // Read item name, quantity, and price from inventory file
        string name;
        int quantity;
        double price;
        while (inventoryFile >> name >> quantity >> price) {
            // If item name matches, update quantity
            if (name == itemName) {
                cout << "Enter new quantity: ";
                cin >> quantity;
                cout << "Order placed successfully!" << endl;
            }
            // Write item name, quantity, and price to temporary file
            tempFile << name << " " << quantity << " " << price << endl;
        }
    } else {
        cout << "Error opening file." << endl;
    }
}

void exitProgram() {
    // Code for exiting the program
    cout << "Thank you for using the Inventory Management System!" << endl;
    sleep(3);
    exit(0);
}
