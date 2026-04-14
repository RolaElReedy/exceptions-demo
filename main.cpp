#include <iostream>
#include <map>
#include "utils.hpp"

int main() {
    std::map<std::string, std::string> users;
    bool loggedIn = false;
    std::string currentUser = "";

    int choice;

    while (true) {
        std::cout << "\nMenu:\n";

        if (!loggedIn) {
            std::cout << "1. Sign Up\n";
            std::cout << "2. Login\n";
        } else {
            std::cout << "3. Logout\n";
        }

        std::cout << "0. Exit\n";
        std::cout << "Enter choice: ";
        std::cin >> choice;

        // SIGN UP
        if (choice == 1 && !loggedIn) {
            std::string email, password;

            std::cout << "Enter email: ";
            std::cin >> email;

            try {
                check_email(email);
            } catch (...) {
                std::cout << "Invalid email format\n";
                continue;
            }

            std::cout << "Enter password: ";
            std::cin >> password;

            users[email] = password;

            std::cout << "Sign up successful!\n";
        }

        // LOGIN
        else if (choice == 2 && !loggedIn) {
            std::string email, password;

            std::cout << "Enter email: ";
            std::cin >> email;

            std::cout << "Enter password: ";
            std::cin >> password;

            if (users.find(email) != users.end() && users[email] == password) {
                loggedIn = true;
                currentUser = email;
                std::cout << "Login successful!\n";
            } else {
                std::cout << "Invalid credentials\n";
            }
        }

        // LOGOUT
        else if (choice == 3 && loggedIn) {
            loggedIn = false;
            currentUser = "";
            std::cout << "Logged out successfully\n";
        }

        // EXIT
        else if (choice == 0) {
            std::cout << "Exiting program...\n";
            break;
        }

        else {
            std::cout << "Invalid option\n";
        }
    }

    return 0;
}
