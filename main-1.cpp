#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Function to check whether a username already exists
bool usernameExists(string username)
{
    ifstream file("users.txt");

    string savedUsername, savedPassword;

    while (file >> savedUsername >> savedPassword)
    {
        if (savedUsername == username)
        {
            file.close();
            return true;
        }
    }

    file.close();
    return false;
}

// Function for user registration
void registerUser()
{
    string username, password;

    cout << "\n========== REGISTRATION ==========\n";

    cout << "Enter username: ";
    cin >> username;

    if (usernameExists(username))
    {
        cout << "Username already exists! Try another.\n";
        return;
    }

    cout << "Enter password: ";
    cin >> password;

    ofstream file("users.txt", ios::app);

    file << username << " " << password << endl;

    file.close();

    cout << "\nRegistration successful!\n";
}

// Function for user login
void loginUser()
{
    string username, password;
    string savedUsername, savedPassword;

    cout << "\n============== LOGIN ==============\n";

    cout << "Enter username: ";
    cin >> username;

    cout << "Enter password: ";
    cin >> password;

    ifstream file("users.txt");

    bool loginSuccessful = false;

    while (file >> savedUsername >> savedPassword)
    {
        if (savedUsername == username &&
            savedPassword == password)
        {
            loginSuccessful = true;
            break;
        }
    }

    file.close();

    if (loginSuccessful)
    {
        cout << "\nLogin successful! Welcome, "
             << username << "!\n";
    }
    else
    {
        cout << "\nInvalid username or password!\n";
    }
}

// Main function
int main()
{
    int choice;

    do
    {
        cout << "\n====================================\n";
        cout << "       LOGIN AND REGISTRATION\n";
        cout << "====================================\n";

        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "3. Exit\n";

        cout << "\nEnter your choice: ";
        cin >> choice;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "\nInvalid input! Enter a number.\n";
            continue;
        }

        switch (choice)
        {
            case 1:
                registerUser();
                break;

            case 2:
                loginUser();
                break;

            case 3:
                cout << "\nThank you for using the system!\n";
                break;

            default:
                cout << "\nInvalid choice! Please try again.\n";
        }

    } while (choice != 3);

    return 0;
}
