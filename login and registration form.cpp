#include<iostream>
#include<fstream>
#include<string.h>
#include<Windows.h>
using namespace std;

void login();
void registration();
void forgot();

int main()
{
	int choice;
	cout << "\t\t\t___________________________________\n\n\n";
	cout << "\t\t\t				Welcome to the Login Page  \n\n\n";
	cout << "\t\t\t________________		Menu		__________________\n\n\n";
	cout << "																\n\n\n";
	cout << "\t| Press 1 to Login								|" << endl;
	cout << "\t| Press 2 to Register							|" << endl;
	cout << "\t| Press 3 if you forgot Password					|" << endl;
	cout << "\t| Press 4 to Exit								|" << endl;
	cout << "\n\t\t\t Please enter your choice :";
	cin >> choice;
	switch(choice)
	{
	case 1:
		login();
		break;

	case 2:
		registration();
		break;

	case 3:
		forgot();
		break;

	case 4:
		cout << "\t\t\t Thank You! \n\n\n";
		break;
	default:
		system("cls"); //to clear up the screen
		cout << "\t\t\t Please select from the options given above \n" << endl;
		main();
	}
}
void login()
{
	int count=0;
	string userid, password, id, pass;
	system("cls");
	cout << "\t\t\t Please enter the user name and password :" << endl;
	cout << "\t\t\t USERNAME :";
		cin >> userid;
	cout << "\t\t\t PASSWORD :";
	cin >> password;

	//to check data with in the data base

	ifstream input("records.txt");

	while(input>>id>>pass)
	{
		if(id==userid && pass==password)
		{
			count = 1;
			system("cls");
		}
	}
	input.close();
	if(count==1)
	{
		cout << userid << "\n Your LOGIN is Successfull \n ThankYou for logging in !";
	}
	else
	{
		system("Color 0C");
		cout << "\n Login Error \nPlease Check your User name and Password\n";
		
	}
	main();
}
void registration()
{
	string ruserid, rpassword, rid, rpass;
	system("cls");
	cout << "\t\t\t Enter the user name :";
	cin >> ruserid;
	cout << "\t\t\t Enter the password :";
	cin >> rpassword;

	/*Writing content into the file*/
	ofstream f1("records.txt", ios::app);
	f1 << ruserid << " " << rpassword << endl;

	system("cls");
	cout << "\n\t\t\t Registration is successful !\n";
	main();

}
void forgot()
{
	int option;
	system("cls");
	cout << "\t\t\t You forgot the password? No worries\n";
	cout << "Press 1 to search your id by username " << endl;
	cout << "Press 2 to go back to main menu " << endl;
	cout << "\t\t\t Enter your choice :";
	cin >> option;
	switch(option)
	{
	case 1:
		{
		int count = 0;
		string suserid, sid, spass;
		cout << "Enter the user name !";
		cin >> suserid;
		ifstream f2("records.txt");
			while(f2>>sid>>spass)
			{
				if(sid==suserid)
				{
					count = 1;
				}
			}
			f2.close();
			if(count==1)
			{
				cout << "\n\n your Account is found !\n";
				cout << "\n\n Your password is :" << spass;
				main();
			}
			break;
		}
	case 2:
		{
		main();

		}
	default:
		cout << "\t\t\t Wrong Choice ! Please Try again " << endl;
		forgot();
	}

}

