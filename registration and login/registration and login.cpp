#include<iostream>
#include<fstream>
using namespace std;


class temp {
	string userName, email, password;
	string searchName, searchPass, searchEamil;
	fstream  file;
public:
	void login();
	void signup();
	void forgetPassword();
}obj;

int main() {
	char choice;
	cout << "\n1 Login";
	cout << "\n2 Sign up";
	cout << "\n3 Forget Password";
	cout << "\n4 Exit";
	cout << "\n5 Enter your choice :: ";
	cin >> choice;


	switch (choice) {
		case '1':
			cin.ignore();
			obj.login();
		break;
		case '2':
			cin.ignore();
			obj.signup();
		break;
		case '3':
			cin.ignore();
			obj.forgetPassword();
		break;
		case '4':
			return 0;
		break;
		default:
			cout << "\n Invalid Selection ...!";
	}
}

void temp::signup() {

	cout << "\n Enter User Name ::";
	getline(cin, userName);

	cout << "\n Enter Your Email ::";
	getline(cin, email);

	cout << "\n Enter Your Password ::";
	getline(cin, password);

	file.open("login.txt", ios::out | ios::app);
	file << userName << "*" << email << "*" << password << endl;
}

void temp::login() {

	cout << "--------Login-----------"<<endl;

	cout << "Enter Your Email ::" << endl;
	getline(cin, searchName);

	cout << "Enter Your Password ::" << endl;
	getline(cin, searchPass);

	file.open("login.txt", ios::in);
	getline(file, userName, '*');
	getline(file, email, '*');
	getline(file, password, '\n');

    // Fix: Add missing closing parenthesis for while condition in login() method
    while (!file.eof()) {
        if (userName == searchName) {
            if (password == searchPass) {
                cout << "\n Account Login Successfully...!" << endl;
                cout << "\n User Name :: "<<userName << endl;
                cout << "\n Email :: "<<email << endl;
            }
            else
            {
                cout << "Password is Incorrect...!";
            }
        }
        getline(file, userName, '*');
        getline(file, email, '*');
        getline(file, password, '*');
    }
	file.close();
}