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

// Teacher Section ///////////////////////////////////////////////////////////////////////////////
class teacher
{ // Class to add amd keep teacher data
public:
    long int id;
    char name[80], course[50];
    void input()
    {
        cout << "\n Enter Teacher Name: "; // input function
        gets(name);
        cout << "\n Enter Teacher ID Number: ";
        cin >> id;
        fflush(stdin);
        cout << "\n Enter Course: ";
        gets(course);
    }
    void display()
    {
        system("CLS"); // function to display teacher data
        cout << "\t\tDisplay Records";
        cout << "\n";
        cout << "\n Name - " << name;
        cout << "\n Teacher ID - " << id;
        cout << "\n Course - " << course;
        cout << "\n";
        system("PAUSE");
    }
    bool operator==(teacher a)
    {
        if (id == a.id)
            return true;
        else
            return false;
    }
};
vector<teacher> vt; // Vector to dynamically resize to allow for data storage
int search_t_id(long int id, int &i);
void get_file_t()
{
    teacher x;
    int i = 0;
    fstream f;
    // Name of the file in which DB is stored.
    f.open("teacherinfo.txt");
    if (f)
    {
        f.read((char *)&x, sizeof(class teacher));
        while (!f.eof())
        {
            vt.push_back(x);
            f.read((char *)&x, sizeof(class teacher));
        }
    }
    else
        ;
    f.close();
}
void bubblesort_t() // Bubble sort function for sorting vector data
{
    int i, j;
    teacher x;
    for (i = 0; i < vt.size(); i++)
        for (j = 0; j < vt.size() - i - 1; j++)
            if (vt[j].id > vt[j + 1].id)
            {
                x = vt[j];
                vt[j] = vt[j + 1];
                vt[j + 1] = x;
            }
}
void insert_new_t() // Function for inputting new user data
{
    int ta;
    fflush(stdin);
    teacher x;
    x.input();
    if (search_t_id(x.id, ta) == 0)
        vt.push_back(x);
    else
        cout << "\nThis teacher ID already exists,\nPlease enter another";
    fflush(stdin);
}
void write_file_t() // Function to store info in txt file
{
    bubblesort_t();
    fstream f;
    // Name of the file in which DB is stored.
    f.open("teacherinfo.txt");
    for (int i = 0; i < vt.size(); i++)
    {
        teacher x = vt[i];
        f.write((char *)&x, sizeof(class teacher));
    }
    f.close();
}
int search_t_id(long int id, int &i) // Formula used to search vector by ID
{
    int ta = 0;
    for (i = 0; i < vt.size(); i++)
        if (vt[i].id == id)
        {
            ta = 1;
            break;
        }
    return ta;
}
int search_name_t(char name[], vector<int> &vi) // Formula used to search vector by name
{
    int i, ta = 0;
    for (i = 0; i < vt.size(); i++)
        if (strcmp(vt[i].name, name) == 0)
        {
            ta = 1;
            vi.push_back(i);
        }
    return ta;
}
int search_course_t(char course[], vector<int> &vj) // Formula used to search vector by course
{
    int i, ta = 0;
    for (i = 0; i < vt.size(); i++)
        if (strcmp(vt[i].course, course) == 0)
        {
            ta = 1;
            vj.push_back(i);
        }
    return ta;
}
void search_and_show_t() // Function to find and show requested data
{
    int ch, i, ta = 0;
    char name[80], course[50];
    vector<int> vi;
    vector<int> vj;
    long int id;
poi:
    cout << "\n1.Search teacher ID. "
         << "\n2.Search teacher name. "
         << "\n3.Search Course. ";
    cin >> ch;
    switch (ch)
    {
    case 1:
        cout << "\nEnter teacher ID: ";
        cin >> id;
        if (search_t_id(id, i) == 1)
            vt[i].display();
        else
            cout << "\nTeacher ID not found";
        break;
    case 2:
        cout << "\nEnter teacher name: ";
        fflush(stdin);
        gets(name);
        if (search_name_t(name, vi) == 1)
        {
            for (int j = 0; j < vi.size(); j++)
                vt[vi[j]].display();
        }
        else
            cout << "\nTeacher name not found";
        break;
    case 3:
        cout << "\nEnter course: ";
        fflush(stdin);
        gets(course);
        if (search_course_t(course, vj) == 1)
        {
            for (int j = 0; j < vj.size(); j++)
                vt[vj[j]].display();
        }
        else
            cout << "\nCourse not found";
        break;
    default:
        cout << "\nHaha, Funny";
        goto poi;
    }
}
void show_t() // Function to view all teacher data
{
    int i;
    for (i = 0; i < vt.size(); i++)
        vt[i].display();
}
void delete_data_t() // Function to delete selected teacher data
{
    int i, j;
    long int id;
    vector<teacher>::iterator p = vt.begin();
    cout << "\nEnter teacher ID: ";
    cin >> id;
    if (search_t_id(id, i) == 1)
    {
        teacher x = vt[i];
        cout << "\nThe following data will be deleted";
        x.display();
        p += i;
        vt.erase(p, p + 1);
    }
}
void edit_data_t() // Function to edit selected teacher data
{
    int i, j;
    long int id;
    vector<teacher> vi;
    cout << "\nEnter teacher ID: ";
    cin >> id;
    if (search_t_id(id, i) == 1)
    {
        cout << "\nEnter new data:";
        fflush(stdin);
        vt[i].input();
    }
}
// Course Section ///////////////////////////////////////////////////////////////////////////////

class course_c // Class to add amd keep teacher data
{
public:
    long int id;
    char name[80], course[50];
    void input() // Input function
    {
        cout << "\n Enter Course Name: ";
        gets(name);
        cout << "\n Enter Course ID Number: ";
        cin >> id;
        fflush(stdin);
        cout << "\n Enter Course Level: ";
        gets(course);
    }
    void display() // function to display course data
    {
        system("CLS");
        cout << "\t\tDisplay Records";
        cout << "\n";
        cout << "\n Name - " << name;
        cout << "\n Course ID - " << id;
        cout << "\n Course Level - " << course;
        cout << "\n";
        system("PAUSE");
    }
    bool operator==(course_c a)
    {
        if (id == a.id)
            return true;
        else
            return false;
    }
};
vector<course_c> vc; // Vector to dynamically resize to allow for data storage
int search_c_id(long int id, int &i);
void get_file_c()
{
    course_c x;
    int i = 0;
    fstream f;
    // Name of the file in which DB is stored.
    f.open("courseinfo.txt");
    if (f)
    {
        f.read((char *)&x, sizeof(class course_c));
        while (!f.eof())
        {
            vc.push_back(x);
            f.read((char *)&x, sizeof(class course_c));
        }
    }
    else
        ;
    f.close();
}
void bubblesort_c() // Bubble sort function for sorting vector data
{
    int i, j;
    course_c x;
    for (i = 0; i < vc.size(); i++)
        for (j = 0; j < vc.size() - i - 1; j++)
            if (vc[j].id > vc[j + 1].id)
            {
                x = vc[j];
                vc[j] = vc[j + 1];
                vc[j + 1] = x;
            }
}
void insert_new_c() // Function for inputting new user data
{
    int ta;
    fflush(stdin);
    course_c x;
    x.input();
    if (search_c_id(x.id, ta) == 0)
        vc.push_back(x);
    else
        cout << "\nThis course already exists,\nPlease enter another";
    fflush(stdin);
}
void write_file_c() // Function to store info in txt file
{
    bubblesort_c();
    fstream f;
    // Name of the file in which DB is stored.
    f.open("courseinfo.txt");
    for (int i = 0; i < vc.size(); i++)
    {
        course_c x = vc[i];
        f.write((char *)&x, sizeof(class course_c));
    }
    f.close();
}
int search_c_id(long int id, int &i) // Formula used to search vector by ID
{
    int ta = 0;
    for (i = 0; i < vc.size(); i++)
        if (vc[i].id == id)
        {
            ta = 1;
            break;
        }
    return ta;
}
int search_name_c(char name[], vector<int> &vi) // Formula used to search vector by name
{
    int i, ta = 0;
    for (i = 0; i < vc.size(); i++)
        if (strcmp(vc[i].name, name) == 0)
        {
            ta = 1;
            vi.push_back(i);
        }
    return ta;
}
int search_course_c(char course[], vector<int> &vj) // Formula used to search vector by course
{
    int i, ta = 0;
    for (i = 0; i < vc.size(); i++)
        if (strcmp(vc[i].course, course) == 0)
        {
            ta = 1;
            vj.push_back(i);
        }
    return ta;
}
void search_and_show_c() // Function to find and show requested data
{
    int ch, i, ta = 0;
    char name[80], course[50];
    vector<int> vi;
    vector<int> vj;
    long int id;
poi:
    cout << "\n1.Search teacher name. "
         << "\n2.Search Course. ";
    cin >> ch;
    switch (ch)
    {
    case 1:
        cout << "\nEnter Course name: ";
        fflush(stdin);
        gets(name);
        if (search_name_c(name, vi) == 1)
        {
            for (int j = 0; j < vi.size(); j++)
                vc[vi[j]].display();
        }
        else
            cout << "\nCourse name not found";
        break;
    case 3:
        cout << "\nEnter course: ";
        fflush(stdin);
        gets(course);
        if (search_course_c(course, vj) == 1)
        {
            for (int j = 0; j < vj.size(); j++)
                vc[vj[j]].display();
        }
        else
            cout << "\nCourse not found";
        break;
    default:
        cout << "\nHaha, Funny";
        goto poi;
    }
}
void show_c() // Function to show all courses
{
    int i;
    for (i = 0; i < vc.size(); i++)
        vc[i].display();
}
void delete_data_c() // Function to edit selected course data
{
    int i, j;
    long int id;
    vector<course_c>::iterator p = vc.begin();
    cout << "\nEnter course ID: ";
    cin >> id;
    if (search_c_id(id, i) == 1)
    {
        course_c x = vc[i];
        cout << "\nThe following data will be deleted";
        x.display();
        p += i;
        vc.erase(p, p + 1);
    }
}
void edit_data_c() // Function to edit selected course data
{
    int i, j;
    long int id;
    vector<course_c> vi;
    cout << "\nEnter course ID: ";
    cin >> id;
    if (search_c_id(id, i) == 1)
    {
        cout << "\nEnter new data:";
        fflush(stdin);
        vc[i].input();
    }
}
// Student Section ///////////////////////////////////////////////////////////////////////////////

class student // Class to add and keep student data
{
public:
    long int id;
    char name[80], course[50];
    void input() // Input function
    {
        cout << "\n Enter Student Name: ";
        gets(name);
        cout << "\n Enter Student ID Number: ";
        cin >> id;
        fflush(stdin);
        cout << "\n Enter The Current Course: ";
        gets(course);
    }
    void display() // function to display student data
    {
        system("CLS");
        cout << "\t\tDisplay Records";
        cout << "\n";
        cout << "\n Name - " << name;
        cout << "\n Student ID - " << id;
        cout << "\n Course - " << course;
        cout << "\n";
        system("PAUSE");
    }
    bool operator==(student a)
    {
        if (id == a.id)
            return true;
        else
            return false;
    }
};
vector<student> v; // vector to store student data
int search_id(long int id, int &i);
void get_file()
{
    student x;
    int i = 0;
    fstream f;
    // Name of the file in which DB is stored.
    f.open("studentinfo.txt");
    if (f)
    {
        f.read((char *)&x, sizeof(class student));
        while (!f.eof())
        {
            v.push_back(x);
            f.read((char *)&x, sizeof(class student));
        }
    }
    else
        ;
    f.close();
}
void bubblesort() // Bubble sort function for sorting vector data
{
    int i, j;
    student x;
    for (i = 0; i < v.size(); i++)
        for (j = 0; j < v.size() - i - 1; j++)
            if (v[j].id > v[j + 1].id)
            {
                x = v[j];
                v[j] = v[j + 1];
                v[j + 1] = x;
            }
}
void insert_new() // Function for inputting new user data
{
    int ta;
    fflush(stdin);
    student x;
    x.input();
    if (search_id(x.id, ta) == 0)
        v.push_back(x);
    else
        cout << "\nThis student ID already exists,\nPlease enter another";
    fflush(stdin);
}
void write_file() // Function to store info in txt file
{
    bubblesort();
    fstream f;
    // Name of the file in which DB is stored.
    f.open("studentinfo.txt");
    for (int i = 0; i < v.size(); i++)
    {
        student x = v[i];
        f.write((char *)&x, sizeof(class student));
    }
    f.close();
}
int search_id(long int id, int &i) // Formula used to search vector by ID
{
    int ta = 0;
    for (i = 0; i < v.size(); i++)
        if (v[i].id == id)
        {
            ta = 1;
            break;
        }
    return ta;
}
int search_name(char name[], vector<int> &vi) // Formula used to search vector by name
{
    int i, ta = 0;
    for (i = 0; i < v.size(); i++)
        if (strcmp(v[i].name, name) == 0)
        {
            ta = 1;
            vi.push_back(i);
        }
    return ta;
}
int search_course(char course[], vector<int> &vj) // Formula used to search vector by course
{
    int i, ta = 0;
    for (i = 0; i < v.size(); i++)
        if (strcmp(v[i].course, course) == 0)
        {
            ta = 1;
            vj.push_back(i);
        }
    return ta;
}
void search_and_show() // Function to find and show requested data
{
    int ch, i, ta = 0;
    char name[80], course[50];
    vector<int> vi;
    vector<int> vj;
    long int id;
poi:
    cout << "\n1.Search student ID. "
         << "\n2.Search student name. "
         << "\n3.Search Course. ";
    cin >> ch;
    switch (ch)
    {
    case 1:
        cout << "\nEnter student ID: ";
        cin >> id;
        if (search_id(id, i) == 1)
            v[i].display();
        else
            cout << "\nStudent ID not found";
        break;
    case 2:
        cout << "\nEnter student name: ";
        fflush(stdin);
        gets(name);
        if (search_name(name, vi) == 1)
        {
            for (int j = 0; j < vi.size(); j++)
                v[vi[j]].display();
        }
        else
            cout << "\nStudent name not found";
        break;
    case 3:
        cout << "\nEnter course: ";
        fflush(stdin);
        gets(course);
        if (search_course(course, vj) == 1)
        {
            for (int j = 0; j < vj.size(); j++)
                v[vj[j]].display();
        }
        else
            cout << "\nCourse not found";
        break;
    default:
        cout << "\nHaha, Funny";
        goto poi;
    }
}
void show() // Function to view all student data
{
    int i;
    for (i = 0; i < v.size(); i++)
        v[i].display();
}
void delete_data() // Function to delete selected student data
{
    int i, j;
    long int id;
    vector<student>::iterator p = v.begin();
    cout << "\nEnter student ID: ";
    cin >> id;
    if (search_id(id, i) == 1)
    {
        student x = v[i];
        cout << "\nThe following data will be deleted";
        x.display();
        p += i;
        v.erase(p, p + 1);
    }
}
void edit_data() // Function to edit selected student data
{
    int i, j;
    long int id;
    vector<student> vi;
    cout << "\nEnter student ID: ";
    cin >> id;
    if (search_id(id, i) == 1)
    {
        cout << "\nEnter new data:";
        fflush(stdin);
        v[i].input();
    }
}

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
