#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
#include<conio.h>              // su dung getch()
#include<stdlib.h>             // su dung exit()
#include<windows.h>
#include<algorithm>
#include"interface.h"
#include"support_function.h"
const int MAX = 10000;
using namespace std;

const char separator = ' ';
const int idWidth = 6;
const int nameWidth = 30;
const int emailWidth = 30;
const int phoneWidth = 15;
const int billWidth =  20;
const int serviceWidth = 25;
const int addressWidth = 30;
// dinh nghia thong tin khach hang
class Users {
    public:
        string id;
        string name;
        string email;
        string phone;
        string bill;
        string service;
        string address;
};

Users user[MAX];   
int numOfUsers;

// ham chinh
void showMenu(void);               //menu chinh cua chuong trinh
void addData(void);                //menu cua chuc nang them du lieu
void removeData(void);             //menu cua chuc nang xoa du lieu
void modifyData(void);             //menu cua chuc nang chinh sua du lieu
void searchData(void);             //menu cua chuc nang tim kiem du lieu
void sortData(void);               //menu cua chuc nang sap xep du lieu
void viewData(void);               //menu cua chuc nang xem du lieu
void advance(void);                //menu cua chuc nang nang cao

// ham phu tro
void readFile(void);               //doc file
void updateFile(void);             //cap nhap du lieu file

// ham con
void addData_1(void);
void removeData_1(void);
void removeData_2(void);
void modifyData_1(void);
void modifyData_2(void);
void searchData_1(void);
void searchData_2(void);
void searchData_3(void);
void searchData_4(void);
void searchData_5(void);
void searchData_6(void);
void searchData_7(void);
void sortData_1(void);
void sortData_1_1(void);
void sortData_1_2(void);
void sortData_2(void);
void sortData_2_1(void);
void sortData_2_2(void);
void sortData_3(void);
void sortData_3_1(void);
void sortData_3_2(void);
void sortData_4(void);
void sortData_4_1(void);
void sortData_4_2(void);
void sortData_5(void);
void sortData_5_1(void);
void sortData_5_2(void);
void sortData_6(void);
void sortData_6_1(void);
void sortData_6_2(void);
void sortData_7(void);
void sortData_7_1(void);
void sortData_7_2(void);
void advance_1(void);
void advance_2(void);

int main(){
    system("Color 9F");
    mainPage();
    loadingBar();
    logScreen();
    showMenu();
    return 0;
}

void readFile()
{
    ifstream fin;
    fin.open("data.txt");
    numOfUsers = 0;
    string tmp;
    while(!fin.eof())
    {
        getline(fin,tmp);
        if(tmp[0]=='\0') break;
        user[numOfUsers].id = "";
        for(int i=0; i<idWidth;i++) user[numOfUsers].id += tmp[i];
        user[numOfUsers].id = delete_space(user[numOfUsers].id);
        
        user[numOfUsers].name = "";
        for(int i=6; i<6+nameWidth;i++) user[numOfUsers].name += tmp[i];
        user[numOfUsers].name = delete_space(user[numOfUsers].name);
        
        user[numOfUsers].email = "";
        for(int i=36; i<36+emailWidth;i++) user[numOfUsers].email += tmp[i];
        user[numOfUsers].email = delete_space(user[numOfUsers].email);
        
        user[numOfUsers].phone = "";
        for(int i=66; i<66+phoneWidth;i++) user[numOfUsers].phone += tmp[i];
        user[numOfUsers].phone = delete_space(user[numOfUsers].phone);
        
        user[numOfUsers].bill = "";
        for(int i=81; i<81+billWidth;i++) user[numOfUsers].bill += tmp[i];;
        user[numOfUsers].bill = delete_space(user[numOfUsers].bill);
        
        user[numOfUsers].service = "";
        for(int i=101; i<101+serviceWidth;i++) user[numOfUsers].service += tmp[i];
        user[numOfUsers].service = delete_space(user[numOfUsers].service);
        
        user[numOfUsers].address = "";
        for(int i=126; i<tmp.size();i++) user[numOfUsers].address += tmp[i];
        user[numOfUsers].address = delete_space(user[numOfUsers].address);
        
        numOfUsers++;
    }
    fin.close();
}

void updateFile()
{
    ofstream fout;
    fout.open("data.txt");
    for(int i=0;i<numOfUsers;i++)
    {
        fout << left << setw(idWidth) << setfill(separator) << user[i].id;
        fout << left << setw(nameWidth) << setfill(separator) << user[i].name;
        fout << left << setw(emailWidth) << setfill(separator) << user[i].email;
        fout << left << setw(phoneWidth) << setfill(separator) << user[i].phone;
        fout << left << setw(billWidth) << setfill(separator) << user[i].bill;
        fout << left << setw(serviceWidth) << setfill(separator) << user[i].service;
        fout << left << setw(addressWidth) << setfill(separator) << user[i].address;
        fout << endl;
    }
    fout.close();
}

// Menu

void showMenu()
{
    system("cls");
    cout << "----------------------MENU----------------------" << endl;
    cout << "                   1.Add data                   " << endl;
    cout << "                   2.Remove data                " << endl;
    cout << "                   3.Modify data                " << endl;
    cout << "                   4.Search data                " << endl;
    cout << "                   5.Sort data                  " << endl;
    cout << "                   6.View data                  " << endl;
    cout << "                   7.Advance                    " << endl;
    cout << "                   0.Exit                       " << endl;
    cout << "------------------------------------------------" << endl;
    cout << "Enter your choice: ";
    int user_input;
    cin >> user_input;
    switch (user_input)
    {
    case 1:
        system("cls");
        addData();
        break;
    case 2:
        system("cls");
        removeData();
        break;
    case 3:
        system("cls");
        modifyData();
        break;
    case 4:
        system("cls");
        searchData();
        break;
    case 5:
        system("cls");
        sortData();
        break;
    case 6:
        system("cls");
        viewData();
        break;
    case 7:
        system("cls");
        advance();
        break;
    case 0:
        exitProgram();
        break;
    default:
        cout << "input invalid!!!";
        pressAnyKey();
        showMenu();
        break;
    }
    system("pause");
}

void addData()
{
    system("cls");
    cout << "Add Data\n";
    cout << "1.Fill in data\n";
    cout << "2.Return Menu\n";
    cout << "Enter your choice: ";
    int user_input;
    cin >> user_input;
    cin.ignore();
    switch (user_input)
    {
    case 1:
        system("cls");
        addData_1();
        break;
    case 2:
        showMenu();
        break;
    default:
        cout << "input invalid!!!";
        pressAnyKey();
        addData();
        break;
    }
    system("pause");
}

void addData_1()
{
    system("cls");
    readFile();
    user[numOfUsers].id = to_string(numOfUsers);
    cout << "Enter name: ";
    string input_name; getline(cin,input_name);
    user[numOfUsers].name = input_name;
    cout << "Enter email: ";
    string input_email; getline(cin,input_email);
    user[numOfUsers].email = input_email;
    cout << "Enter phone: ";
    string input_phone; getline(cin,input_phone);
    user[numOfUsers].phone = input_phone;
    cout << "Enter bill: ";
    string input_bill; getline(cin,input_bill);
    user[numOfUsers].bill = input_bill;
    cout << "Enter service: ";
    string input_service; getline(cin,input_service);
    user[numOfUsers].service = input_service;
    cout << "Enter address: ";
    string input_address; getline(cin,input_address);
    user[numOfUsers].address = input_address;
    numOfUsers++;
    updateFile();
    cout << "Data is updated successfully!\n";
    cout << "Do you want to continue to add data? (Y/N): ";
    char c; cin >> c;
    cin.ignore();
    switch (c)
    {
    case 'Y':
        addData_1();
        break;
    case 'y':
        addData_1();
        break;
    default:
        showMenu();
        break;
    }
}

void removeData()
{
    system("cls");
    cout << "Remove Data\n";
    cout << "1.Remove a user's data\n";
    cout << "2.Remove data of multiple users\n";
    cout << "3.Return Menu\n";
    cout << "Enter your choice: ";
    int user_input;
    cin >> user_input;
    switch (user_input)
    {
    case 1:
        system("cls");
        removeData_1();
        break;
    case 2:
        system("cls");
        removeData_2();
        break;
    case 3:
        showMenu();
        break;
    default:
        cout << "input invalid!!!";
        pressAnyKey();
        removeData();
        break;
    }
    system("pause");
}

void removeData_1()
{
    system("cls");
    readFile();
    cout << "Select the user's id you want to remove: ";
    int input_id; cin >> input_id;
    ofstream fout;
    fout.open("data.txt");
    fout << left << setw(idWidth) << setfill(separator) << user[0].id;
    fout << left << setw(nameWidth) << setfill(separator) << user[0].name;
    fout << left << setw(emailWidth) << setfill(separator) << user[0].email;
    fout << left << setw(phoneWidth) << setfill(separator) << user[0].phone;
    fout << left << setw(billWidth) << setfill(separator) << user[0].bill;
    fout << left << setw(serviceWidth) << setfill(separator) << user[0].service;
    fout << left << setw(addressWidth) << setfill(separator) << user[0].address;
    fout << endl;
    int id;
    for(int i=1;i<numOfUsers;i++)
    {
        if(i>=input_id) id = i-1;
        else id = i;
        if(i==input_id) continue;
        else
        {
            fout << left << setw(idWidth) << setfill(separator) << id;
            fout << left << setw(nameWidth) << setfill(separator) << user[i].name;
            fout << left << setw(emailWidth) << setfill(separator) << user[i].email;
            fout << left << setw(phoneWidth) << setfill(separator) << user[i].phone;
            fout << left << setw(billWidth) << setfill(separator) << user[i].bill;
            fout << left << setw(serviceWidth) << setfill(separator) << user[i].service;
            fout << left << setw(addressWidth) << setfill(separator) << user[i].address;
            fout << endl;
        } 
    }
    fout.close();
    cout << "Data is removed successfully!\n";
    pressAnyKey();
    removeData();
}

void removeData_2()
{
    system("cls");
    readFile();
    cout << "Remove data from id: ";
    int input_id1; cin >> input_id1;
    cout << "              to id: ";
    int input_id2; cin >> input_id2;
    if(input_id1 > input_id2) swap(input_id1, input_id2);
    int distance = input_id2 - input_id1 + 1;
    ofstream fout;
    fout.open("data.txt");
    fout << left << setw(idWidth) << setfill(separator) << user[0].id;
    fout << left << setw(nameWidth) << setfill(separator) << user[0].name;
    fout << left << setw(emailWidth) << setfill(separator) << user[0].email;
    fout << left << setw(phoneWidth) << setfill(separator) << user[0].phone;
    fout << left << setw(billWidth) << setfill(separator) << user[0].bill;
    fout << left << setw(serviceWidth) << setfill(separator) << user[0].service;
    fout << left << setw(addressWidth) << setfill(separator) << user[0].address;
    fout << endl;
    int id;
    for(int i=1;i<numOfUsers;i++)
    {
        if(i>=input_id1) id = i-distance;
        else id = i;
        if(i>=input_id1 && i <= input_id2) continue;
        else
        {
            fout << left << setw(idWidth) << setfill(separator) << id;
            fout << left << setw(nameWidth) << setfill(separator) << user[i].name;
            fout << left << setw(emailWidth) << setfill(separator) << user[i].email;
            fout << left << setw(phoneWidth) << setfill(separator) << user[i].phone;
            fout << left << setw(billWidth) << setfill(separator) << user[i].bill;
            fout << left << setw(serviceWidth) << setfill(separator) << user[i].service;
            fout << left << setw(addressWidth) << setfill(separator) << user[i].address;
            fout << endl;
        } 
    }
    fout.close();
    cout << "Data is removed successfully!\n";
    pressAnyKey();
    removeData();
}

void modifyData()
{
    system("cls");
    cout << "Modify Data\n";
    cout << "1.Modify data by id\n";
    cout << "2.Replace user's data\n";
    cout << "3.Return Menu\n";
    cout << "Enter your choice: ";
    int user_input;
    cin >> user_input;
    switch (user_input)
    {
    case 1:
        system("cls");
        modifyData_1();
        break;
    case 2:
        system("cls");
        modifyData_2();
        break;
    case 3:
        showMenu();
        break;    
    default:
        cout << "input invalid!!!";
        pressAnyKey();
        modifyData();
        break;
    }
    system("pause");
}

void modifyData_1()
{
    system("cls");
    readFile();
    cout << "Select the user's id you want to modify: ";
    int input_id; cin >> input_id;
    cout << left << setw(idWidth) << setfill(separator) << user[input_id].id;
    cout << left << setw(nameWidth) << setfill(separator) << user[input_id].name;
    cout << left << setw(emailWidth) << setfill(separator) << user[input_id].email;
    cout << left << setw(phoneWidth) << setfill(separator) << user[input_id].phone;
    cout << left << setw(billWidth) << setfill(separator) << user[input_id].bill;
    cout << left << setw(serviceWidth) << setfill(separator) << user[input_id].service;
    cout << left << setw(addressWidth) << setfill(separator) << user[input_id].address;
    cout << endl;
    cout << "Select the information you want to modify:\n";
    cout << "1.Name\n";
    cout << "2.Email\n";
    cout << "3.Phone\n";
    cout << "4.Bill\n";
    cout << "5.Service\n";
    cout << "6.Address\n";
    cout << "Enter your choice: ";
    int user_input;
    cin >> user_input;
    cin.ignore();
    cout << endl;
    string input_name;
    string input_email;
    string input_phone; 
    string input_bill;
    string input_service; 
    string input_address; 
    switch (user_input)
    {
    case 1:
        cout << "Enter new name: ";
        getline(cin,input_name);
        user[input_id].name = input_name;
        updateFile();
        break;
    case 2:
        cout << "Enter new email: ";
        getline(cin,input_email);
        user[input_id].email = input_email;
        updateFile();
        break;
    case 3:
        cout << "Enter new phone: ";
        getline(cin,input_phone);
        user[input_id].phone = input_phone;
        updateFile();
        break;
    case 4:
        cout << "Enter new bill: ";
        getline(cin,input_bill);
        user[input_id].bill = input_bill;
        updateFile();
        break;
    case 5:
        cout << "Enter new service: ";
        getline(cin,input_service);
        user[input_id].service = input_service;
        updateFile();
        break;
    case 6:
        cout << "Enter new address: ";
        getline(cin,input_address);
        user[input_id].address = input_address;
        updateFile();
        break;
    default:
        cout << "input invalid!!!";
        pressAnyKey();
        modifyData_1();
        break;
    }
    cout << "User's data is modified successfully!\n";
    cout << "Do you want to continue to modify user's data? (Y/N): ";
    char c; cin >> c;
    cin.ignore();
    switch (c)
    {
    case 'Y':
        modifyData_1();
        break;
    case 'y':
        modifyData_1();
        break;
    default:
        showMenu();
        break;
    }
}

void modifyData_2()
{
    system("cls");
    readFile();
    cout << "Select the user's id you want to replace: ";
    int input_id; cin >> input_id;
    cout << left << setw(idWidth) << setfill(separator) << user[input_id].id;
    cout << left << setw(nameWidth) << setfill(separator) << user[input_id].name;
    cout << left << setw(emailWidth) << setfill(separator) << user[input_id].email;
    cout << left << setw(phoneWidth) << setfill(separator) << user[input_id].phone;
    cout << left << setw(billWidth) << setfill(separator) << user[input_id].bill;
    cout << left << setw(serviceWidth) << setfill(separator) << user[input_id].service;
    cout << left << setw(addressWidth) << setfill(separator) << user[input_id].address;
    cout << endl;
    cin.ignore();
    cout << "Enter new name: ";
    string input_name; getline(cin,input_name);
    user[input_id].name = input_name;
    cout << "Enter new email: ";
    string input_email; getline(cin,input_email);
    user[input_id].email = input_email;
    cout << "Enter new phone: ";
    string input_phone; getline(cin,input_phone);
    user[input_id].phone = input_phone;
    cout << "Enter new bill: ";
    string input_bill; getline(cin,input_bill);
    user[input_id].bill = input_bill;
    cout << "Enter new service: ";
    string input_service; getline(cin,input_service);
    user[input_id].service = input_service;
    cout << "Enter new address: ";
    string input_address; getline(cin,input_address);
    user[input_id].address = input_address;
    updateFile();
    cout << "User's data is replaced successfully!\n";
    cout << "Do you want to continue to replace user's data? (Y/N): ";
    char c; cin >> c;
    cin.ignore();
    switch (c)
    {
    case 'Y':
        modifyData_2();
        break;
    case 'y':
        modifyData_2();
        break;
    default:
        showMenu();
        break;
    }
}

void searchData()
{
    system("cls");
    cout << "Search Data\n";
    cout << "1.Search by id\n";
    cout << "2.Search by name\n";
    cout << "3.Search by email\n";
    cout << "4.Search by phone\n";
    cout << "5.Search by bill\n";
    cout << "6.Search by service\n";
    cout << "7.Search by address\n";
    cout << "8.Return Menu\n";
    cout << "Enter your choice: ";
    int user_input;
    cin >> user_input;
    cin.ignore();
    switch (user_input)
    {
    case 1:
        system("cls");
        searchData_1();
        break;
    case 2:
        system("cls");
        searchData_2();
        break;
    case 3:
        system("cls");
        searchData_3();
        break;
    case 4:
        system("cls");
        searchData_4();
        break;
    case 5:
        system("cls");
        searchData_5();
        break;
    case 6:
        system("cls");
        searchData_6();
        break;
    case 7:
        system("cls");
        searchData_7();
        break;
    case 8:
        showMenu();
        break;    
    default:
        cout << "input invalid!!!";
        pressAnyKey();
        searchData();
        break;
    }
    system("pause");
}

void searchData_1()
{
    system("cls");
    readFile();
    cout << "Select the user's id you want to search: ";
    int input_id; cin >> input_id;
    if(input_id < 1 || input_id >=numOfUsers) 
    {
        cout << "Not found user's data\n";
        pressAnyKey();
        showMenu();
    }else
    {
        cout << "How would you like to see the result?\n";
        cout << "1.Print to the screen\n";
        cout << "2.Save to new file\n";
        cout << "Enter your choice: ";  
        int user_input;
        cin >> user_input;
        ofstream fout;
        switch (user_input)
        {
        case 1:
            system("cls");
            cout << left << setw(idWidth) << setfill(separator) << user[0].id;
            cout << left << setw(nameWidth) << setfill(separator) << user[0].name;
            cout << left << setw(emailWidth) << setfill(separator) << user[0].email;
            cout << left << setw(phoneWidth) << setfill(separator) << user[0].phone;
            cout << left << setw(billWidth) << setfill(separator) << user[0].bill;
            cout << left << setw(serviceWidth) << setfill(separator) << user[0].service;
            cout << left << setw(addressWidth) << setfill(separator) << user[0].address;
            cout << endl;
            cout << left << setw(idWidth) << setfill(separator) << user[input_id].id;
            cout << left << setw(nameWidth) << setfill(separator) << user[input_id].name;
            cout << left << setw(emailWidth) << setfill(separator) << user[input_id].email;
            cout << left << setw(phoneWidth) << setfill(separator) << user[input_id].phone;
            cout << left << setw(billWidth) << setfill(separator) << user[input_id].bill;
            cout << left << setw(serviceWidth) << setfill(separator) << user[input_id].service;
            cout << left << setw(addressWidth) << setfill(separator) << user[input_id].address;
            cout << endl;
            cout << "--------------------------------\n";
            pressAnyKey();
            showMenu();
            break;
        case 2:
            fout.open("search.txt");
            fout << left << setw(idWidth) << setfill(separator) << user[0].id;
            fout << left << setw(nameWidth) << setfill(separator) << user[0].name;
            fout << left << setw(emailWidth) << setfill(separator) << user[0].email;
            fout << left << setw(phoneWidth) << setfill(separator) << user[0].phone;
            fout << left << setw(billWidth) << setfill(separator) << user[0].bill;
            fout << left << setw(serviceWidth) << setfill(separator) << user[0].service;
            fout << left << setw(addressWidth) << setfill(separator) << user[0].address;
            fout << endl;
            fout << left << setw(idWidth) << setfill(separator) << user[input_id].id;
            fout << left << setw(nameWidth) << setfill(separator) << user[input_id].name;
            fout << left << setw(emailWidth) << setfill(separator) << user[input_id].email;
            fout << left << setw(phoneWidth) << setfill(separator) << user[input_id].phone;
            fout << left << setw(billWidth) << setfill(separator) << user[input_id].bill;
            fout << left << setw(serviceWidth) << setfill(separator) << user[input_id].service;
            fout << left << setw(addressWidth) << setfill(separator) << user[input_id].address;
            fout << endl;
            fout.close();
            cout << "Data has been successfully transferred to search.txt\n";
            pressAnyKey();
            showMenu();
            break;
        default:
            cout << "input invalid!!!";
            pressAnyKey();
            searchData_1();
            break;
        }
    }
    
}

void searchData_2()
{
    system("cls");
    readFile();
    cout << "Enter the user's name you want to search: ";
    string input_name; getline(cin,input_name);
    input_name = lower_string(input_name);
    cout << "How would you like to see the result?\n";
    cout << "1.Print to the screen\n";
    cout << "2.Save to new file\n";
    cout << "Enter your choice: ";  
    int user_input; cin >> user_input;
    cin.ignore();
    string tmp;
    ofstream fout;
    switch (user_input)
    {
    case 1:
        system("cls");
        cout << left << setw(idWidth) << setfill(separator) << user[0].id;
        cout << left << setw(nameWidth) << setfill(separator) << user[0].name;
        cout << left << setw(emailWidth) << setfill(separator) << user[0].email;
        cout << left << setw(phoneWidth) << setfill(separator) << user[0].phone;
        cout << left << setw(billWidth) << setfill(separator) << user[0].bill;
        cout << left << setw(serviceWidth) << setfill(separator) << user[0].service;
        cout << left << setw(addressWidth) << setfill(separator) << user[0].address;
        cout << endl;
        for(int i = 1; i < numOfUsers; i++)
        {
            tmp = lower_string(user[i].name);
            if(check_child_string(tmp,input_name))
            {
                cout << left << setw(idWidth) << setfill(separator) << user[i].id;
                cout << left << setw(nameWidth) << setfill(separator) << user[i].name;
                cout << left << setw(emailWidth) << setfill(separator) << user[i].email;
                cout << left << setw(phoneWidth) << setfill(separator) << user[i].phone;
                cout << left << setw(billWidth) << setfill(separator) << user[i].bill;
                cout << left << setw(serviceWidth) << setfill(separator) << user[i].service;
                cout << left << setw(addressWidth) << setfill(separator) << user[i].address;
                cout << endl;
            }else continue;
        }
        cout << "--------------------------------\n";
        pressAnyKey();
        showMenu();
        break;
    case 2:
        fout.open("search.txt");
        fout << left << setw(idWidth) << setfill(separator) << user[0].id;
        fout << left << setw(nameWidth) << setfill(separator) << user[0].name;
        fout << left << setw(emailWidth) << setfill(separator) << user[0].email;
        fout << left << setw(phoneWidth) << setfill(separator) << user[0].phone;
        fout << left << setw(billWidth) << setfill(separator) << user[0].bill;
        fout << left << setw(serviceWidth) << setfill(separator) << user[0].service;
        fout << left << setw(addressWidth) << setfill(separator) << user[0].address;
        fout << endl;
        for(int i = 1; i < numOfUsers; i++)
        {
            tmp = lower_string(user[i].name);
            if(check_child_string(tmp,input_name))
            {
                fout << left << setw(idWidth) << setfill(separator) << user[i].id;
                fout << left << setw(nameWidth) << setfill(separator) << user[i].name;
                fout << left << setw(emailWidth) << setfill(separator) << user[i].email;
                fout << left << setw(phoneWidth) << setfill(separator) << user[i].phone;
                fout << left << setw(billWidth) << setfill(separator) << user[i].bill;
                fout << left << setw(serviceWidth) << setfill(separator) << user[i].service;
                fout << left << setw(addressWidth) << setfill(separator) << user[i].address;
                fout << endl;
            }else continue;
        }
        fout.close();
        cout << "Data has been successfully transferred to search.txt\n";
        pressAnyKey();
        showMenu();
        break;
    default:
        cout << "input invalid!!!";
        pressAnyKey();
        searchData_2();
        break;
    }
}

void searchData_3()
{
    system("cls");
    readFile();
    cout << "Enter the user's email you want to search: ";
    string input_email; getline(cin,input_email);
    input_email = lower_string(input_email);
    cout << "How would you like to see the result?\n";
    cout << "1.Print to the screen\n";
    cout << "2.Save to new file\n";
    cout << "Enter your choice: ";  
    int user_input; cin >> user_input;
    cin.ignore();
    string tmp;
    ofstream fout;
    switch (user_input)
    {
    case 1:
        system("cls");
        cout << left << setw(idWidth) << setfill(separator) << user[0].id;
        cout << left << setw(nameWidth) << setfill(separator) << user[0].name;
        cout << left << setw(emailWidth) << setfill(separator) << user[0].email;
        cout << left << setw(phoneWidth) << setfill(separator) << user[0].phone;
        cout << left << setw(billWidth) << setfill(separator) << user[0].bill;
        cout << left << setw(serviceWidth) << setfill(separator) << user[0].service;
        cout << left << setw(addressWidth) << setfill(separator) << user[0].address;
        cout << endl;
        for(int i = 1; i < numOfUsers; i++)
        {
            tmp = lower_string(user[i].email);
            if(check_child_string(tmp,input_email))
            {
                cout << left << setw(idWidth) << setfill(separator) << user[i].id;
                cout << left << setw(nameWidth) << setfill(separator) << user[i].name;
                cout << left << setw(emailWidth) << setfill(separator) << user[i].email;
                cout << left << setw(phoneWidth) << setfill(separator) << user[i].phone;
                cout << left << setw(billWidth) << setfill(separator) << user[i].bill;
                cout << left << setw(serviceWidth) << setfill(separator) << user[i].service;
                cout << left << setw(addressWidth) << setfill(separator) << user[i].address;
                cout << endl;
            }else continue;
        }
        cout << "--------------------------------\n";
        pressAnyKey();
        showMenu();
        break;
    case 2:
        fout.open("search.txt");
        fout << left << setw(idWidth) << setfill(separator) << user[0].id;
        fout << left << setw(nameWidth) << setfill(separator) << user[0].name;
        fout << left << setw(emailWidth) << setfill(separator) << user[0].email;
        fout << left << setw(phoneWidth) << setfill(separator) << user[0].phone;
        fout << left << setw(billWidth) << setfill(separator) << user[0].bill;
        fout << left << setw(serviceWidth) << setfill(separator) << user[0].service;
        fout << left << setw(addressWidth) << setfill(separator) << user[0].address;
        fout << endl;
        for(int i = 1; i < numOfUsers; i++)
        {
            tmp = lower_string(user[i].email);
            if(check_child_string(tmp,input_email))
            {
                fout << left << setw(idWidth) << setfill(separator) << user[i].id;
                fout << left << setw(nameWidth) << setfill(separator) << user[i].name;
                fout << left << setw(emailWidth) << setfill(separator) << user[i].email;
                fout << left << setw(phoneWidth) << setfill(separator) << user[i].phone;
                fout << left << setw(billWidth) << setfill(separator) << user[i].bill;
                fout << left << setw(serviceWidth) << setfill(separator) << user[i].service;
                fout << left << setw(addressWidth) << setfill(separator) << user[i].address;
                fout << endl;
            }else continue;
        }
        fout.close();
        cout << "Data has been successfully transferred to search.txt\n";
        pressAnyKey();
        showMenu();
        break;
    default:
        cout << "input invalid!!!";
        pressAnyKey();
        searchData_3();
        break;
    }
}

void searchData_4()
{
    system("cls");
    readFile();
    cout << "Enter the user's phone you want to search: ";
    string input_phone; getline(cin,input_phone);
    cout << "How would you like to see the result?\n";
    cout << "1.Print to the screen\n";
    cout << "2.Save to new file\n";
    cout << "Enter your choice: ";  
    int user_input; cin >> user_input;
    cin.ignore();
    string tmp;
    ofstream fout;
    switch (user_input)
    {
    case 1:
        system("cls");
        cout << left << setw(idWidth) << setfill(separator) << user[0].id;
        cout << left << setw(nameWidth) << setfill(separator) << user[0].name;
        cout << left << setw(emailWidth) << setfill(separator) << user[0].email;
        cout << left << setw(phoneWidth) << setfill(separator) << user[0].phone;
        cout << left << setw(billWidth) << setfill(separator) << user[0].bill;
        cout << left << setw(serviceWidth) << setfill(separator) << user[0].service;
        cout << left << setw(addressWidth) << setfill(separator) << user[0].address;
        cout << endl;
        for(int i = 1; i < numOfUsers; i++)
        {
            tmp = user[i].phone;
            if(check_child_string(tmp,input_phone))
            {
                cout << left << setw(idWidth) << setfill(separator) << user[i].id;
                cout << left << setw(nameWidth) << setfill(separator) << user[i].name;
                cout << left << setw(emailWidth) << setfill(separator) << user[i].email;
                cout << left << setw(phoneWidth) << setfill(separator) << user[i].phone;
                cout << left << setw(billWidth) << setfill(separator) << user[i].bill;
                cout << left << setw(serviceWidth) << setfill(separator) << user[i].service;
                cout << left << setw(addressWidth) << setfill(separator) << user[i].address;
                cout << endl;
            }else continue;
        }
        cout << "--------------------------------\n";
        pressAnyKey();
        showMenu();
        break;
    case 2:
        fout.open("search.txt");
        fout << left << setw(idWidth) << setfill(separator) << user[0].id;
        fout << left << setw(nameWidth) << setfill(separator) << user[0].name;
        fout << left << setw(emailWidth) << setfill(separator) << user[0].email;
        fout << left << setw(phoneWidth) << setfill(separator) << user[0].phone;
        fout << left << setw(billWidth) << setfill(separator) << user[0].bill;
        fout << left << setw(serviceWidth) << setfill(separator) << user[0].service;
        fout << left << setw(addressWidth) << setfill(separator) << user[0].address;
        fout << endl;
        for(int i = 1; i < numOfUsers; i++)
        {
            tmp = user[i].phone;
            if(check_child_string(tmp,input_phone))
            {
                fout << left << setw(idWidth) << setfill(separator) << user[i].id;
                fout << left << setw(nameWidth) << setfill(separator) << user[i].name;
                fout << left << setw(emailWidth) << setfill(separator) << user[i].email;
                fout << left << setw(phoneWidth) << setfill(separator) << user[i].phone;
                fout << left << setw(billWidth) << setfill(separator) << user[i].bill;
                fout << left << setw(serviceWidth) << setfill(separator) << user[i].service;
                fout << left << setw(addressWidth) << setfill(separator) << user[i].address;
                fout << endl;
            }else continue;
        }
        fout.close();
        cout << "Data has been successfully transferred to search.txt\n";
        pressAnyKey();
        showMenu();
        break;
    default:
        cout << "input invalid!!!";
        pressAnyKey();
        searchData_4();
        break;
    }
}

void searchData_5()
{
    system("cls");
    readFile();
    cout << "Enter the user's bill you want to search: ";
    string input_bill; getline(cin,input_bill);
    input_bill = lower_string(input_bill);
    input_bill = delete_dot(input_bill);
    cout << "How would you like to see the result?\n";
    cout << "1.Print to the screen\n";
    cout << "2.Save to new file\n";
    cout << "Enter your choice: ";  
    int user_input; cin >> user_input;
    cin.ignore();
    string tmp;
    ofstream fout;
    switch (user_input)
    {
    case 1:
        system("cls");
        cout << left << setw(idWidth) << setfill(separator) << user[0].id;
        cout << left << setw(nameWidth) << setfill(separator) << user[0].name;
        cout << left << setw(emailWidth) << setfill(separator) << user[0].email;
        cout << left << setw(phoneWidth) << setfill(separator) << user[0].phone;
        cout << left << setw(billWidth) << setfill(separator) << user[0].bill;
        cout << left << setw(serviceWidth) << setfill(separator) << user[0].service;
        cout << left << setw(addressWidth) << setfill(separator) << user[0].address;
        cout << endl;
        for(int i = 1; i < numOfUsers; i++)
        {
            tmp = lower_string(user[i].bill);
            tmp = delete_dot(tmp);
            if(check_child_string(tmp,input_bill))
            {
                cout << left << setw(idWidth) << setfill(separator) << user[i].id;
                cout << left << setw(nameWidth) << setfill(separator) << user[i].name;
                cout << left << setw(emailWidth) << setfill(separator) << user[i].email;
                cout << left << setw(phoneWidth) << setfill(separator) << user[i].phone;
                cout << left << setw(billWidth) << setfill(separator) << user[i].bill;
                cout << left << setw(serviceWidth) << setfill(separator) << user[i].service;
                cout << left << setw(addressWidth) << setfill(separator) << user[i].address;
                cout << endl;
            }else continue;
        }
        cout << "--------------------------------\n";
        pressAnyKey();
        showMenu();
        break;
    case 2:
        fout.open("search.txt");
        fout << left << setw(idWidth) << setfill(separator) << user[0].id;
        fout << left << setw(nameWidth) << setfill(separator) << user[0].name;
        fout << left << setw(emailWidth) << setfill(separator) << user[0].email;
        fout << left << setw(phoneWidth) << setfill(separator) << user[0].phone;
        fout << left << setw(billWidth) << setfill(separator) << user[0].bill;
        fout << left << setw(serviceWidth) << setfill(separator) << user[0].service;
        fout << left << setw(addressWidth) << setfill(separator) << user[0].address;
        fout << endl;
        for(int i = 1; i < numOfUsers; i++)
        {
            tmp = lower_string(user[i].bill);
            tmp = delete_dot(tmp);
            if(check_child_string(tmp,input_bill))
            {
                fout << left << setw(idWidth) << setfill(separator) << user[i].id;
                fout << left << setw(nameWidth) << setfill(separator) << user[i].name;
                fout << left << setw(emailWidth) << setfill(separator) << user[i].email;
                fout << left << setw(phoneWidth) << setfill(separator) << user[i].phone;
                fout << left << setw(billWidth) << setfill(separator) << user[i].bill;
                fout << left << setw(serviceWidth) << setfill(separator) << user[i].service;
                fout << left << setw(addressWidth) << setfill(separator) << user[i].address;
                fout << endl;
            }else continue;
        }
        fout.close();
        cout << "Data has been successfully transferred to search.txt\n";
        pressAnyKey();
        showMenu();
        break;
    default:
        cout << "input invalid!!!";
        pressAnyKey();
        searchData_5();
        break;
    }
}

void searchData_6()
{
    system("cls");
    readFile();
    cout << "Enter the user's service you want to search: ";
    string input_service; getline(cin,input_service);
    input_service = lower_string(input_service);
    cout << "How would you like to see the result?\n";
    cout << "1.Print to the screen\n";
    cout << "2.Save to new file\n";
    cout << "Enter your choice: ";  
    int user_input; cin >> user_input;
    cin.ignore();
    string tmp;
    ofstream fout;
    switch (user_input)
    {
    case 1:
        system("cls");
        cout << left << setw(idWidth) << setfill(separator) << user[0].id;
        cout << left << setw(nameWidth) << setfill(separator) << user[0].name;
        cout << left << setw(emailWidth) << setfill(separator) << user[0].email;
        cout << left << setw(phoneWidth) << setfill(separator) << user[0].phone;
        cout << left << setw(billWidth) << setfill(separator) << user[0].bill;
        cout << left << setw(serviceWidth) << setfill(separator) << user[0].service;
        cout << left << setw(addressWidth) << setfill(separator) << user[0].address;
        cout << endl;
        for(int i = 1; i < numOfUsers; i++)
        {
            tmp = lower_string(user[i].service);
            if(check_child_string(tmp,input_service))
            {
                cout << left << setw(idWidth) << setfill(separator) << user[i].id;
                cout << left << setw(nameWidth) << setfill(separator) << user[i].name;
                cout << left << setw(emailWidth) << setfill(separator) << user[i].email;
                cout << left << setw(phoneWidth) << setfill(separator) << user[i].phone;
                cout << left << setw(billWidth) << setfill(separator) << user[i].bill;
                cout << left << setw(serviceWidth) << setfill(separator) << user[i].service;
                cout << left << setw(addressWidth) << setfill(separator) << user[i].address;
                cout << endl;
            }else continue;
        }
        cout << "--------------------------------\n";
        pressAnyKey();
        showMenu();
        break;
    case 2:
        fout.open("search.txt");
        fout << left << setw(idWidth) << setfill(separator) << user[0].id;
        fout << left << setw(nameWidth) << setfill(separator) << user[0].name;
        fout << left << setw(emailWidth) << setfill(separator) << user[0].email;
        fout << left << setw(phoneWidth) << setfill(separator) << user[0].phone;
        fout << left << setw(billWidth) << setfill(separator) << user[0].bill;
        fout << left << setw(serviceWidth) << setfill(separator) << user[0].service;
        fout << left << setw(addressWidth) << setfill(separator) << user[0].address;
        fout << endl;
        for(int i = 1; i < numOfUsers; i++)
        {
            tmp = lower_string(user[i].service);
            if(check_child_string(tmp,input_service))
            {
                fout << left << setw(idWidth) << setfill(separator) << user[i].id;
                fout << left << setw(nameWidth) << setfill(separator) << user[i].name;
                fout << left << setw(emailWidth) << setfill(separator) << user[i].email;
                fout << left << setw(phoneWidth) << setfill(separator) << user[i].phone;
                fout << left << setw(billWidth) << setfill(separator) << user[i].bill;
                fout << left << setw(serviceWidth) << setfill(separator) << user[i].service;
                fout << left << setw(addressWidth) << setfill(separator) << user[i].address;
                fout << endl;
            }else continue;
        }
        fout.close();
        cout << "Data has been successfully transferred to search.txt\n";
        pressAnyKey();
        showMenu();
        break;
    default:
        cout << "input invalid!!!";
        pressAnyKey();
        searchData_6();
        break;
    }
}

void searchData_7()
{
    system("cls");
    readFile();
    cout << "Enter the user's address you want to search: ";
    string input_address; getline(cin,input_address);
    input_address = lower_string(input_address);
    cout << "How would you like to see the result?\n";
    cout << "1.Print to the screen\n";
    cout << "2.Save to new file\n";
    cout << "Enter your choice: ";  
    int user_input; cin >> user_input;
    cin.ignore();
    string tmp;
    ofstream fout;
    switch (user_input)
    {
    case 1:
        system("cls");
        cout << left << setw(idWidth) << setfill(separator) << user[0].id;
        cout << left << setw(nameWidth) << setfill(separator) << user[0].name;
        cout << left << setw(emailWidth) << setfill(separator) << user[0].email;
        cout << left << setw(phoneWidth) << setfill(separator) << user[0].phone;
        cout << left << setw(billWidth) << setfill(separator) << user[0].bill;
        cout << left << setw(serviceWidth) << setfill(separator) << user[0].service;
        cout << left << setw(addressWidth) << setfill(separator) << user[0].address;
        cout << endl;
        for(int i = 1; i < numOfUsers; i++)
        {
            tmp = lower_string(user[i].address);
            if(check_child_string(tmp,input_address))
            {
                cout << left << setw(idWidth) << setfill(separator) << user[i].id;
                cout << left << setw(nameWidth) << setfill(separator) << user[i].name;
                cout << left << setw(emailWidth) << setfill(separator) << user[i].email;
                cout << left << setw(phoneWidth) << setfill(separator) << user[i].phone;
                cout << left << setw(billWidth) << setfill(separator) << user[i].bill;
                cout << left << setw(serviceWidth) << setfill(separator) << user[i].service;
                cout << left << setw(addressWidth) << setfill(separator) << user[i].address;
                cout << endl;
            }else continue;
        }
        cout << "--------------------------------\n";
        pressAnyKey();
        showMenu();
        break;
    case 2:
        fout.open("search.txt");
        fout << left << setw(idWidth) << setfill(separator) << user[0].id;
        fout << left << setw(nameWidth) << setfill(separator) << user[0].name;
        fout << left << setw(emailWidth) << setfill(separator) << user[0].email;
        fout << left << setw(phoneWidth) << setfill(separator) << user[0].phone;
        fout << left << setw(billWidth) << setfill(separator) << user[0].bill;
        fout << left << setw(serviceWidth) << setfill(separator) << user[0].service;
        fout << left << setw(addressWidth) << setfill(separator) << user[0].address;
        fout << endl;
        for(int i = 1; i < numOfUsers; i++)
        {
            tmp = lower_string(user[i].address);
            if(check_child_string(tmp,input_address))
            {
                fout << left << setw(idWidth) << setfill(separator) << user[i].id;
                fout << left << setw(nameWidth) << setfill(separator) << user[i].name;
                fout << left << setw(emailWidth) << setfill(separator) << user[i].email;
                fout << left << setw(phoneWidth) << setfill(separator) << user[i].phone;
                fout << left << setw(billWidth) << setfill(separator) << user[i].bill;
                fout << left << setw(serviceWidth) << setfill(separator) << user[i].service;
                fout << left << setw(addressWidth) << setfill(separator) << user[i].address;
                fout << endl;
            }else continue;
        }
        fout.close();
        cout << "Data has been successfully transferred to search.txt\n";
        pressAnyKey();
        showMenu();
        break;
    default:
        cout << "input invalid!!!";
        pressAnyKey();
        searchData_7();
        break;
    }
}

void sortData()
{
    system("cls");
    cout << "Sort Data\n";
    cout << "1.Sort by first name\n";
    cout << "2.Sort by last name\n";
    cout << "3.Sort by email\n";
    cout << "4.Sort by phone\n";
    cout << "5.Sort by bill\n";
    cout << "6.Sort by service\n";
    cout << "7.Sort by address\n";
    cout << "8.Return Menu\n";
    cout << "Enter your choice: ";
    int user_input;
    cin >> user_input;
    switch (user_input)
    {
    case 1:
        system("cls");
        sortData_1();
        break;
    case 2:
        system("cls");
        sortData_2();
        break;
    case 3:
        system("cls");
        sortData_3();
        break;
    case 4:
        system("cls");
        sortData_4();
        break;
    case 5:
        system("cls");
        sortData_5();
        break;
    case 6:
        system("cls");
        sortData_6();
        break;
    case 7:
        system("cls");
        sortData_7();
        break;  
    case 8:
        showMenu();
        break;    
    default:
        cout << "input invalid!!!";
        pressAnyKey();
        sortData();
        break;
    }
    system("pause");
}

void sortData_1()
{
    system("cls");
    cout << "Sort by first name\n";
    cout << "1.Ascending sort\n";
    cout << "2.Descending sort\n";
    cout << "Enter your choice: ";
    int user_input;
    cin >> user_input;
    switch (user_input)
    {
    case 1:
        system("cls");
        sortData_1_1();
        break;
    case 2:
        system("cls");
        sortData_1_2();
        break;
    default:
        cout << "input invalid!!!";
        pressAnyKey();
        sortData();
        break;
    }
    system("pause");
}

void sortData_1_1()
{
    system("cls");
    readFile();
    cout << "How would you like to see the result?\n";
    cout << "1.Print to the screen\n";
    cout << "2.Save to new file\n";
    cout << "Enter your choice: "; 
    int user_input; cin >> user_input;
    ofstream fout;
    string str1, str2;
    switch (user_input)
    {
    case 1:
        system("cls");
        for(int i = 1; i < numOfUsers - 1; i++)
        {
            for(int j = i + 1; j < numOfUsers; j++)
            {
                str1 = name2first(user[i].name);              
                str2 = name2first(user[j].name); 
                if(str1.compare(str2)>0) swap(user[i],user[j]);
            }
        }
        for(int i = 0; i < numOfUsers; i++)
        {
            cout << left << setw(idWidth) << setfill(separator) << user[i].id;
            cout << left << setw(nameWidth) << setfill(separator) << user[i].name;
            cout << left << setw(emailWidth) << setfill(separator) << user[i].email;
            cout << left << setw(phoneWidth) << setfill(separator) << user[i].phone;
            cout << left << setw(billWidth) << setfill(separator) << user[i].bill;
            cout << left << setw(serviceWidth) << setfill(separator) << user[i].service;
            cout << left << setw(addressWidth) << setfill(separator) << user[i].address;
            cout << endl;
        }
        cout << "--------------------------------\n";
        pressAnyKey();
        showMenu();
        break;
    case 2:
        fout.open("sort.txt");
        for(int i = 1; i < numOfUsers - 1; i++)
        {
            for(int j = i + 1; j < numOfUsers; j++)
            {
                str1 = name2first(user[i].name);              
                str2 = name2first(user[j].name); 
                if(str1.compare(str2)>0) swap(user[i],user[j]);
            }
        }
        for(int i = 0; i < numOfUsers; i++)
        {
            fout << left << setw(idWidth) << setfill(separator) << user[i].id;
            fout << left << setw(nameWidth) << setfill(separator) << user[i].name;
            fout << left << setw(emailWidth) << setfill(separator) << user[i].email;
            fout << left << setw(phoneWidth) << setfill(separator) << user[i].phone;
            fout << left << setw(billWidth) << setfill(separator) << user[i].bill;
            fout << left << setw(serviceWidth) << setfill(separator) << user[i].service;
            fout << left << setw(addressWidth) << setfill(separator) << user[i].address;
            fout << endl;
        }
        fout.close();
        cout << "Data has been successfully transferred to sort.txt\n";
        pressAnyKey();
        showMenu();
        break;
    default:
        cout << "input invalid!!!";
        pressAnyKey();
        sortData_1_1();
        break;
    }
}

void sortData_1_2()
{
    system("cls");
    readFile();
    cout << "How would you like to see the result?\n";
    cout << "1.Print to the screen\n";
    cout << "2.Save to new file\n";
    cout << "Enter your choice: "; 
    int user_input; cin >> user_input;
    ofstream fout;
    string str1, str2;
    switch (user_input)
    {
    case 1:
        system("cls");
        for(int i = 1; i < numOfUsers - 1; i++)
        {
            for(int j = i + 1; j < numOfUsers; j++)
            {
                str1 = name2first(user[i].name);              
                str2 = name2first(user[j].name); 
                if(str1.compare(str2)<0) swap(user[i],user[j]);
            }
        }
        for(int i = 0; i < numOfUsers; i++)
        {
            cout << left << setw(idWidth) << setfill(separator) << user[i].id;
            cout << left << setw(nameWidth) << setfill(separator) << user[i].name;
            cout << left << setw(emailWidth) << setfill(separator) << user[i].email;
            cout << left << setw(phoneWidth) << setfill(separator) << user[i].phone;
            cout << left << setw(billWidth) << setfill(separator) << user[i].bill;
            cout << left << setw(serviceWidth) << setfill(separator) << user[i].service;
            cout << left << setw(addressWidth) << setfill(separator) << user[i].address;
            cout << endl;
        }
        cout << "--------------------------------\n";
        pressAnyKey();
        showMenu();
        break;
    case 2:
        fout.open("sort.txt");
        for(int i = 1; i < numOfUsers - 1; i++)
        {
            for(int j = i + 1; j < numOfUsers; j++)
            {
                str1 = name2first(user[i].name);              
                str2 = name2first(user[j].name); 
                if(str1.compare(str2)<0) swap(user[i],user[j]);
            }
        }
        for(int i = 0; i < numOfUsers; i++)
        {
            fout << left << setw(idWidth) << setfill(separator) << user[i].id;
            fout << left << setw(nameWidth) << setfill(separator) << user[i].name;
            fout << left << setw(emailWidth) << setfill(separator) << user[i].email;
            fout << left << setw(phoneWidth) << setfill(separator) << user[i].phone;
            fout << left << setw(billWidth) << setfill(separator) << user[i].bill;
            fout << left << setw(serviceWidth) << setfill(separator) << user[i].service;
            fout << left << setw(addressWidth) << setfill(separator) << user[i].address;
            fout << endl;
        }
        fout.close();
        cout << "Data has been successfully transferred to sort.txt\n";
        pressAnyKey();
        showMenu();
        break;
    default:
        cout << "input invalid!!!";
        pressAnyKey();
        sortData_1_2();
        break;
    }
}

void sortData_2()
{
    system("cls");
    cout << "Sort by last name\n";
    cout << "1.Ascending sort\n";
    cout << "2.Descending sort\n";
    cout << "Enter your choice: ";
    int user_input;
    cin >> user_input;
    switch (user_input)
    {
    case 1:
        system("cls");
        sortData_2_1();
        break;
    case 2:
        system("cls");
        sortData_2_2();
        break;
    default:
        cout << "input invalid!!!";
        pressAnyKey();
        sortData();
        break;
    }
    system("pause");
}

void sortData_2_1()
{
    system("cls");
    readFile();
    cout << "How would you like to see the result?\n";
    cout << "1.Print to the screen\n";
    cout << "2.Save to new file\n";
    cout << "Enter your choice: "; 
    int user_input; cin >> user_input;
    ofstream fout;
    switch (user_input)
    {
    case 1:
        system("cls");
        for(int i = 1; i < numOfUsers - 1; i++)
        {
            for(int j = i + 1; j < numOfUsers; j++)
            {
                if(user[i].name.compare(user[j].name)>0) swap(user[i],user[j]);
            }
        }
        for(int i = 0; i < numOfUsers; i++)
        {
            cout << left << setw(idWidth) << setfill(separator) << user[i].id;
            cout << left << setw(nameWidth) << setfill(separator) << user[i].name;
            cout << left << setw(emailWidth) << setfill(separator) << user[i].email;
            cout << left << setw(phoneWidth) << setfill(separator) << user[i].phone;
            cout << left << setw(billWidth) << setfill(separator) << user[i].bill;
            cout << left << setw(serviceWidth) << setfill(separator) << user[i].service;
            cout << left << setw(addressWidth) << setfill(separator) << user[i].address;
            cout << endl;
        }
        cout << "--------------------------------\n";
        pressAnyKey();
        showMenu();
        break;
    case 2:
        fout.open("sort.txt");
        for(int i = 1; i < numOfUsers - 1; i++)
        {
            for(int j = i + 1; j < numOfUsers; j++)
            {
                if(user[i].name.compare(user[j].name)>0) swap(user[i],user[j]);
            }
        }
        for(int i = 0; i < numOfUsers; i++)
        {
            fout << left << setw(idWidth) << setfill(separator) << user[i].id;
            fout << left << setw(nameWidth) << setfill(separator) << user[i].name;
            fout << left << setw(emailWidth) << setfill(separator) << user[i].email;
            fout << left << setw(phoneWidth) << setfill(separator) << user[i].phone;
            fout << left << setw(billWidth) << setfill(separator) << user[i].bill;
            fout << left << setw(serviceWidth) << setfill(separator) << user[i].service;
            fout << left << setw(addressWidth) << setfill(separator) << user[i].address;
            fout << endl;
        }
        fout.close();
        cout << "Data has been successfully transferred to sort.txt\n";
        pressAnyKey();
        showMenu();
        break;
    default:
        cout << "input invalid!!!";
        pressAnyKey();
        sortData_2_1();
        break;
    }
}

void sortData_2_2()
{
    system("cls");
    readFile();
    cout << "How would you like to see the result?\n";
    cout << "1.Print to the screen\n";
    cout << "2.Save to new file\n";
    cout << "Enter your choice: "; 
    int user_input; cin >> user_input;
    ofstream fout;
    switch (user_input)
    {
    case 1:
        system("cls");
        for(int i = 1; i < numOfUsers - 1; i++)
        {
            for(int j = i + 1; j < numOfUsers; j++)
            {
                if(user[i].name.compare(user[j].name)<0) swap(user[i],user[j]);
            }
        }
        for(int i = 0; i < numOfUsers; i++)
        {
            cout << left << setw(idWidth) << setfill(separator) << user[i].id;
            cout << left << setw(nameWidth) << setfill(separator) << user[i].name;
            cout << left << setw(emailWidth) << setfill(separator) << user[i].email;
            cout << left << setw(phoneWidth) << setfill(separator) << user[i].phone;
            cout << left << setw(billWidth) << setfill(separator) << user[i].bill;
            cout << left << setw(serviceWidth) << setfill(separator) << user[i].service;
            cout << left << setw(addressWidth) << setfill(separator) << user[i].address;
            cout << endl;
        }
        cout << "--------------------------------\n";
        pressAnyKey();
        showMenu();
        break;
    case 2:
        fout.open("sort.txt");
        for(int i = 1; i < numOfUsers - 1; i++)
        {
            for(int j = i + 1; j < numOfUsers; j++)
            {
                if(user[i].name.compare(user[j].name)<0) swap(user[i],user[j]);
            }
        }
        for(int i = 0; i < numOfUsers; i++)
        {
            fout << left << setw(idWidth) << setfill(separator) << user[i].id;
            fout << left << setw(nameWidth) << setfill(separator) << user[i].name;
            fout << left << setw(emailWidth) << setfill(separator) << user[i].email;
            fout << left << setw(phoneWidth) << setfill(separator) << user[i].phone;
            fout << left << setw(billWidth) << setfill(separator) << user[i].bill;
            fout << left << setw(serviceWidth) << setfill(separator) << user[i].service;
            fout << left << setw(addressWidth) << setfill(separator) << user[i].address;
            fout << endl;
        }
        fout.close();
        cout << "Data has been successfully transferred to sort.txt\n";
        pressAnyKey();
        showMenu();
        break;
    default:
        cout << "input invalid!!!";
        pressAnyKey();
        sortData_2_2();
        break;
    }
}

void sortData_3()
{
    system("cls");
    cout << "Sort by email\n";
    cout << "1.Ascending sort\n";
    cout << "2.Descending sort\n";
    cout << "Enter your choice: ";
    int user_input;
    cin >> user_input;
    switch (user_input)
    {
    case 1:
        system("cls");
        sortData_3_1();
        break;
    case 2:
        system("cls");
        sortData_3_2();
        break;
    default:
        cout << "input invalid!!!";
        pressAnyKey();
        sortData();
        break;
    }
    system("pause");
}

void sortData_3_1()
{
    system("cls");
    readFile();
    cout << "How would you like to see the result?\n";
    cout << "1.Print to the screen\n";
    cout << "2.Save to new file\n";
    cout << "Enter your choice: "; 
    int user_input; cin >> user_input;
    ofstream fout;
    string str1, str2;
    switch (user_input)
    {
    case 1:
        system("cls");
        for(int i = 1; i < numOfUsers - 1; i++)
        {
            for(int j = i + 1; j < numOfUsers; j++)
            {
                str1 = delete_acom(user[i].email); str1 = lower_string(str1);              
                str2 = delete_acom(user[j].email); str2 = lower_string(str2);
                if(str1.compare(str2)>0) swap(user[i],user[j]);
            }
        }
        for(int i = 0; i < numOfUsers; i++)
        {
            cout << left << setw(idWidth) << setfill(separator) << user[i].id;
            cout << left << setw(nameWidth) << setfill(separator) << user[i].name;
            cout << left << setw(emailWidth) << setfill(separator) << user[i].email;
            cout << left << setw(phoneWidth) << setfill(separator) << user[i].phone;
            cout << left << setw(billWidth) << setfill(separator) << user[i].bill;
            cout << left << setw(serviceWidth) << setfill(separator) << user[i].service;
            cout << left << setw(addressWidth) << setfill(separator) << user[i].address;
            cout << endl;
        }
        cout << "--------------------------------\n";
        pressAnyKey();
        showMenu();
        break;
    case 2:
        fout.open("sort.txt");
        for(int i = 1; i < numOfUsers - 1; i++)
        {
            for(int j = i + 1; j < numOfUsers; j++)
            {
                str1 = delete_acom(user[i].email); str1 = lower_string(str1);              
                str2 = delete_acom(user[j].email); str2 = lower_string(str2);
                if(str1.compare(str2)>0) swap(user[i],user[j]);
            }
        }
        for(int i = 0; i < numOfUsers; i++)
        {
            fout << left << setw(idWidth) << setfill(separator) << user[i].id;
            fout << left << setw(nameWidth) << setfill(separator) << user[i].name;
            fout << left << setw(emailWidth) << setfill(separator) << user[i].email;
            fout << left << setw(phoneWidth) << setfill(separator) << user[i].phone;
            fout << left << setw(billWidth) << setfill(separator) << user[i].bill;
            fout << left << setw(serviceWidth) << setfill(separator) << user[i].service;
            fout << left << setw(addressWidth) << setfill(separator) << user[i].address;
            fout << endl;
        }
        fout.close();
        cout << "Data has been successfully transferred to sort.txt\n";
        pressAnyKey();
        showMenu();
        break;
    default:
        cout << "input invalid!!!";
        pressAnyKey();
        sortData_3_1();
        break;
    }
}

void sortData_3_2()
{
    system("cls");
    readFile();
    cout << "How would you like to see the result?\n";
    cout << "1.Print to the screen\n";
    cout << "2.Save to new file\n";
    cout << "Enter your choice: "; 
    int user_input; cin >> user_input;
    ofstream fout;
    string str1, str2;
    switch (user_input)
    {
    case 1:
        system("cls");
        for(int i = 1; i < numOfUsers - 1; i++)
        {
            for(int j = i + 1; j < numOfUsers; j++)
            {
                str1 = delete_acom(user[i].email); str1 = lower_string(str1);              
                str2 = delete_acom(user[j].email); str2 = lower_string(str2);
                if(str1.compare(str2)<0) swap(user[i],user[j]);
            }
        }
        for(int i = 0; i < numOfUsers; i++)
        {
            cout << left << setw(idWidth) << setfill(separator) << user[i].id;
            cout << left << setw(nameWidth) << setfill(separator) << user[i].name;
            cout << left << setw(emailWidth) << setfill(separator) << user[i].email;
            cout << left << setw(phoneWidth) << setfill(separator) << user[i].phone;
            cout << left << setw(billWidth) << setfill(separator) << user[i].bill;
            cout << left << setw(serviceWidth) << setfill(separator) << user[i].service;
            cout << left << setw(addressWidth) << setfill(separator) << user[i].address;
            cout << endl;
        }
        cout << "--------------------------------\n";
        pressAnyKey();
        showMenu();
        break;
    case 2:
        fout.open("sort.txt");
        for(int i = 1; i < numOfUsers - 1; i++)
        {
            for(int j = i + 1; j < numOfUsers; j++)
            {
                str1 = delete_acom(user[i].email); str1 = lower_string(str1);              
                str2 = delete_acom(user[j].email); str2 = lower_string(str2);
                if(str1.compare(str2)<0) swap(user[i],user[j]);
            }
        }
        for(int i = 0; i < numOfUsers; i++)
        {
            fout << left << setw(idWidth) << setfill(separator) << user[i].id;
            fout << left << setw(nameWidth) << setfill(separator) << user[i].name;
            fout << left << setw(emailWidth) << setfill(separator) << user[i].email;
            fout << left << setw(phoneWidth) << setfill(separator) << user[i].phone;
            fout << left << setw(billWidth) << setfill(separator) << user[i].bill;
            fout << left << setw(serviceWidth) << setfill(separator) << user[i].service;
            fout << left << setw(addressWidth) << setfill(separator) << user[i].address;
            fout << endl;
        }
        fout.close();
        cout << "Data has been successfully transferred to sort.txt\n";
        pressAnyKey();
        showMenu();
        break;
    default:
        cout << "input invalid!!!";
        pressAnyKey();
        sortData_3_2();
        break;
    }
}

void sortData_4()
{
    system("cls");
    cout << "Sort by phone\n";
    cout << "1.Ascending sort\n";
    cout << "2.Descending sort\n";
    cout << "Enter your choice: ";
    int user_input;
    cin >> user_input;
    switch (user_input)
    {
    case 1:
        system("cls");
        sortData_4_1();
        break;
    case 2:
        system("cls");
        sortData_4_2();
        break;
    default:
        cout << "input invalid!!!";
        pressAnyKey();
        sortData();
        break;
    }
    system("pause");
}

void sortData_4_1()
{
    system("cls");
    readFile();
    cout << "How would you like to see the result?\n";
    cout << "1.Print to the screen\n";
    cout << "2.Save to new file\n";
    cout << "Enter your choice: "; 
    int user_input; cin >> user_input;
    ofstream fout;
    switch (user_input)
    {
    case 1:
        system("cls");
        for(int i = 1; i < numOfUsers - 1; i++)
        {
            for(int j = i + 1; j < numOfUsers; j++)
            {
                if(user[i].phone.compare(user[j].phone)>0) swap(user[i],user[j]);
            }
        }
        for(int i = 0; i < numOfUsers; i++)
        {
            cout << left << setw(idWidth) << setfill(separator) << user[i].id;
            cout << left << setw(nameWidth) << setfill(separator) << user[i].name;
            cout << left << setw(emailWidth) << setfill(separator) << user[i].email;
            cout << left << setw(phoneWidth) << setfill(separator) << user[i].phone;
            cout << left << setw(billWidth) << setfill(separator) << user[i].bill;
            cout << left << setw(serviceWidth) << setfill(separator) << user[i].service;
            cout << left << setw(addressWidth) << setfill(separator) << user[i].address;
            cout << endl;
        }
        cout << "--------------------------------\n";
        pressAnyKey();
        showMenu();
        break;
    case 2:
        fout.open("sort.txt");
        for(int i = 1; i < numOfUsers - 1; i++)
        {
            for(int j = i + 1; j < numOfUsers; j++)
            {
                if(user[i].phone.compare(user[j].phone)>0) swap(user[i],user[j]);
            }
        }
        for(int i = 0; i < numOfUsers; i++)
        {
            fout << left << setw(idWidth) << setfill(separator) << user[i].id;
            fout << left << setw(nameWidth) << setfill(separator) << user[i].name;
            fout << left << setw(emailWidth) << setfill(separator) << user[i].email;
            fout << left << setw(phoneWidth) << setfill(separator) << user[i].phone;
            fout << left << setw(billWidth) << setfill(separator) << user[i].bill;
            fout << left << setw(serviceWidth) << setfill(separator) << user[i].service;
            fout << left << setw(addressWidth) << setfill(separator) << user[i].address;
            fout << endl;
        }
        fout.close();
        cout << "Data has been successfully transferred to sort.txt\n";
        pressAnyKey();
        showMenu();
        break;
    default:
        cout << "input invalid!!!";
        pressAnyKey();
        sortData_4_1();
        break;
    }
}

void sortData_4_2()
{
    system("cls");
    readFile();
    cout << "How would you like to see the result?\n";
    cout << "1.Print to the screen\n";
    cout << "2.Save to new file\n";
    cout << "Enter your choice: "; 
    int user_input; cin >> user_input;
    ofstream fout;
    switch (user_input)
    {
    case 1:
        system("cls");
        for(int i = 1; i < numOfUsers - 1; i++)
        {
            for(int j = i + 1; j < numOfUsers; j++)
            {
                if(user[i].phone.compare(user[j].phone)<0) swap(user[i],user[j]);
            }
        }
        for(int i = 0; i < numOfUsers; i++)
        {
            cout << left << setw(idWidth) << setfill(separator) << user[i].id;
            cout << left << setw(nameWidth) << setfill(separator) << user[i].name;
            cout << left << setw(emailWidth) << setfill(separator) << user[i].email;
            cout << left << setw(phoneWidth) << setfill(separator) << user[i].phone;
            cout << left << setw(billWidth) << setfill(separator) << user[i].bill;
            cout << left << setw(serviceWidth) << setfill(separator) << user[i].service;
            cout << left << setw(addressWidth) << setfill(separator) << user[i].address;
            cout << endl;
        }
        cout << "--------------------------------\n";
        pressAnyKey();
        showMenu();
        break;
    case 2:
        fout.open("sort.txt");
        for(int i = 1; i < numOfUsers - 1; i++)
        {
            for(int j = i + 1; j < numOfUsers; j++)
            {
                if(user[i].phone.compare(user[j].phone)<0) swap(user[i],user[j]);
            }
        }
        for(int i = 0; i < numOfUsers; i++)
        {
            fout << left << setw(idWidth) << setfill(separator) << user[i].id;
            fout << left << setw(nameWidth) << setfill(separator) << user[i].name;
            fout << left << setw(emailWidth) << setfill(separator) << user[i].email;
            fout << left << setw(phoneWidth) << setfill(separator) << user[i].phone;
            fout << left << setw(billWidth) << setfill(separator) << user[i].bill;
            fout << left << setw(serviceWidth) << setfill(separator) << user[i].service;
            fout << left << setw(addressWidth) << setfill(separator) << user[i].address;
            fout << endl;
        }
        fout.close();
        cout << "Data has been successfully transferred to sort.txt\n";
        pressAnyKey();
        showMenu();
        break;
    default:
        cout << "input invalid!!!";
        pressAnyKey();
        sortData_4_2();
        break;
    }
}

void sortData_5()
{
    system("cls");
    cout << "Sort by bill\n";
    cout << "1.Ascending sort\n";
    cout << "2.Descending sort\n";
    cout << "Enter your choice: ";
    int user_input;
    cin >> user_input;
    switch (user_input)
    {
    case 1:
        system("cls");
        sortData_5_1();
        break;
    case 2:
        system("cls");
        sortData_5_2();
        break;
    default:
        cout << "input invalid!!!";
        pressAnyKey();
        sortData();
        break;
    }
    system("pause");
}

void sortData_5_1()
{
    system("cls");
    readFile();
    cout << "How would you like to see the result?\n";
    cout << "1.Print to the screen\n";
    cout << "2.Save to new file\n";
    cout << "Enter your choice: "; 
    int user_input; cin >> user_input;
    ofstream fout;
    string str1, str2;
    switch (user_input)
    {
    case 1:
        system("cls");
        for(int i = 1; i < numOfUsers - 1; i++)
        {
            for(int j = i + 1; j < numOfUsers; j++)
            {
                if(compare_money(user[i].bill, user[j].bill)) swap(user[i],user[j]);
            }
        }
        for(int i = 0; i < numOfUsers; i++)
        {
            cout << left << setw(idWidth) << setfill(separator) << user[i].id;
            cout << left << setw(nameWidth) << setfill(separator) << user[i].name;
            cout << left << setw(emailWidth) << setfill(separator) << user[i].email;
            cout << left << setw(phoneWidth) << setfill(separator) << user[i].phone;
            cout << left << setw(billWidth) << setfill(separator) << user[i].bill;
            cout << left << setw(serviceWidth) << setfill(separator) << user[i].service;
            cout << left << setw(addressWidth) << setfill(separator) << user[i].address;
            cout << endl;
        }
        cout << "--------------------------------\n";
        pressAnyKey();
        showMenu();
        break;
    case 2:
        fout.open("sort.txt");
        for(int i = 1; i < numOfUsers - 1; i++)
        {
            for(int j = i + 1; j < numOfUsers; j++)
            {
                if(compare_money(user[i].bill, user[j].bill)) swap(user[i],user[j]);
            }
        }
        for(int i = 0; i < numOfUsers; i++)
        {
            fout << left << setw(idWidth) << setfill(separator) << user[i].id;
            fout << left << setw(nameWidth) << setfill(separator) << user[i].name;
            fout << left << setw(emailWidth) << setfill(separator) << user[i].email;
            fout << left << setw(phoneWidth) << setfill(separator) << user[i].phone;
            fout << left << setw(billWidth) << setfill(separator) << user[i].bill;
            fout << left << setw(serviceWidth) << setfill(separator) << user[i].service;
            fout << left << setw(addressWidth) << setfill(separator) << user[i].address;
            fout << endl;
        }
        fout.close();
        cout << "Data has been successfully transferred to sort.txt\n";
        pressAnyKey();
        showMenu();
        break;
    default:
        cout << "input invalid!!!";
        pressAnyKey();
        sortData_5_1();
        break;
    }
}

void sortData_5_2()
{
    system("cls");
    readFile();
    cout << "How would you like to see the result?\n";
    cout << "1.Print to the screen\n";
    cout << "2.Save to new file\n";
    cout << "Enter your choice: "; 
    int user_input; cin >> user_input;
    ofstream fout;
    string str1, str2;
    switch (user_input)
    {
    case 1:
        system("cls");
        for(int i = 1; i < numOfUsers - 1; i++)
        {
            for(int j = i + 1; j < numOfUsers; j++)
            {
                if(!compare_money(user[i].bill, user[j].bill)) swap(user[i],user[j]);
            }
        }
        for(int i = 0; i < numOfUsers; i++)
        {
            cout << left << setw(idWidth) << setfill(separator) << user[i].id;
            cout << left << setw(nameWidth) << setfill(separator) << user[i].name;
            cout << left << setw(emailWidth) << setfill(separator) << user[i].email;
            cout << left << setw(phoneWidth) << setfill(separator) << user[i].phone;
            cout << left << setw(billWidth) << setfill(separator) << user[i].bill;
            cout << left << setw(serviceWidth) << setfill(separator) << user[i].service;
            cout << left << setw(addressWidth) << setfill(separator) << user[i].address;
            cout << endl;
        }
        cout << "--------------------------------\n";
        pressAnyKey();
        showMenu();
        break;
    case 2:
        fout.open("sort.txt");
        for(int i = 1; i < numOfUsers - 1; i++)
        {
            for(int j = i + 1; j < numOfUsers; j++)
            {
                if(!compare_money(user[i].bill, user[j].bill)) swap(user[i],user[j]);
            }
        }
        for(int i = 0; i < numOfUsers; i++)
        {
            fout << left << setw(idWidth) << setfill(separator) << user[i].id;
            fout << left << setw(nameWidth) << setfill(separator) << user[i].name;
            fout << left << setw(emailWidth) << setfill(separator) << user[i].email;
            fout << left << setw(phoneWidth) << setfill(separator) << user[i].phone;
            fout << left << setw(billWidth) << setfill(separator) << user[i].bill;
            fout << left << setw(serviceWidth) << setfill(separator) << user[i].service;
            fout << left << setw(addressWidth) << setfill(separator) << user[i].address;
            fout << endl;
        }
        fout.close();
        cout << "Data has been successfully transferred to sort.txt\n";
        pressAnyKey();
        showMenu();
        break;
    default:
        cout << "input invalid!!!";
        pressAnyKey();
        sortData_5_2();
        break;
    }
}

void sortData_6()
{
    system("cls");
    cout << "Sort by service\n";
    cout << "1.Ascending sort\n";
    cout << "2.Descending sort\n";
    cout << "Enter your choice: ";
    int user_input;
    cin >> user_input;
    switch (user_input)
    {
    case 1:
        system("cls");
        sortData_6_1();
        break;
    case 2:
        system("cls");
        sortData_6_2();
        break;
    default:
        cout << "input invalid!!!";
        pressAnyKey();
        sortData();
        break;
    }
    system("pause");
}

void sortData_6_1()
{
    system("cls");
    readFile();
    cout << "How would you like to see the result?\n";
    cout << "1.Print to the screen\n";
    cout << "2.Save to new file\n";
    cout << "Enter your choice: "; 
    int user_input; cin >> user_input;
    ofstream fout;
    string str1, str2;
    switch (user_input)
    {
    case 1:
        system("cls");
        for(int i = 1; i < numOfUsers - 1; i++)
        {
            for(int j = i + 1; j < numOfUsers; j++)
            {
                str1 = lower_string(user[i].service);
                str2 = lower_string(user[j].service);
                if(str1.compare(str2)>0) swap(user[i],user[j]);
            }
        }
        for(int i = 0; i < numOfUsers; i++)
        {
            cout << left << setw(idWidth) << setfill(separator) << user[i].id;
            cout << left << setw(nameWidth) << setfill(separator) << user[i].name;
            cout << left << setw(emailWidth) << setfill(separator) << user[i].email;
            cout << left << setw(phoneWidth) << setfill(separator) << user[i].phone;
            cout << left << setw(billWidth) << setfill(separator) << user[i].bill;
            cout << left << setw(serviceWidth) << setfill(separator) << user[i].service;
            cout << left << setw(addressWidth) << setfill(separator) << user[i].address;
            cout << endl;
        }
        cout << "--------------------------------\n";
        pressAnyKey();
        showMenu();
        break;
    case 2:
        fout.open("sort.txt");
        for(int i = 1; i < numOfUsers - 1; i++)
        {
            for(int j = i + 1; j < numOfUsers; j++)
            {
                str1 = lower_string(user[i].service);
                str2 = lower_string(user[j].service);
                if(str1.compare(str2)>0) swap(user[i],user[j]);
            }
        }
        for(int i = 0; i < numOfUsers; i++)
        {
            fout << left << setw(idWidth) << setfill(separator) << user[i].id;
            fout << left << setw(nameWidth) << setfill(separator) << user[i].name;
            fout << left << setw(emailWidth) << setfill(separator) << user[i].email;
            fout << left << setw(phoneWidth) << setfill(separator) << user[i].phone;
            fout << left << setw(billWidth) << setfill(separator) << user[i].bill;
            fout << left << setw(serviceWidth) << setfill(separator) << user[i].service;
            fout << left << setw(addressWidth) << setfill(separator) << user[i].address;
            fout << endl;
        }
        fout.close();
        cout << "Data has been successfully transferred to sort.txt\n";
        pressAnyKey();
        showMenu();
        break;
    default:
        cout << "input invalid!!!";
        pressAnyKey();
        sortData_6_1();
        break;
    }
}

void sortData_6_2()
{
    system("cls");
    readFile();
    cout << "How would you like to see the result?\n";
    cout << "1.Print to the screen\n";
    cout << "2.Save to new file\n";
    cout << "Enter your choice: "; 
    int user_input; cin >> user_input;
    ofstream fout;
    string str1, str2;
    switch (user_input)
    {
    case 1:
        system("cls");
        for(int i = 1; i < numOfUsers - 1; i++)
        {
            for(int j = i + 1; j < numOfUsers; j++)
            {
                str1 = lower_string(user[i].service);
                str2 = lower_string(user[j].service);
                if(str1.compare(str2)<0) swap(user[i],user[j]);
            }
        }
        for(int i = 0; i < numOfUsers; i++)
        {
            cout << left << setw(idWidth) << setfill(separator) << user[i].id;
            cout << left << setw(nameWidth) << setfill(separator) << user[i].name;
            cout << left << setw(emailWidth) << setfill(separator) << user[i].email;
            cout << left << setw(phoneWidth) << setfill(separator) << user[i].phone;
            cout << left << setw(billWidth) << setfill(separator) << user[i].bill;
            cout << left << setw(serviceWidth) << setfill(separator) << user[i].service;
            cout << left << setw(addressWidth) << setfill(separator) << user[i].address;
            cout << endl;
        }
        cout << "--------------------------------\n";
        pressAnyKey();
        showMenu();
        break;
    case 2:
        fout.open("sort.txt");
        for(int i = 1; i < numOfUsers - 1; i++)
        {
            for(int j = i + 1; j < numOfUsers; j++)
            {
                str1 = lower_string(user[i].service);
                str2 = lower_string(user[j].service);
                if(str1.compare(str2)<0) swap(user[i],user[j]);
            }
        }
        for(int i = 0; i < numOfUsers; i++)
        {
            fout << left << setw(idWidth) << setfill(separator) << user[i].id;
            fout << left << setw(nameWidth) << setfill(separator) << user[i].name;
            fout << left << setw(emailWidth) << setfill(separator) << user[i].email;
            fout << left << setw(phoneWidth) << setfill(separator) << user[i].phone;
            fout << left << setw(billWidth) << setfill(separator) << user[i].bill;
            fout << left << setw(serviceWidth) << setfill(separator) << user[i].service;
            fout << left << setw(addressWidth) << setfill(separator) << user[i].address;
            fout << endl;
        }
        fout.close();
        cout << "Data has been successfully transferred to sort.txt\n";
        pressAnyKey();
        showMenu();
        break;
    default:
        cout << "input invalid!!!";
        pressAnyKey();
        sortData_6_2();
        break;
    }
}

void sortData_7()
{
    system("cls");
    cout << "Sort by address\n";
    cout << "1.Ascending sort\n";
    cout << "2.Descending sort\n";
    cout << "Enter your choice: ";
    int user_input;
    cin >> user_input;
    switch (user_input)
    {
    case 1:
        system("cls");
        sortData_7_1();
        break;
    case 2:
        system("cls");
        sortData_7_2();
        break;
    default:
        cout << "input invalid!!!";
        pressAnyKey();
        sortData();
        break;
    }
    system("pause");
}

void sortData_7_1()
{
    system("cls");
    readFile();
    cout << "How would you like to see the result?\n";
    cout << "1.Print to the screen\n";
    cout << "2.Save to new file\n";
    cout << "Enter your choice: "; 
    int user_input; cin >> user_input;
    ofstream fout;
    switch (user_input)
    {
    case 1:
        system("cls");
        for(int i = 1; i < numOfUsers - 1; i++)
        {
            for(int j = i + 1; j < numOfUsers; j++)
            {
                if(user[i].address.compare(user[j].address)>0) swap(user[i],user[j]);
            }
        }
        for(int i = 0; i < numOfUsers; i++)
        {
            cout << left << setw(idWidth) << setfill(separator) << user[i].id;
            cout << left << setw(nameWidth) << setfill(separator) << user[i].name;
            cout << left << setw(emailWidth) << setfill(separator) << user[i].email;
            cout << left << setw(phoneWidth) << setfill(separator) << user[i].phone;
            cout << left << setw(billWidth) << setfill(separator) << user[i].bill;
            cout << left << setw(serviceWidth) << setfill(separator) << user[i].service;
            cout << left << setw(addressWidth) << setfill(separator) << user[i].address;
            cout << endl;
        }
        cout << "--------------------------------\n";
        pressAnyKey();
        showMenu();
        break;
    case 2:
        fout.open("sort.txt");
        for(int i = 1; i < numOfUsers - 1; i++)
        {
            for(int j = i + 1; j < numOfUsers; j++)
            {
                if(user[i].address.compare(user[j].address)>0) swap(user[i],user[j]);
            }
        }
        for(int i = 0; i < numOfUsers; i++)
        {
            fout << left << setw(idWidth) << setfill(separator) << user[i].id;
            fout << left << setw(nameWidth) << setfill(separator) << user[i].name;
            fout << left << setw(emailWidth) << setfill(separator) << user[i].email;
            fout << left << setw(phoneWidth) << setfill(separator) << user[i].phone;
            fout << left << setw(billWidth) << setfill(separator) << user[i].bill;
            fout << left << setw(serviceWidth) << setfill(separator) << user[i].service;
            fout << left << setw(addressWidth) << setfill(separator) << user[i].address;
            fout << endl;
        }
        fout.close();
        cout << "Data has been successfully transferred to sort.txt\n";
        pressAnyKey();
        showMenu();
        break;
    default:
        cout << "input invalid!!!";
        pressAnyKey();
        sortData_7_1();
        break;
    }
}

void sortData_7_2()
{
    system("cls");
    readFile();
    cout << "How would you like to see the result?\n";
    cout << "1.Print to the screen\n";
    cout << "2.Save to new file\n";
    cout << "Enter your choice: "; 
    int user_input; cin >> user_input;
    ofstream fout;
    switch (user_input)
    {
    case 1:
        system("cls");
        for(int i = 1; i < numOfUsers - 1; i++)
        {
            for(int j = i + 1; j < numOfUsers; j++)
            {
                if(user[i].address.compare(user[j].address)<0) swap(user[i],user[j]);
            }
        }
        for(int i = 0; i < numOfUsers; i++)
        {
            cout << left << setw(idWidth) << setfill(separator) << user[i].id;
            cout << left << setw(nameWidth) << setfill(separator) << user[i].name;
            cout << left << setw(emailWidth) << setfill(separator) << user[i].email;
            cout << left << setw(phoneWidth) << setfill(separator) << user[i].phone;
            cout << left << setw(billWidth) << setfill(separator) << user[i].bill;
            cout << left << setw(serviceWidth) << setfill(separator) << user[i].service;
            cout << left << setw(addressWidth) << setfill(separator) << user[i].address;
            cout << endl;
        }
        cout << "--------------------------------\n";
        pressAnyKey();
        showMenu();
        break;
    case 2:
        fout.open("sort.txt");
        for(int i = 1; i < numOfUsers - 1; i++)
        {
            for(int j = i + 1; j < numOfUsers; j++)
            {
                if(user[i].address.compare(user[j].address)<0) swap(user[i],user[j]);
            }
        }
        for(int i = 0; i < numOfUsers; i++)
        {
            fout << left << setw(idWidth) << setfill(separator) << user[i].id;
            fout << left << setw(nameWidth) << setfill(separator) << user[i].name;
            fout << left << setw(emailWidth) << setfill(separator) << user[i].email;
            fout << left << setw(phoneWidth) << setfill(separator) << user[i].phone;
            fout << left << setw(billWidth) << setfill(separator) << user[i].bill;
            fout << left << setw(serviceWidth) << setfill(separator) << user[i].service;
            fout << left << setw(addressWidth) << setfill(separator) << user[i].address;
            fout << endl;
        }
        fout.close();
        cout << "Data has been successfully transferred to sort.txt\n";
        pressAnyKey();
        showMenu();
        break;
    default:
        cout << "input invalid!!!";
        pressAnyKey();
        sortData_7_2();
        break;
    }
}

void viewData()
{
    system("cls");
    readFile();
    for(int i=0;i<numOfUsers;i++)
    {
        cout << left << setw(idWidth) << setfill(separator) << user[i].id;
        cout << left << setw(nameWidth) << setfill(separator) << user[i].name;
        cout << left << setw(emailWidth) << setfill(separator) << user[i].email;
        cout << left << setw(phoneWidth) << setfill(separator) << user[i].phone;
        cout << left << setw(billWidth) << setfill(separator) << user[i].bill;
        cout << left << setw(serviceWidth) << setfill(separator) << user[i].service;
        cout << left << setw(addressWidth) << setfill(separator) << user[i].address;
        cout << endl;
    }
    cout << "--------------------------------\n";
    pressAnyKey();
    showMenu();
}

void advance()
{
    system("cls");
    cout << "Advance\n";
    cout << "1.Swap data position\n";
    cout << "2.Filter by bill\n";
    cout << "3.Return Menu\n";
    cout << "Enter your choice: ";
    int user_input;
    cin >> user_input;
    cin.ignore();
    switch (user_input)
    {
    case 1:
        system("cls");
        advance_1();
        break;
    case 2:
        system("cls");
        advance_2();
        break;    
    case 3:
        showMenu();
        break;
    default:
        cout << "input invalid!!!";
        pressAnyKey();
        advance();
        break;
    }
    system("pause");
}

void advance_1()
{
    system("cls");
    readFile();
    cout << "Select two user's id you want to swap:\n";
    cout << "First id: ";
    int input_id_1; cin >> input_id_1;
    cout << "Second id: ";
    int input_id_2; cin >> input_id_2;
    string tmp1 = user[input_id_1].id, tmp2 = user[input_id_2].id;
    swap(user[input_id_1], user[input_id_2]);
    user[input_id_1].id = tmp1; user[input_id_2].id = tmp2;
    updateFile();
    cout << "Data is updated successfully!\n";
    cout << "Do you want to continue? (Y/N): ";
    char c; cin >> c;
    cin.ignore();
    switch (c)
    {
    case 'Y':
        advance_1();
        break;
    case 'y':
        advance_1();
        break;
    default:
        showMenu();
        break;
    }
}

void advance_2()
{
    system("cls");
    readFile();
    cout << "Search data from bill money: ";
    string bill_min; getline(cin, bill_min);
    cout << "              to bill money: ";
    string bill_max; getline(cin, bill_max);
    bill_min = toMoney(bill_min);
    bill_max = toMoney(bill_max);
    string tmp, total_bill = "0";
    cout << "How would you like to see the result?\n";
    cout << "1.Print to the screen\n";
    cout << "2.Save to new file\n";
    cout << "Enter your choice: "; 
    int user_input; cin >> user_input;
    cin.ignore();
    ofstream fout;
    switch (user_input)
    {
    case 1:
        system("cls");
        for(int i = 0; i < numOfUsers; i++ ){
            tmp = toMoney(user[i].bill);
            if((compare_money(tmp, bill_min) && !compare_money(tmp, bill_max)) || i == 0)
            {
                if(i!=0) total_bill = bigSum(total_bill, tmp);
                cout << left << setw(idWidth) << setfill(separator) << user[i].id;
                cout << left << setw(nameWidth) << setfill(separator) << user[i].name;
                cout << left << setw(emailWidth) << setfill(separator) << user[i].email;
                cout << left << setw(phoneWidth) << setfill(separator) << user[i].phone;
                cout << left << setw(billWidth) << setfill(separator) << user[i].bill;
                cout << left << setw(serviceWidth) << setfill(separator) << user[i].service;
                cout << left << setw(addressWidth) << setfill(separator) << user[i].address;
                cout << endl;
            }
        }
        cout << "--------------------------------\n";
        total_bill = add_dot(total_bill);
        cout << "Total bill = " << total_bill << " VND\n";
        pressAnyKey();
        showMenu();
        break;
    case 2:
        system("cls");
        fout.open("filter.txt");
        for(int i = 0; i < numOfUsers; i++ ){
            tmp = toMoney(user[i].bill);
            if((compare_money(tmp, bill_min) && !compare_money(tmp, bill_max)) || i == 0)
            {
                if(i!=0) total_bill = bigSum(total_bill, tmp);
                fout << left << setw(idWidth) << setfill(separator) << user[i].id;
                fout << left << setw(nameWidth) << setfill(separator) << user[i].name;
                fout << left << setw(emailWidth) << setfill(separator) << user[i].email;
                fout << left << setw(phoneWidth) << setfill(separator) << user[i].phone;
                fout << left << setw(billWidth) << setfill(separator) << user[i].bill;
                fout << left << setw(serviceWidth) << setfill(separator) << user[i].service;
                fout << left << setw(addressWidth) << setfill(separator) << user[i].address;
                fout << endl;
            }
        }
        fout << "--------------------------------\n";
        total_bill = add_dot(total_bill);
        fout << "Total bill = " << total_bill << " VND\n";
        fout.close();
        cout << "Data has been successfully transferred to filter.txt\n";
        pressAnyKey();
        showMenu();
        break;
    default:
        cout << "input invalid!!!";
        pressAnyKey();
        advance_2();
        break;
    }
}
