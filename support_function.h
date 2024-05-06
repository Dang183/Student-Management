#include<iostream>
#include<string>
#include<conio.h>             
#include<stdlib.h>     
#include<algorithm>      

string lower_string(string str);   //bien chuoi bat ky thanh chuoi thuong
string delete_space(string str);   //xoa khoang trong sau chuoi ki tu
string delete_dot(string str);     //xoa dau cham
string delete_acom(string str);    //xoa a cong 
string name2first(string str);     //dua ten len truoc ho
string toMoney(string str);
string bigSum(string s1, string s2);
string add_dot(string str);
bool check_child_string(string strParent, string strChild);      //kiem tra chuoi con
bool compare_money(string str1, string str2);                    //so sanh 2 bill
void pressAnyKey(void);            //nhan phim bat ky de tiep tuc

string delete_space(string str)
{
    int i = str.size() - 1;
    while(str[i] == ' ') i--;
    return str.substr(0,i+1);
}

string lower_string(string str)
{
    for(int i = 0;i < str.size(); i++)
    {
        str[i] = tolower(str[i]);
    }
    return str;
}

string delete_dot(string str)
{
    string s = "";
    for(int i = 0;i < str.size(); i++)
    {
        if(str[i] == '.') continue;
        else s.push_back(str[i]);
    }
    return s;
}

string delete_acom(string str)
{
    string s = "";
    for(int i = 0;i < str.size(); i++)
    {
        if(str[i] == '@') str[i] = ' ';
        s.push_back(str[i]);
    }
    return s;
}

string name2first(string str)
{
    int n;
    for(int i = str.size() - 1; i>=0; i--)
    {
        if(str[i] == ' ')
        {
            n = i;
            break;
        }
    }
    string s = "";
    for(int i = n+1; i < str.size(); i++) s.push_back(str[i]);
    s += " ";
    for(int i = 0; i < n; i++) s.push_back(str[i]);
    return s;
}

string toMoney(string str){
    string s = "";
    for(int i = 0;i < str.size(); i++)
    {
        if(str[i] == ' ') break;
        else if(str[i] == '.') continue;
        else s.push_back(str[i]);
    }
    return s;
}

string bigSum(string s1, string s2)
{
    if(s1.size() < s2.size()) swap(s1,s2);
    int n1 = s1.size();
    int n2 = s2.size();
    reverse(s1.begin(),s1.end());
    reverse(s2.begin(),s2.end());
    int carry = 0, tmp;
    string res = "";
    for(int i=0;i<n2;i++){
        tmp = (s1[i] - '0') + (s2[i] - '0') + carry;
        carry = tmp / 10;
        res.push_back(tmp%10 + '0');
    }
    for(int i=n2;i<n1;i++){
        tmp = (s1[i] - '0') + carry;
        carry = tmp / 10;
        res.push_back(tmp%10 + '0');
    }
    if(carry > 0) res.push_back(carry + '0');
    reverse(res.begin(),res.end());
    return res;
}

string add_dot(string str)
{
    int check = 0;
    string s = "";
    for(int i=str.size() - 1; i >= 0; i--)
    {
        if(check == 3)
        {
            s.push_back('.');
            check = 0;
        } 
        s.push_back(str[i]);
        check++;
    }
    reverse(s.begin(),s.end());
    return s;
}

bool check_child_string(string strParent, string strChild)
{
    return (strParent.find(strChild) != string::npos)?true:false;
}

bool compare_money(string str1, string str2)
{
    if(str1.size() > str2.size()) return true;
    else if(str1.size() < str2.size()) return false;
    else 
    {
        if(str1.compare(str2)>0) return true;
        else return false;
    }
}

void pressAnyKey() 
{
    cout << "\n\nPress any key to continue...";
    getch();
    system("cls");
}
