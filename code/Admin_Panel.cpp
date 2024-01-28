#include<stdio.h>
#include<fstream>
#include<conio.h>
#include<iostream>
#include<string.h>
#include<iomanip>
#include"conio2.h"
int main();
void box(int row,int col,int endrow,int endcol,int color);
using namespace std;
class Admin
{
public:
    int Bus_id;
    char bus_no[10];
    int distance;
    char starting_dest[15];
    char starting_time[10];
    char end_dest[15];
    char end_time[10];
    float fare;
    int n_seats;

    void add_bus();
    void view_all_bus();
    void search_bus();
    void show_data();
    void update_bus();
};
class User_ticket : public Admin
{
public:
    char User_name[20];
    int user_age;
    char user_gender;
    char User_Address[30];
    char User_phoneno[10];
    void show_user_data();

    void Book_user_ticket(Admin );
    void view_revenue();
};
void admin_panel() // admin function should be called by main
{
        int ch;
    do
    {
        textcolor(WHITE);
        textbackground(BLACK);
        system("cls");
        box(2,30,4,94,LIGHTBLUE);
        gotoxy(46,3);
        cout<<"Group 'A' Bus Depot ";
        box(6,24,17,100,GREEN);
        gotoxy(34,7);
        cout<<"1. Add bus";
        gotoxy(34,8);
        cout<<"2. View all bus";
        gotoxy(34,9);
        cout<<"3. Search bus";
        gotoxy(34,10);
        cout<<"4. Update bus";
        gotoxy(34,11);
        cout<<"5. View total bookings ";
        gotoxy(34,12);
        cout<<"6. View total revenue ";
        gotoxy(34,13);
        cout<<"7. Main menu ";
        gotoxy(34,15);
        cout<<"Enter your choice : ";
        cin>>ch;
        Admin a;
        User_ticket c;
        switch(ch)
        {
        case 1:
            a.add_bus();
            break;
        case 2:
            a.view_all_bus();
            break;
        case 3:
            a.search_bus();
            break;
        case 4:
            a.update_bus();
            break;
        case 5:
            c.show_user_data();
            break;
        case 6:
            c.view_revenue();
            break;
        case 7:
            textbackground(BLACK);
            textcolor(WHITE);
            main();
            break;
        }
            textbackground(BLACK);
            textcolor(WHITE);
    }while(ch!=0);
    textcolor(WHITE);
    textbackground(BLACK);
    system("cls");
}
void Admin::add_bus() // function for adding new bus
{
     textcolor(WHITE);
    textbackground(BLACK);
    system("cls");
    box(2,30,4,94,MAGENTA);
    gotoxy(46,3);
    cout<<"Function For Adding New Bus ";
    ofstream in("busfile.txt",ios::app);
    box(6,24,20,100,LIGHTRED);
    gotoxy(32,7);
    cout<<"Enter Bus id : ";
    cin>>Bus_id;
    gotoxy(32,8);
    cout<<"Enter bus Number : ";
    fflush(stdin);
    gets(bus_no);
    gotoxy(32,9);
    cout<<"Enter starting destination  : ";
    fflush(stdin);
    gets(starting_dest);
    gotoxy(32,10);
    cout<<"Enter Ending destination :  ";
    fflush(stdin);
    gets(end_dest);
    gotoxy(32,11);
    cout<<"Enter starting time :  ";
    fflush(stdin);
    gets(starting_time);
    gotoxy(32,12);
    cout<<"Enter Reaching time :  ";
    fflush(stdin);
    gets(end_time);
    gotoxy(32,13);
    cout<<"Enter total distance Bus will cover (in km) :  ";
    cin>>distance;
    gotoxy(32,14);
    cout<<"Enter Bus fare :  ";
    cin>>fare;
    gotoxy(32,15);
    cout<<"Enter number of seats :  ";
    cin>>n_seats;
    in.write((char*)this,sizeof(Admin));
    in.close();
    textcolor(WHITE);
    textbackground(BLACK);
    system("cls");
}
void Admin::view_all_bus() // for viewing all bus in list view
{
    textcolor(WHITE);
    textbackground(BLACK);
    system("cls");
    box(2,30,4,94,MAGENTA);
    gotoxy(45,3);
    cout<<"Showing All Buses ";
    ifstream in("busfile.txt");
    in.seekg(0);
    box(6,10,20,114,YELLOW);
    textcolor(BLACK);
    int i=7;
    gotoxy(12,i);
    cout<<setiosflags(ios::left)<<setw(10)<<"Bus Id "<<setw(13)<<"Bus No. "<<setw(14)<<"From "<<setw(14)<<"To "<<setw(14)<<"Start Time"<<setw(14)<<"Reach Time"<<setw(10)<<"fare "<<setw(13)<<"Seats Avail.";
    while(in.read((char*)this,sizeof(Admin)))
    {
        i=i+2;
        gotoxy(12,i);
        textcolor(RED);
        cout<<setiosflags(ios::left)<<setw(10)<<Bus_id<<setw(13)<<bus_no<<setw(14)<<starting_dest<<setw(14)<<end_dest<<setw(14)<<starting_time<<setw(14)<<end_time<<setw(10)<<fare<<setw(13)<<n_seats;
    }
    getch();
    in.close();
    textcolor(WHITE);
    textbackground(BLACK);
    system("cls");
}
void Admin::show_data()  // all in one function for showing data
{
    textcolor(WHITE);
    textbackground(BLACK);
    system("cls");
    box(2,30,4,94,MAGENTA);
    gotoxy(40,3);
    cout<<"Bus Information ";
    box(6,24,16,100,YELLOW);
    textcolor(RED);
    gotoxy(30,7);
    cout<<"Bus Id : "<<Bus_id;
    gotoxy(30,8);
    cout<<"Bus Number : "<<bus_no;
    gotoxy(30,9);
    cout<<"Starting Destination : "<<starting_dest;
    gotoxy(30,10);
    cout<<"Starting Time : "<<starting_time;
    gotoxy(30,11);
    cout<<"Ending Destination : "<<end_dest;
    gotoxy(30,12);
    cout<<"Ending Time : "<<end_time;
    gotoxy(30,13);
    cout<<"Distance : "<<distance;
    gotoxy(30,14);
    cout<<"Total fare : "<<fare;
    gotoxy(30,15);
    cout<<"Number of seats : "<<n_seats;
    getch();
}
void Admin::search_bus() // function for searching bus by id and bus number
{
    textcolor(WHITE);
    textbackground(BLACK);
    system("cls");
    box(2,36,4,88,BLUE);
    gotoxy(45,3);
    cout<<"Search Bus ";
     int id,flag=0;
   box(6,24,10,100,YELLOW);
   textcolor(BLACK);
   gotoxy(34,8);
   cout<<"Enter Bus id : ";
   cin>>id;
    ifstream inf("busfile.txt");
    while(inf.read((char*)this,sizeof(Admin)))
    {
        if(id==Bus_id)
        {
            show_data();
            flag=1;
        }
    }
    if(flag==0)
    {
        box(12,40,15,84,RED);
        textcolor(WHITE);
        gotoxy(44,13);
        cout<<"The Id you Entered does not exist ";
        gotoxy(44,14);
        cout<<"Press any key to continue ";
        getch();
    }
    textcolor(WHITE);
    textbackground(BLACK);
    system("cls");
}
void Admin::update_bus()
{
    textcolor(WHITE);
    textbackground(BLACK);
    system("cls");
    int id,uch,flag=0;
    box(2,36,4,88,LIGHTCYAN);
    gotoxy(38,3);
    textcolor(BLACK);
    cout<<"Enter Bus id which you want to update : ";
    cin>>id;
    fstream fin("busfile.txt",ios::in|ios::out|ios::ate);
    fin.seekg(0);
    while(fin.read((char*)this,sizeof(Admin)))
    {
        if(id==Bus_id)
        {
            box(6,24,24,100,MAGENTA);
            textcolor(WHITE);
            gotoxy(34,7);
            cout<<"Enter what do you want to update : ";
            gotoxy(40,8);
            cout<<"1. Bus id ";
            gotoxy(40,9);
            cout<<"2. Bus number ";
            gotoxy(40,10);
            cout<<"3. distance covered ";
            gotoxy(40,11);
            cout<<"4. Starting destination ";
            gotoxy(40,12);
            cout<<"5. Ending destination ";
            gotoxy(40,13);
            cout<<"6. Starting time ";
            gotoxy(40,14);
            cout<<"7. Ending time ";
            gotoxy(40,15);
            cout<<"8. fare ";
            gotoxy(40,16);
            cout<<"9. Number of seats ";
            gotoxy(40,18);
            cout<<"Enter your choice :  ";
            cin>>uch;
            box(20,40,20,84,RED);
            gotoxy(44,20);
            if(uch==1)
            {
                cout<<"Enter new Bus id  :  ";
                cin>>Bus_id;
            }
            else if(uch==2)
            {
                fflush(stdin);
                cout<<"Enter new Bus Number :  ";
                gets(bus_no);
            }
            else if(uch==3)
            {
                cout<<"Enter new Distance bus has to travel ";
                cin>>distance;
            }
            else if(uch==4)
            {
                fflush(stdin);
                cout<<"Enter new Starting destination :  ";
                gets(starting_dest);
            }
            else if(uch==5)
            {
                fflush(stdin);
                cout<<"Enter new Ending destination : ";
                gets(end_dest);
            }
            else if(uch==6)
            {
                fflush(stdin);
                cout<<"Enter new Starting time of bus : ";
                gets(starting_time);
            }
            else if(uch==7)
            {
                fflush(stdin);
                cout<<"Enter new Ending time of bus : ";
                gets(end_time);
            }
            else if(uch==8)
            {
                cout<<"Enter the updated fare of bus :  ";
                cin>>fare;
            }
            else if(uch==9)
            {
                cout<<"Enter The updated number of seats : ";
                cin>>n_seats;
            }
            else
            {
                flag=1;
                break;
            }
                 flag=1;
                 fin.seekp(fin.tellp()- sizeof(Admin));
                 fin.write((char *)this,sizeof(Admin));
                 box(22,46,22,78,GREEN);
                 gotoxy(48,22);
                 cout<<"Data is successfully Updated";
                 break;
        }
    }
     if(flag==0)
     {
            box(8,40,8,84,RED);
            gotoxy(44,8);
            textcolor(WHITE);
            cout<<"Bus Id "<<id<<" is not found!!";
            gotoxy(44,10);
        cout<<"Press any key to continue...";
     }
        fin.close();
        getch();
}
void User_ticket::view_revenue()
{
    textcolor(WHITE);
    textbackground(BLACK);
    system("cls");
    ifstream in("ticket.txt");
    float rev=0.0;
    while(in.read((char*)this,sizeof(User_ticket)))
    {
        rev=rev+fare;
    }
    box(5,30,9,94,BLUE);
    gotoxy(34,7);
    textcolor(YELLOW);
    cout<<"Total revenue generated Till today : "<<rev;
    getch();
    in.close();
    textcolor(WHITE);
    textbackground(BLACK);
    system("cls");
}
