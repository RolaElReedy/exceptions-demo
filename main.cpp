#include <iostream>
#include <map>
#include "utils.hpp"

using namespace std;

int main() {
    map<string, string> users;
    bool loggedIn = false;

    int choice;

    while (true) {
        cout << endl << "Menu:" << endl;

        if (!loggedIn) {
            cout << "1. Sign Up" << endl;
            cout << "2. Login" << endl;
        } else {
            cout << "3. Logout" << endl;
        }

        cout << "0. Exit" << endl;
        cout << "Choice: ";
        cin >> choice;

        // SIGN UP
        if (choice == 1 && !loggedIn) {
            string email, password;

            cout << "Enter email: ";
            cin >> email;

            try {
                check_email(email);
            } catch (invalid_argument& e) {
                cout << "Invalid email" << endl;
                continue;
            }

            cout << "Enter password: ";
            cin >> password;

            users[email] = password;

            cout << "Account created" << endl;
        }

        // LOGIN
        else if (choice == 2 && !loggedIn) {
            string email, password;

            cout << "Enter email: ";
            cin >> email;

            cout << "Enter password: ";
            cin >> password;

            if (users.find(email) != users.end() && users[email] == password) {
                loggedIn = true;
                cout << "Logged in" << endl;
            } else {
                cout << "Wrong email or password" << endl;
            }
        }

        // LOGOUT
        else if (choice == 3 && loggedIn) {
            loggedIn = false;
            cout << "Logged out" << endl;
        }

        // EXIT
        else if (choice == 0) {
            break;
        }

        else {
            cout << "Invalid choice" << endl;
        }
    }

    return 0;
}
