#include<iostream>
#include<fstream>
using namespace std;


class temp {
	string userName, email, password;
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
		break;
	case '2':
		break;
	case '3':
		break;
	case '4':
		break;
	default:
		cout << "\n Invalid Selection ...!";
	}
}