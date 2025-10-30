#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class temp {
    string userName, email, password;
    string searchName, searchPass, searchEmail;
    fstream file;
public:
    void login();
    void signup();
    void forgetPassword();
} obj;

int main() {
    char choice;
    cout << "\n1. Login";
    cout << "\n2. Sign up";
    cout << "\n3. Forget Password";
    cout << "\n4. Exit";
    cout << "\n\nEnter your choice :: ";
    cin >> choice;
    cin.ignore();

    switch (choice) {
    case '1':
        obj.login();
        break;
    case '2':
        obj.signup();
        break;
    case '3':
        obj.forgetPassword();
        break;
    case '4':
        return 0;
    default:
        cout << "\nInvalid Selection ...!" << endl;
    }
}

void temp::signup() {
    cout << "\nEnter User Name :: ";
    getline(cin, userName);

    cout << "Enter Your Email :: ";
    getline(cin, email);

    cout << "Enter Your Password :: ";
    getline(cin, password);

    file.open("login.txt", ios::out | ios::app);
    file << userName << "*" << email << "*" << password << endl;
    file.close(); 
    cout << "\nAccount created successfully!" << endl;
}

void temp::login() {
    cout << "\n-------- Login -----------" << endl;

    cout << "Enter Your Email :: ";
    getline(cin, searchName);

    cout << "Enter Your Password :: ";
    getline(cin, searchPass);

    file.open("login.txt", ios::in);
    bool found = false;

    while (getline(file, userName, '*')) {
        getline(file, email, '*');
        getline(file, password, '\n');

        if (email == searchName) {
            found = true;
            if (password == searchPass) {
                cout << "\nAccount Login Successfully!" << endl;
                cout << "User Name :: " << userName << endl;
                cout << "Email :: " << email << endl;
            }
            else {
                cout << "\nPassword is Incorrect!" << endl;
            }
            break;
        }
    }

    if (!found) {
        cout << "\nAccount not found!" << endl;
    }

    file.close();
}

void temp::forgetPassword() {
    cout << "\nEnter User Name :: ";
    getline(cin, searchName);

    cout << "Enter Email Address :: ";
    getline(cin, searchEmail);

    file.open("login.txt", ios::in);
    bool found = false;

    while (getline(file, userName, '*')) {
        getline(file, email, '*');
        getline(file, password, '\n');

        if (userName == searchName && email == searchEmail) {
            cout << "\nAccount Found!" << endl;
            cout << "Your Password :: " << password << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "\nAccount not found!" << endl;
    }

    file.close();
}
