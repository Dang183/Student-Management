#include<iostream>
#include<conio.h> 
#include<windows.h>

using namespace std;

void mainPage(void);                //giao dien trang chu
void loadingBar(void);              //thanh loading 
void logScreen(void);               //dang nhap tai khoan
void exitProgram(void);             //thoat chuong trinh

void mainPage()
{
    system("cls");
    cout << "\n";
    cout << "\t\t\t\t    ---------------------------------\n";
    cout << "\t\t\t\t    |ASSIGNMENT COMPUTER PROGRAMMING|\n";
    cout << "\t\t\t\t    ---------------------------------\n";
    cout << "\n\n\n";
    cout << "\t\t\t\t";
    cout << "Made By        ";
    cout << ":";
    cout << "   Nguyen Hai Dang";
    cout << "\n\n";
    cout << "\t\t\t\t";
    cout << "Assignment     ";
    cout << ":";
    cout << "   Data Management System";
    cout << "\n\n";
    cout << "\t\t\t\t";
    cout << "Lecturer       ";
    cout << ":";
    cout << "   Mr.Trung Anh";
    cout << "\n\n";
    cout << "\t\t\t\t    Press Enter to continue......";
    cout << "\n\n";
    getch();
}

void loadingBar()
{
	
	char a = 177, b = 219;

	cout << "\n\n\n\t\t\t\t\tLoading...\n";
	cout << endl;
	cout << "\t\t\t\t\t";
	
	for(int i = 0;i<26;i++) cout<<a;

	cout << "\r";
	cout << "\t\t\t\t\t";
	for(int i = 0; i < 26 ; i++)
	{
		cout<<b;
		Sleep(200);
	}
	
}

void logScreen()
{
    system("cls");
    string account;
    string password;
    int check = 1;
    do
    {
        system("cls");
        cout << "\n\n\n\n\n\n\n\n\n\n";
        cout << "\t\t\t\t\t";
        cout << "Username: "; cin >> account;
        cout << "\t\t\t\t\t";
        cout << "\n";
        cout << "\t\t\t\t\t";
        cout << "Password: "; cin >> password;
        if(account.compare("admin") == 0 && password.compare("12345678") == 0)
        {
            cout << "\n\n";
            cout << "\t\t\t\t\t";
            cout << "You are accessed to the system!\n\n";
            loadingBar();
            check = 0;
        }else{
            cout << "\n\n";
            cout << "\t\t\t\t\t";
            cout << "Wrong account or password!!!\n";
            cout << "\t\t\t\t\t";
            cout << "Please login again.";
            getch();
        }
    } while (check);
}

void exitProgram()
{
    system("cls");
    cout << "\t\t\n\n\n\n\n\n\n\t\t\t\t\tQuitting The Program";

    for (int i = 0; i < 4; i++)
    {
        Sleep(1000); 
        cout << ".";
    }
    
    exit(0);
}