#include<stdio.h>
#include<fstream>
#include<conio.h>
#include<iostream>
#include<string.h>
#include"conio2.h"
#include<iomanip>
void box(int row,int col,int endrow,int endcol,int color);
int main();
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
    void view_all_bus_x();
    void search_route_bus();
    void view_bus();
};
void Admin::view_all_bus_x() // for viewing all bus in list view
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

};
void user_panel()
{
    textbackground(BLACK);
    textcolor(WHITE);
    system("cls");
    int ch;
    Admin x;
    do
    {
        box(3,30,5,94,GREEN);
        gotoxy(55,4);
        cout<<"Group 'A' Bus Depot ";
        box(7,24,13,100,BROWN);
        gotoxy(34,8);
        textcolor(BLACK);
        cout<<"1. Bus Tours Brochure";
        gotoxy(34,9);
        cout<<"2. Search Bus";
        gotoxy(34,10);
        cout<<"3. View your bookings";
        //gotoxy(34,12);
        cout<<"\n\t\t\t\t 4. Main menu";
        gotoxy(34,13);
        cout<<"Enter your choice : ";
        cin>>ch;
        Admin a;
        User_ticket c;
        switch(ch)
        {
        case 1:
            a.view_all_bus_x();
            break;
        case 2:
            a.search_route_bus();
            break;
        case 3:
            c.show_user_data();
            break;
        case 4:
            main();
            break;
        }
    }while(ch!=0);
    textcolor(WHITE);
    textbackground(BLACK);
    system("cls");
}
void Admin::search_route_bus()
{
    textcolor(WHITE);
    textbackground(BLACK);
    system("cls");
    int id,flag=0,bookchoice;
    char start[10],ending[10],time[10];
    User_ticket c;
    Admin a;
    ifstream fin("busfile.txt");
    box(3,30,5,94,MAGENTA);
    gotoxy(40,3);
    cout<<"********************************************";
    gotoxy(54,4);
    cout<<"searching bus panel \n";
    gotoxy(40,5);
    cout<<"*********************************************";
    box(7,24,13,100,CYAN);
    gotoxy(30,8);
    cout<<"1. Search by bus id ";
    gotoxy(30,9);
    cout<<"2. Search by route ";
    gotoxy(30,10);
    cout<<"3. Search by time ";
    int choice;
    gotoxy(30,12);
    cout<<"Enter your choice : ";
    cin>>choice;
    textcolor(WHITE);
    textbackground(BLACK);
    system("cls");
    box(2,24,4,100,LIGHTRED);
    int i=7;
    switch(choice)
    {
        case 1:
            gotoxy(34,3);
            cout<<"Enter Id by which you want to search bus :  ";
            cin>>id;
            while(fin.read((char*)&a,sizeof(a)))
            {
                if(id==a.Bus_id)
                {
                    box(6,10,20,114,YELLOW);
                    textcolor(RED);
                    gotoxy(12,i);
                    if(i==7)
                    cout<<setiosflags(ios::left)<<setw(10)<<"Bus Id "<<setw(13)<<"Bus No. "<<setw(14)<<"From "<<setw(14)<<"To "<<setw(14)<<"Start Time"<<setw(14)<<"Reach Time"<<setw(10)<<"fare "<<setw(13)<<"Seats Avail.";
                    gotoxy(12,i+2);
                    cout<<setiosflags(ios::left)<<setw(10)<<a.Bus_id<<setw(13)<<a.bus_no<<setw(14)<<a.starting_dest<<setw(14)<<a.end_dest<<setw(14)<<a.starting_time<<setw(14)<<a.end_time<<setw(10)<<a.fare<<setw(13)<<a.n_seats;
                    flag=1;
                    gotoxy(34,18);
                    cout<<"Do you want to book ticket ( 1 -yes | 0 -Main menu)s : ";
                        cin>>bookchoice;
                        if(bookchoice==0)
                            break;
                    c.Book_user_ticket(a);
                }
            }
            if(flag==0)
            {
                box(8,40,12,84,RED);
                gotoxy(44,9);
                cout<<"The id You have entered does not exist ";
                gotoxy(44,11);
                cout<<"Press any key to continue  ";
                getch();
                user_panel();
            }
            break;
        case 2:
            box(1,24,1,100,LIGHTRED);
            gotoxy(34,2);
            cout<<"Enter your starting destination :  ";
            fflush(stdin);
            gets(start);
            gotoxy(34,3);
            cout<<"Enter your Ending destination :  ";
            gets(ending);
            while(fin.read((char*)&a,sizeof(a)))
            {
                if(strcmp(a.starting_dest,start)==0)
                {
                    if(strcmp(a.end_dest,ending)==0)
                    {
                        box(6,10,20,114,YELLOW);
                        textcolor(RED);
                        gotoxy(12,i);
                        if(i==7)
                        cout<<setiosflags(ios::left)<<setw(10)<<"Bus Id "<<setw(13)<<"Bus No. "<<setw(14)<<"From "<<setw(14)<<"To "<<setw(14)<<"Start Time"<<setw(14)<<"Reach Time"<<setw(10)<<"fare "<<setw(13)<<"Seats Avail.";
                        gotoxy(12,i+2);
                        cout<<setiosflags(ios::left)<<setw(10)<<a.Bus_id<<setw(13)<<a.bus_no<<setw(14)<<a.starting_dest<<setw(14)<<a.end_dest<<setw(14)<<a.starting_time<<setw(14)<<a.end_time<<setw(10)<<a.fare<<setw(13)<<a.n_seats;
                        flag=1;
                        gotoxy(34,18);
                        cout<<"Do you want to book ticket ( 1 -yes | 0 -Main menu) : ";
                        cin>>bookchoice;
                        if(bookchoice==0)
                            break;
                        c.Book_user_ticket(a);
                    }
                }
            }
            if(flag==0)
            {
                box(8,30,12,94,RED);
                gotoxy(36,9);
                cout<<"We do not have Bus for the route you are entering ";
                gotoxy(36,11);
                cout<<"Press any key to continue ";
                getch();
                user_panel();
            }
            break;
        case 3:
            gotoxy(34,3);
            cout<<"Enter timing at which you want to board bus :  ";
            fflush(stdin);
            gets(time);
            while(fin.read((char*)&a,sizeof(a)))
            {
                if(strcmp(a.starting_time,time)==0)
                {
                    box(6,10,20,114,YELLOW);
                        textcolor(RED);
                        gotoxy(12,i);
                        if(i==7)
                        cout<<setiosflags(ios::left)<<setw(10)<<"Bus Id "<<setw(13)<<"Bus No. "<<setw(14)<<"From "<<setw(14)<<"To "<<setw(14)<<"Start Time"<<setw(14)<<"Reach Time"<<setw(10)<<"fare "<<setw(13)<<"Seats Avail.";
                        gotoxy(12,i+2);
                        cout<<setiosflags(ios::left)<<setw(10)<<a.Bus_id<<setw(13)<<a.bus_no<<setw(14)<<a.starting_dest<<setw(14)<<a.end_dest<<setw(14)<<a.starting_time<<setw(14)<<a.end_time<<setw(10)<<a.fare<<setw(13)<<a.n_seats;
                        flag=1;
                        gotoxy(34,18);
                    cout<<"Do you want to book ticket ( 1 -yes | 0 -Main menu) : ";
                        cin>>bookchoice;
                        if(bookchoice==0)
                            break;
                    c.Book_user_ticket(a);
                }
            }
            if(flag==0)
            {
                box(8,40,12,84,RED);
                gotoxy(44,9);
                cout<<"We do not have Bus any bus at this timing ";
                gotoxy(44,11);
                cout<<"Press any key to continue ";
                getch();
                user_panel();
            }
            break;
        default:
            cout<<"\n\nEnter valid option ";
            getch();
            user_panel();
    }
    textcolor(WHITE);
    textbackground(BLACK);
    system("cls");
}
void User_ticket::Book_user_ticket(Admin a)
{
    textcolor(WHITE);
    textbackground(BLACK);
    system("cls");
    box(2,30,4,94,LIGHTBLUE);
    gotoxy(40,3);
    cout<<"Input form for booking ticket ";
    ofstream in("ticket.txt",ios::app);
    box(6,24,13,100,MAGENTA);
    gotoxy(30,7);
    cout<<"Enter your name : ";
    fflush(stdin);
    gets(User_name);
    gotoxy(30,8);
    cout<<"Enter your age :  ";
    cin>>user_age;
    gotoxy(30,9);
    cout<<"Enter your gender :  ";
    cin>>user_gender;
    gotoxy(30,10);
    cout<<"Enter your address :  ";
    fflush(stdin);
    gets(User_Address);
    gotoxy(30,11);
    cout<<"Enter your contact details : ";
    gets(User_phoneno);
    Bus_id=a.Bus_id;
    strcpy(bus_no,a.bus_no);
    strcpy(starting_dest,a.starting_dest);
    strcpy(starting_time,a.starting_time);
    strcpy(end_dest,a.end_dest);
    strcpy(end_time,a.end_time);
    fare=a.fare;
    in.write((char*)this,sizeof(User_ticket));
    in.close();
    box(15,40,15,84,GREEN);
    gotoxy(44,15);
    cout<<"CONGRATS !! YOU GOT A TICKET";
    getch();
    textcolor(WHITE);
    textbackground(BLACK);
    system("cls");
}
void User_ticket::show_user_data()
{
    textcolor(WHITE);
    textbackground(BLACK);
    system("cls");
    box(2,30,4,94,LIGHTRED);
    gotoxy(40,3);
    cout<<"Showing booking for Group 'A' Bus Depot ";
    ifstream in("ticket.txt");
    int i=6,cnt=1;
    while(in.read((char*)this,sizeof(User_ticket)))
    {
        box(i,24,i+17,100,LIGHTMAGENTA);
        box(i+1,50,i+1,74,RED);
        gotoxy(60,i+1);
        cout<<"DATA "<<cnt;
        textbackground(LIGHTMAGENTA);
        gotoxy(30,i+3);
        cout<<"Customer Name :  "<<User_name;
        gotoxy(30,i+4);
        cout<<"Customer Age :  "<<user_age;
        gotoxy(30,i+5);
        cout<<"Gender :  "<<user_gender;
        gotoxy(30,i+6);
        cout<<"Customer phone No. :  "<<User_phoneno;
        gotoxy(30,i+7);
        cout<<"Customer Address :  "<<User_Address;
        gotoxy(30,i+8);
        cout<<"Bus Id :  "<<Bus_id;
        gotoxy(30,i+9);
        cout<<"Bus No. :  "<<bus_no;
        gotoxy(30,i+10);
        cout<<"Starting Destination :  "<<starting_dest;
        gotoxy(30,i+11);
        cout<<"Ending Destination :  "<<end_dest;
        gotoxy(30,i+12);
        cout<<"Starting time :  "<<starting_time;
        gotoxy(30,i+13);
        cout<<"Ending time :  "<<end_time;
        gotoxy(30,i+14);
        cout<<"Total Fare :  "<<fare;
        cnt++;
        getch();
    }
    getch();
    in.close();
    textcolor(WHITE);
    textbackground(BLACK);
    system("cls");
}
