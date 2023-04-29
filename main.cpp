#include <iostream>

using namespace std;

/*
1. admin 
2. staff
3. login 
4. salaries/ employees data
5. add remove employees
6. update inventory
*/

void admin()
{
    cout << "admin" << endl;
}

void staff()
{
    cout << "staff" << endl;
}

int adminLogin()
{
    cout << "login" << endl;
    int id;
    cout << "Enter your id: ";
    cin >> id;
    if(id == 123)
    {
        cout << "Login successful!" << endl;
        return 1;
    }
    else
    {
        cout << "Login failed!" << endl;
        return 0;
    }
}

int staffLogin()
{
    cout << "login" << endl;
    int id;
    cout << "Enter your id: ";
    cin >> id;
    if(id == 456)
    {
        cout << "Login successful!" << endl;
        return 1;
    }
    else
    {
        cout << "Login failed!" << endl;
        return 0;
    }
}

void salaries()
{
    cout << "1. view salaries" << endl;
    cout << "2. update salaries" << endl;
}

void add_remove_employees()
{
    cout << "add_remove_employees" << endl;
}

void update_inventory()
{
    cout << "1. check inventory" << endl;
    cout << "2. update inventory" << endl;
    cout << "3. add new item" << endl;
}

int main()
{
    cout << "Cafe Management System!" << endl;
    cout << "1. admin" << endl;
    cout << "2. staff" << endl;
    // cout << "3. login" << endl;
    // cout << "3 salaries/ employees data" << endl;
    // cout << "4. add remove employees" << endl;
    int choice, login_status;
    cout << "Enter your choice: ";
    cin >> choice;
    
    switch(choice)
    {
        case 1:
            login_status = adminLogin();
            if(login_status == 0)
            {
                cout << "Login failed!" << endl;
                break;
            }
            else if(login_status == 1)
            {
                admin();
            }
            login_status = 0;
            break;
        case 2:
            login_status = staffLogin();
            if(login_status == 0)
            {
                cout << "Login failed!" << endl;
                break;
            }
            else if(login_status == 1)
            {
                staff();
            }
            login_status = 0;
            break;
        // case 3:
        //     login();
        //     break;
        // case 3:
        //     salaries();
        //     break;
        // case 4:
        //     add_remove_employees();
        //     break;
        default:
            cout << "Invalid choice!" << endl;
    }
    return 0;
    
}

