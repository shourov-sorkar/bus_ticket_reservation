#include <bits/stdc++.h>
#include<conio.h>
#include<windows.h>
using namespace std;
typedef struct{
	char name[50];
	int bus_num;
	int num_of_seats;
}pd;
void reservation(void);
void viewdetails(void);
void printticket(char name[],int,int,float);
void specifictrain(int);
float charge(int,int);
void login();

int main()
{
    cout<<"\n";
    cout<<"\n";
    cout<<"\n";
    cout<<"\n";
    cout<<"\n";
    cout<<"\n";
    cout<<"\n";
    cout<<"\n";
    cout<<"\n";
    cout<<"\n";
    cout<<"\n";
    cout<<"\t";cout<<"\t";cout<<"\t";cout<<"\t";cout<<"\t";
    cout<<"B"; Sleep(200); cout<<"U"; Sleep(200);cout<<"S"; Sleep(200);cout<<" "; cout<<"T"; Sleep(200);cout<<"I"; Sleep(200);cout<<"C"; Sleep(200);cout<<"K"; Sleep(30);
    cout<<"E"; Sleep(30);cout<<"T"; Sleep(200);cout<<" "; cout<<"R"; Sleep(200);cout<<"E"; Sleep(200);cout<<"S"; Sleep(200);cout<<"E"; Sleep(200);
    cout<<"R"; Sleep(200);cout<<"V"; Sleep(200);cout<<"A"; cout<<"T"; Sleep(200);cout<<"I"; Sleep(200);cout<<"O"; Sleep(200);cout<<"N"; Sleep(200);
    cout<<" "; Sleep(200);cout<<"S"; Sleep(200);cout<<"Y"; cout<<"S"; Sleep(200);cout<<"T"; Sleep(200);cout<<"E"; Sleep(200); cout<<"M"; Sleep(200);
    cout<<"\n";
    cout<<"\n";
    cout<<"\n";
    cout<<"\n";
    cout<<"\t";cout<<"\t";cout<<"\t";cout<<"\t";cout<<"\t";
    cout<<"============================= \n";
    cout<<"\n";
     cout<<"\t";cout<<"\t";cout<<"\t";cout<<"\t";cout<<"\t";cout<<"     Developed By Shourov";
    cout<<"\n";
    cout<<"\t";cout<<"\t";cout<<"\t";cout<<"\t";cout<<"\t";
    cout<<"============================= \n";
    cout<<"\n";
    cout<<"\n";
	cout<<" \n Press Enter to Enter the System.....";
	getch();
	system("cls");
	login();
	int menu_choice,choice_return;
	start:
	    system("cls");
        cout<<"\n\t\t\t=================================\n";
        cout<<" \t\t\t   BUS TICKET RESERVATION SYSTEM";
        cout<<"\n\t\t\t=================================\n";
        cout<<"\n                                 \n";
        cout<<"\n1 Reserve Ticket/s\n";
        cout<<"\n2 View All Available Bus\n";
        cout<<"\n3 Exit";
        cout<<"\n\n Enter your Choice:";
        cin>>menu_choice;
        switch(menu_choice)
        {
            case 1: reservation();
			break;
			case 2: viewdetails();
			break;
			default:
			cout<<"\nInvalid choice";
        }
        goto start;
        return(0);
}
void login()
{
	int a=0,i=0;
    char uname[10],c=' ';
    char pword[10],code[10];
    char user[15]="shourov";
    char pass[15]="demo1234";
    do
{

    cout<<"\n";
    cout<<"\n  =======================  LOGIN FORM  =======================\n";
    cout<<" \n                       ENTER USERNAME:";
	cin>>uname;
	cout<<" \n                       ENTER PASSWORD:";
	while(i<10)
	{
	    pword[i]=getch();
	    c=pword[i];
	    if(c==13) break;
	    else
            cout<<"*";
	    i++;
	}
	pword[i]='\0';
	i=0;
		if(strcmp(uname,"shourov")==0 && strcmp(pword,"demo1234")==0)
	{
	cout<<"  \n\n\n       Thank you for log in  !! YOUR LOGIN IS SUCCESSFUL";
	cout<<"\n\n\n\t\t\t\t Press Any Key to continue...";
	getch();
	break;
	}
	else
	{
		cout<<"\n        SORRY !!!!  LOGIN IS UNSUCESSFUL";
		a++;
		getch();
		system("cls");
	}
}
	while(a<=3);
	if (a>3)
	{
	    system("color F4");
	    {
	        for(;;)
            {
                Sleep(200);
            cout<<"\nSorry you have entered the wrong Username or Password for maximum times!!!";
            }
        }
		getch();

		}
		system("cls");
}
void reservation(void)
{
	char confirm;
	int i=0;
	float charges;
	pd passdetails;
	FILE *fp;
	fp=fopen("seats_reserved.txt","a");
	system("cls");

	cout<<"\nEnter Your Name: ";
	fflush(stdin);
	gets(passdetails.name);
	cout<<"\nEnter Number of seats: ";
	cin>>passdetails.num_of_seats;
	cout<<"\n\nPress Enter To View Available Bus ";
	getch();
	system("cls");
	viewdetails();
	cout<<"\n\nEnter Bus number: ";
	start1:
	cin>>passdetails.bus_num;
	if(passdetails.bus_num>=1001 && passdetails.bus_num<=1010)
	{
		charges=charge(passdetails.bus_num,passdetails.num_of_seats);
		printticket(passdetails.name,passdetails.num_of_seats,passdetails.bus_num,charges);
	}
	else
	{
		cout<<"\nInvalid train Number! Enter again-- ";
		goto start1;
	}

	cout<<"\n\nConfirm Ticket (y/n):>";
	start:
	cin>>confirm;
	if(confirm == 'y')
	{
	    system("cls");
		fprintf(fp,"%s\t\t%d\t\t%d\t\t%.2f\n",&passdetails.name,passdetails.num_of_seats,passdetails.bus_num,charges);
		cout<<"==================\n";
		cout<<" Reservation Done\n";
		cout<<"==================";
		cout<<"\n";
        cout<<"\n Thanks for using this system\n";
		cout<<"\nPress backspace to go back to Main menu";
	}
	else
	{
		if(confirm=='n')
        {
			cout<<"\nReservation Not Done!\nPress backspace to go back to  Main menu!";
        }
		else
		{
			cout<<"\nInvalid choice entered! Enter again----- ";
			goto start;
		}
	}
	fclose(fp);
	getch();
}
float charge(int bus_num,int num_of_seats)
{
    if (bus_num==1001)
    {
		return(350.0*num_of_seats);
    }
	if (bus_num==1002)
    {
		return(450.0*num_of_seats);
    }
	if (bus_num==1003)
    {
		return(450.0*num_of_seats);
    }
	if (bus_num==1004)
    {
		return(280.0*num_of_seats);
    }
	if (bus_num==1005)
    {
		return(200.0*num_of_seats);
    }
	if (bus_num==1006)
    {
		return(580.0*num_of_seats);
    }
	if (bus_num==1007)
        {
		return(250.0*num_of_seats);
        }
	if (bus_num==1008)
    {
		return(310.0*num_of_seats);
    }
	if (bus_num==1009)
	{
		return(470.0*num_of_seats);
	}
	if (bus_num==1010)
	{
		return(2460.0*num_of_seats);
	}
}
void printticket(char name[],int num_of_seats,int bus_num,float charges)
{
	system("cls");
	time_t timetoday;
    time (&timetoday);
	cout<<"\t\t-------------------\n";
	cout<<"\t\tTICKET\n";
	cout<<"\t\t-------------------\n\n";
	cout<<"Name:\t\t\t"<<name;
	cout<<"\nNumber Of Seats:\t"<<num_of_seats;
	cout<<"\nTrain Number:\t\t"<<bus_num;
	specifictrain(bus_num);
	cout<<"\nCharges:\t\t"<<charges;
	cout << "\nTicket print time:\t"<< asctime(localtime(&timetoday));
}
void specifictrain(int bus_num)
{

	if (bus_num==1001)
	{
		cout<<"\nBus:\t\t\tDemo1 Express";
		cout<<"\nDestination:\t\tDhaka to Chittagong";
		cout<<"\nDeparture:\t\t9am ";
	}
	if (bus_num==1002)
	{
		cout<<"\nBus:\t\t\tDemo2 Express";
		cout<<"\nDestination:\t\tDhaka to Rajshahi";
		cout<<"\nDeparture:\t\t12pm";
	}
	if (bus_num==1003)
	{
		cout<<"\nBus:\t\t\tDemo3 Express";
		cout<<"\nDestination:\t\tDhaka to Khulna";
		cout<<"\nDeparture:\t\t8am";
	}
	if (bus_num==1004)
	{
		cout<<"\nBus:\t\t\tDemo4 Express";
		cout<<"\nDestination:\t\tDhaka to Sirajganj";
		cout<<"\nDeparture:\t\t5pm ";
	}
	if (bus_num==1005)
	{
		cout<<"\nBus:\t\t\tDemo5 Express";
		cout<<"\nDestination:\t\tDhaka to Lalmonirhat";
		cout<<"\nDeparture:\t\t7am";
	}
	if (bus_num==1006)
	{
		cout<<"\nBus:\t\t\tDemo6 Express ";
		cout<<"\nDestination:\t\tDhaka to Sylhet";
		cout<<"\nDeparture:\t\t9.30am ";
	}
	if (bus_num==1007)
	{
		cout<<"\nBus:\t\t\tDemo7 Express";
		cout<<"\nDestination:\t\tDhaka to Tangail";
		cout<<"\nDeparture:\t\t1pm ";
	}
	if (bus_num==1008)
	{
		cout<<"\nBus:\t\t\tDemo8 Express";
		cout<<"\n Destination:\t\tDhaka to Dinajpur";
		cout<<"\nDeparture:\t\t4pm ";
	}
	if (bus_num==1009)
	{
		cout<<"\nBus:\t\t\tDemo9 Express";
		cout<<"\nDestination:\t\tDhaka to Rajshahi";
		cout<<"\nDeparture:\t\t3.35pm ";
	}
	if (bus_num==1010)
	{
		cout<<"\nBus:\t\t\tDemo10 Express";
		cout<<"\nDestination:\t\tDhaka to Kholkhata";
		cout<<"\nDeparture:\t\t1.15 ";
	}
}
void viewdetails(void)
{
	system("cls");
	cout<<"-----------------------------------------------------------------------------";
	cout<<"\nTr.No\tName\t\t\tDestinations\t\tCharges\t\tTime\n";
	cout<<"-----------------------------------------------------------------------------";
	cout<<"\n1001\tDemo1 Express       Dhaka to Chittagong     \tTk.350\t\t9am";
	cout<<"\n1002\tDemo2 Express       Dhaka To Rajshahi       \tTk.450\t\t12pm";
	cout<<"\n1003\tDemo3 Express       Dhaka To Khulna         \tTk.450\t\t8am";
	cout<<"\n1004\tDemo4 Express       Dhaka To Sirajganj      \tTk.280\t\t5pm";
	cout<<"\n1005\tDemo5 Express       Dhaka To Lalmonirhat    \tTk.200\t\t7am";
	cout<<"\n1006\tDemo6 Express       Dhaka To Sylhet         \tTk.580\t\t9.30am";
    cout<<"\n1007\tDemo7 Express       Dhaka To tangail        \tTk.250\t\t1pm";
    cout<<"\n1008\tDemo8 Express       Dhaka To Dinajpur       \tTk.310\t\t4pm";
    cout<<"\n1009\tDemo9 Express       Dhaka To Rajshahi       \tTk.470\t\t3.35pm";
    cout<<"\n1010\tDemo10 Express      Dhaka To Kholkhata      \tTk.2460\t\t4.15pm";
    cout<<"\n";cout<<"\n";
    cout<<"Press Enter to go back to the main menu ";
   getch();
}


