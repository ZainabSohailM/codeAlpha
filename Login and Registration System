#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

string hashPassword(const string& password) {
    stringstream ss;
    for (char c : password) {
        ss << hex << int(c);
    }
    return ss.str();
}

bool checkPassword(const string& password) {
    bool upper_case = false, lower_case = false, digits = false, special_char = false;

    if (password.length() < 8) return false;

    for (char c : password) {
        if (isupper(c)) upper_case = true;
        else if (islower(c)) lower_case = true;
        else if (isdigit(c)) digits = true;
        else if (!isalnum(c)) special_char = true;
    }

    return upper_case && lower_case && digits && special_char;
}

bool registerUser(const string& username, const string& password) {
    ifstream file(username + ".txt");
    if (file.is_open()) {
        cout << "Username already exists.\n";
        return false;
    }

    ofstream outFile(username + ".txt");
    outFile << hashPassword(password);
    outFile.close();

    cout << "Registration successful. Your user file has been created.\n";
    return true;
}

bool loginUser(const string& username, const string& password) {
    ifstream file(username + ".txt");
    if (!file.is_open()) {
        cout << "User not found.\n";
        return false;
    }

    string storedHash;
    getline(file, storedHash);
    file.close();

    if (storedHash == hashPassword(password)) {
        cout << "Login successful.\n";
        return true;
    }
    else {
        cout << "Invalid password.\n";
        return false;
    }
}

int main() {
    int choice;
    string username, password;

    cout << "1. Register\n2. Login\nEnter choice: ";
    cin >> choice;

    if (choice == 1) {
        bool passwordStrong = false;
        while (!passwordStrong) {
            cout << "Enter username: ";
            cin >> username;
            cout << "Enter password: ";
            cin >> password;

            if (checkPassword(password)) {
                passwordStrong = true;
                registerUser(username, password);
            }
            else {
                cout << "Weak Password! Please make sure it has at least 8 characters, one lowercase letter, one digit, and one special character.\n";
            }
        }
    }
    else if (choice == 2) {
        cout << "Enter username: ";
        cin >> username;
        cout << "Enter password: ";
        cin >> password;
        loginUser(username, password);
    }
    else {
        cout << "Invalid choice.\n";
    }

    return 0;
}
