#include <iostream>
#include<stdio.h>
#include<fstream>
#include<conio.h>
#include"conio2.h"
using namespace std;
string admin_usr = "Admin";
string admin_pass="Admin@123";
string usn;
int tm;
void valid(string);
void login();
void admin_panel();
void user_panel();
void login()
{
    int choice,i,exit=0;
    string ans,psd,name,fname,bio,usern,pw,line,nusn;
    ofstream fileo;
    ifstream filei;
    //cout<<"----------------------------------------------Welcome to our system!------------------------------------------------------\n";
    while(exit==0)
    {
        cout<<"\nChoose one option:\n1. SignIn/LogIn(press 1 to select this)\n2. SignUp/Register(press 2 to select this)\n\npress any key and enter to exit\n";
        cin>>choice;
        if(choice==1)
        {
            cout<<"Enter your username:";
            cin>>usn;
            cout<<"\nEnter your password:";
            cin>>psd;
            fname=usn+".txt";
            filei.open(fname.c_str());
            if(!filei.is_open() && filei.fail())
            {
                cout<<"\nYou are not registered, please register before logging in.\n";
                filei.close();
                continue;
            }
            getline(filei,usern);
            getline(filei,line);
            getline(filei,pw);
            if(usn==usern && psd==pw)
            {
                cout<<"\nYou are successfully logged in :)";
                user_panel();
            }
            else{
                cout<<"\nWrong username or password!\nPlease try Again.\n";
            }
            cout<<endl;
        }
        else if(choice==2)
        {
            cout<<"\nEnter your name:";
            cin.ignore();
            getline(cin,name);
            cout<<"\nCreate a username:";
            cin>>usn;
            tm=0;
            valid(usn);
            if(tm>=3)
            {
                continue;
            }
            cout<<"\nCreate a password:";
            cin>>psd;
            fname=usn+".txt";
            //cout<<fname;
            fileo.open(fname.c_str());
            fileo<<usn<<endl<<name<<endl<<psd<<endl;
            cout<<"\nYou are successfully registered:)";
            //cout<<"\nAdd to your bio and press enter when you are done:";
            //cin.ignore();
            //getline(cin,bio);
            //fileo<<bio<<endl;
            //cout<<"\nYour bio is saved as: "<<bio;
            fileo.close();
        }
        else
        {
            exit=1;
        }
    }
    //cout<<"\n----------------------------------------------Thank you for visiting:)----------------------------------------------------\n";
}
void valid(string str)
{
    string dir,user;
    ifstream file;
    dir = str+".txt";
    file.open(dir.c_str());
    if(!file.is_open() && file.fail())
    {
        //file.close();
        return;
    }
    else
    {
        tm++;
        if(tm==3)
        {
            cout<<"\nThis username already exists\nPlease try Again.";
            //file.close();
            return;
        }
        cout<<"\nThis username already exists!\nCreate a username:";
        cin>>usn;
        //file.close();
        valid(usn);
    }
}



void box(int row,int col,int endrow,int endcol,int color)
{
    int i,j;
    for( i=row;i<=endrow;i++)
    {
        for(j=col;j<=endcol;j++)
        {
            gotoxy(j,i);
            textbackground(color);
            printf(" ");
        }
    }
}

int main()
{
    string ausrn, apass;
    system("cls");
    textcolor(WHITE);
    textbackground(BLACK);
    box(3,30,5,94,YELLOW);
    gotoxy(45,4);
    textcolor(RED);
    cout<<"Tourism Management System";
    int ch;
    textcolor(WHITE);
    do
    {
            box(7,24,11,100,MAGENTA);
            gotoxy(34,8);
            cout <<"1. Admin Panel\t\t\t 2. User Panel";
            gotoxy(34,10);
            cout<<"Enter your choice : ";
            cin>>ch;
            switch(ch)
            {
            case 1:
                cout<<"\n\n\nEnter the UserName of the admin : ";
                cin>>ausrn;
                cout<<"Enter the Password of the admin : ";
                cin>>apass;
                if (ausrn==admin_usr & apass==admin_pass){
                    admin_panel();
                }
                else{
                    cout<<"Wrong Username or Password !"<<endl;
                    getch();
                    system("cls");
                }
                break;
            case 2:
                login();
                break;
            default:
                box(13,40,13,84,RED);
                gotoxy(44,13);
                cout<<"!!!!   Enter valid choice ";
                exit(0);
            }
    }while(ch!=0);
    return 0;
}
