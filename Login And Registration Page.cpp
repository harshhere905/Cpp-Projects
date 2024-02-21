#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
class temp
{
  string username, Email, password;
  string searchname, searchpass, searchEmail;
  fstream file;
public:
  void login ();
  void signUp ();
  void forgot ();

} obj;

int
main ()
{
  char choice;
  cout << "\n1- Login";
  cout << "\n2- Sign-up";
  cout << "\n3- Forgot Password";
  cout << "\n4- Exit" << endl;
  cout << "\nEnter your choice: ";
  cin >> choice;

  switch (choice)
	{
	case '1':
	  obj.login ();
	  break;
	case '2':
	  obj.signUp ();
	  break;
	case '3':
	  obj.forgot ();
	  break;
	case '4':
	  return 0;
	  break;
	default:
	  cout << "invalid selection";
	}

}

void temp::signUp()
{
  cout<<"Enter Your User Name :: ";
    cin.ignore();
    getline(cin,username);
    cout<<"Enter Your Email Address :: ";
    getline(cin,Email);
    cout<<"Enter Your Password :: ";
    getline(cin,password);

    file.open("loginData.txt",ios :: out | ios :: app);
    file<<username<<"*"<<Email<<"*"<<password<<endl;
    file.close();
}

void temp::login ()
{

  cout << "------LOGIN------" << endl;
  cout << "\nEnter your username: ";
  cin.ignore();
  getline (cin, searchname);
  cout << "\nEnter your password: " << endl;
  getline (cin, searchpass);
  file.open ("loginData.txt", ios::in);
  getline (file, username, '*');
  getline (file, Email, '*');
  getline (file, password, '\n');
  while (!file.eof ())
	{
	  if (searchname == username)
		{
		  if (searchpass == password)
			{
			  cout << "\n Account Login Successfull";
			  cout << "\nUsername: " << username << endl;
			  cout << "\nEmail: " << Email << endl;
			}
		}
	  getline (file, username, '*');
	  getline (file, Email, '*');
	  getline (file, password, '\n');
	}
}

void temp::forgot ()
{
  cout << "\nEnter your username: ";
  cin.ignore();
  getline (cin, searchname);
  cout << "\nEnter your email: ";
  getline (cin, searchEmail);

  file.open ("loginData.txt", ios::in);
  getline (file, username, '*');
  getline (file, Email, '*');
  getline (file, password, '\n');
  while (!file.eof ())
	{
	  if (username == searchname)
		{
		  if (Email == searchEmail)
			{
			  cout << "\nAccount Found...!"<<endl;
			  cout<<"Your Password :: "<<password<<endl;
			}
		  else
			{
			  cout << "Not found...!\n";
			}
		}
	  else
		{
		  cout << "\nNot found...!\n";
		}
    getline(file,username,'*');
    getline(file,Email,'*');
    getline(file,password,'\n');
    }
     file.close();
	}

