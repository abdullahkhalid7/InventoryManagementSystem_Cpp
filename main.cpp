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

int login()
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

void salaries()
{
    cout << "salaries" << endl;
}

void add_remove_employees()
{
    cout << "add_remove_employees" << endl;
}

void update_inventory()
{
    cout << "update_inventory" << endl;
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
            login_status = login();
            if(login_status == 0)
            {
                cout << "Login failed!" << endl;
                break;
            }
            else if(login_status == 1)
            {
                admin();
            }
            break;
        case 2:
            login_status = login();
            if(login_status == 0)
            {
                cout << "Login failed!" << endl;
                break;
            }
            else if(login_status == 1)
            {
                staff();
            }
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

