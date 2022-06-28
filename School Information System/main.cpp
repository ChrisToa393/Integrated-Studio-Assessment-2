#include <stdio.h>
#include <iostream>
#include <string.h>
#include <time.h>
#include <string>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;


// Other Section ///////////////////////////////////////////////////////////////////////////////

bool is_logged_in() // A for loop to check login status and limit attempts to 3
{
    string username, password, un, pw;
    for (int attempts = 1; attempts <= 3; ++attempts)
    {
        cout << "Enter username: ";
        cin >> username;
        cout << "Enter password: ";
        cin >> password;

        ifstream read("user" + username + ".txt");
        getline(read, un);
        getline(read, pw);

        if (un == username && pw == password)
        {
            return true;
            cout << "Access Granted\n";
        }
        else
        {
            cout << "Access Denied,\nTry Again\n";
        }
    }
    cout << "You are a sus imposter, \nGoodbye\n";
    exit(0);
}
void reg_usr() // Function to register a new user and store data into txt file
{
    string username, password;
    cout << "Select a username: ";
    cin >> username;
    cout << "Select a password: ";
    cin >> password;

    ofstream file;
    file.open("user" + username + ".txt");
    file << username << endl
         << password;
    file.close();

    cout << "\n\nNew user succesfully added\n\n";
}
void login() // Fuction to log a user in
{
    bool status = is_logged_in();
    if (!status)
    {
        cout << "Username and password not found, please try again" << endl;
        system("pause");
    }
    else
    {
        cout << "\nSuccesfully logged in\n\n";
    };
}

void login_menu() // Function to display the login menu
{

    system("CLS");
    cout << "\t\t\t-----------------------------------------\n";
    cout << "\t\t\t      School Information System\n";
    cout << "\t\t\t-----------------------------------------\n";
    cout << "\n\t\t\tEnter <1> to Register new user"
         << "\n\t\t\tEnter <2> to Admin login"
         << "\n\t\t\tEnter <3> to Student/Parent Login"
         << "\n\t\t\tEnter <4> to Exit\n";
}
void student_parent_menu() // Function to display the student/parent menu
{
    bool loop = true;
    int choice;
    while (loop == true)
    {
        system("CLS");
        cout << "\t\t\t-----------------------------------------\n";
        cout << "\t\t\t      School Information System Student Menu\n";
        cout << "\t\t\t-----------------------------------------\n";
        cout << "\n\t\t\tEnter <1> to View report"
             << "\n\t\t\tEnter <2> to Print report"
             << "\n\t\t\tEnter <3> to Contact Admin"
             << "\n\t\t\tEnter <4> to Exit\n";

        switch (choice)
        {
        case 1:
            insert_new_t();
            break;
        case 2:
            show_t();
            break;
        case 3:
            delete_data_t();
            break;
        case 4:
            exit(0);
            break;
        default:
            cout << "\nPlease try again lol";
        }
    }
}

void teacher_manage() // Function to display the teacher management admin menu
{
    bool loop = true;
    int choice;
    while (loop == true)
    {
        system("CLS");
        cout << "\t\t\t-----------------------------------------\n";
        cout << "\t\t\t     Teacher Management\n";
        cout << "\t\t\t-----------------------------------------\n";
        cout << "\n\t\t\tEnter <1> to Add Teacher"
             << "\n\t\t\tEnter <2> to View Teacher"
             << "\n\t\t\tEnter <3> to Delete Data"
             << "\n\t\t\tEnter <4> to Edit Data"
             << "\n\t\t\tEnter <5> to Search Teacher"
             << "\n\t\t\tEnter <6> to Exit\n";
        cout << "\n\n\t\t\tEnter Your Choice:";
        cin >> choice;

        switch (choice)
        {
        case 1:
            insert_new_t();
            break;
        case 2:
            show_t();
            break;
        case 3:
            delete_data_t();
            break;
        case 4:
            edit_data_t();
            break;
        case 5:
            search_and_show_t();
            break;
        case 6:
            exit(0);
            break;
        default:
            cout << "\nPlease try again lol";
        }
    }
}

void course_manage() // Function to display the course management admin menu
{
    bool loop = true;
    int choice;
    while (loop == true)
    {
        system("CLS");
        cout << "\t\t\t-----------------------------------------\n";
        cout << "\t\t\t     Course Management\n";
        cout << "\t\t\t-----------------------------------------\n";
        cout << "\n\t\t\tEnter <1> to Add Course"
             << "\n\t\t\tEnter <2> to View Course"
             << "\n\t\t\tEnter <3> to Delete Data"
             << "\n\t\t\tEnter <4> to Edit Data"
             << "\n\t\t\tEnter <5> to Search Course"
             << "\n\t\t\tEnter <6> to Exit\n";
        cout << "\n\n\t\t\tEnter Your Choice:";
        cin >> choice;

        switch (choice)
        {
        case 1:
            insert_new_c();
            break;
        case 2:
            show_c();
            break;
        case 3:
            delete_data_c();
            break;
        case 4:
            edit_data_c();
            break;
        case 5:
            search_and_show_c();
            break;
        case 6:
            exit(0);
            break;
        default:
            cout << "\nPlease try again lol";
        }
    }
}

void student_manage() // Function to display the student management admin menu
{
    bool loop = true;
    int choice;
    while (loop == true)
    {
        system("CLS");
        cout << "\t\t\t-----------------------------------------\n";
        cout << "\t\t\t     Student Management\n";
        cout << "\t\t\t-----------------------------------------\n";
        cout << "\n\t\t\tEnter <1> to Add Students"
             << "\n\t\t\tEnter <2> to View Students"
             << "\n\t\t\tEnter <3> to Delete Data"
             << "\n\t\t\tEnter <4> to Edit Data"
             << "\n\t\t\tEnter <5> to Search Students"
             << "\n\t\t\tEnter <6> to Exit\n";
        cout << "\n\n\t\t\tEnter Your Choice:";
        cin >> choice;

        switch (choice)
        {
        case 1:
            insert_new();
            break;
        case 2:
            show();
            break;
        case 3:
            delete_data();
            break;
        case 4:
            edit_data();
            break;
        case 5:
            search_and_show();
            break;
        case 6:
            exit(0);
            break;
        default:
            cout << "\nPlease try again lol";
        }
    }
}

void admin_menu() // Function to display the admin menu
{
    int choice;
    system("CLS");
    cout << "\t\t\t-----------------------------------------\n";
    cout << "\t\t\t\t\t     Admin Menu\n";
    cout << "\t\t\t-----------------------------------------\n";
    cout << "\n\t\t\tEnter <1> to Manage Students"
         << "\n\t\t\tEnter <2> to Manage Teachers"
         << "\n\t\t\tEnter <3> to Manage Course"
         << "\n\t\t\tEnter <4> to Manage Reports"
         << "\n\t\t\tEnter <5> to Exit\n";
    cout << "\n\n\t\t\tEnter Your Choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        student_manage();
        break;
    case 2:
        teacher_manage();
        break;
    case 3:
        course_manage();
        break;
    case 4:
        student_manage();
        break;
    case 5:
        exit(0);
        break;
    default:
        cout << "\nPlease try again lol";
    }
}

int main()
{
    bool loop = true;
    while (loop == true)
    {
        login_menu(); // Initiate program
        int choice;
        cout << "\n\n\t\t\tEnter Your Choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            reg_usr();
            system("pause");
            break;
        case 2:
            login();
            system("pause");
            admin_menu();
            break;
        case 3:
            login();
            system("pause");

            break;
        case 4:
            exit(0);
            break;
        default:
            cout << "\nPlease try again lol";
        }
    }
    return 0;
}