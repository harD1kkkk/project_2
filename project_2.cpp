// project_2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "FileManagerChild.h"


int main() {

    // Create a FileManagerChild object with the current working directory as the start path
    FileManagerChild fmc(fs::current_path().string());

    // Print a welcome message
    cout << "Welcome to the file manager program.\n";

    // Declare variables to store the user's option and name
    int option;
    string name;

    // Repeat until the user chooses to exit
    do {
        // Print the menu options
        cout << "Choose an option:\n";
        cout << "1. Show drives\n";
        cout << "2. Show directory\n";
        cout << "3. Create directory\n";
        cout << "4. Create file\n";
        cout << "5. Remove\n";
        cout << "6. Rename\n";
        cout << "7. Copy\n";
        cout << "8. Move\n";
        cout << "9. Size\n";
        cout << "10. Search\n";
        cout << "0. Exit\n";

        // Get the user's option
        cin >> option;

        // Perform different actions depending on the option
        if (option == 1) { // Show drives
            fmc.showDrives();
        }

        else if (option == 2) { // Show directory
            fmc.showDirectory();
        }

        else if (option == 3) { // Create directory
            cout << "Enter the name of the new directory: ";
            cin >> name;
            bool isNum = false;
            for (char a : name) {
                if (isdigit(a)) {
                    isNum = true;
                    break;
                }
                else {
                    isNum = false;
                }
            }
            if (isNum) {
                cout << "Invalid name, try again!\n\n";
            }
            else {
                cout << "Created!\n";
                fmc.createDiractory(name);
            }
        }

        else if (option == 4) { // Create file
            cout << "Enter the name of the new file: ";
            cin >> name;
            bool isNum = false;
            for (char a : name) {
                if (isdigit(a)) {
                    isNum = true;
                    break;
                }
                else {
                    isNum = false;
                }
            }
            if (isNum) {
                cout << "Invalid name, try again!\n";
            }
            else {
                cout << "Created!\n";
                fmc.createFile(name);
            }
        }

        else if (option == 5) { // Remove
            cout << "Enter the name of the element to remove: ";
            cin >> name;
            bool isNum = false;
            for (char a : name) {
                if (isdigit(a)) {
                    isNum = true;
                    break;
                }
                else {
                    isNum = false;
                }
            }
            if (isNum) {
                cout << "Invalid name, try again!\n";
            }
            else {
                cout << "Removed!\n";
                fmc.remove(name);
            }
        }

        else if (option == 6) { // Rename
            string old_name, new_name;
            cout << "Enter the old name of the element to rename: ";
            cin >> old_name;
            bool isNum = false;
            for (char a : old_name) {
                if (isdigit(a)) {
                    isNum = true;
                    break;
                }
                else {
                    isNum = false;
                }
            }

            if (isNum) {
                cout << "Invalid name, try again!\n";
            }
            else {
                cout << "Enter the new name of the element: ";
                cin >> new_name;
                bool isNum = false;
                for (char a : new_name) {
                    if (isdigit(a)) {
                        isNum = true;
                        break;
                    }
                    else {
                        isNum = false;
                    }
                }

                if (isNum) {
                    cout << "Invalid name, try again!\n";
                }
                else {
                    fmc.rename(old_name, new_name);
                }
            }
        }

        else if (option == 7) { // Copy
            string source, destination;
            cout << "Enter the source element to copy: ";
            cin >> source;
            bool isNum = false;
            for (char a : source) {
                if (isdigit(a)) {
                    isNum = true;
                    break;
                }
                else {
                    isNum = false;
                }
            }

            if (isNum) {
                cout << "Invalid name, try again!\n";
            }
            else {
                cout << "Enter the destination element: ";
                cin >> destination;
                bool isNum = false;
                for (char a : destination) {
                    if (isdigit(a)) {
                        isNum = true;
                        break;
                    }
                    else {
                        isNum = false;
                    }
                }

                if (isNum) {
                    cout << "Invalid name, try again!\n";
                }
                else {
                    fmc.copy(source, destination);
                }
            }
        }

        else if (option == 8) { // Move
            string source, destination;
            cout << "Enter the source element to move: ";
            cin >> source;
            bool isNum = false;
            for (char a : source) {
                if (isdigit(a)) {
                    isNum = true;
                    break;
                }
                else {
                    isNum = false;
                }
            }

            if (isNum) {
                cout << "Invalid name, try again!\n";
            }
            else {
                cout << "Enter the destination element: ";
                cin >> destination;
                bool isNum = false;
                for (char a : destination) {
                    if (isdigit(a)) {
                        isNum = true;
                        break;
                    }
                    else {
                        isNum = false;
                    }
                }
                if (isNum) {
                    cout << "Invalid name, try again!\n";
                }
                else {
                    fmc.move(source, destination);
                }
            }
        }

        else if (option == 9) { // Size
            cout << "Enter the name of the element to get its size: ";
            cin >> name;
            bool isNum = false;
            for (char a : name) {
                if (isdigit(a)) {
                    isNum = true;
                    break;
                }
                else {
                    isNum = false;
                }
            }
            if (isNum) {
                cout << "Invalid name, try again!\n";
            }

            else {
                cout << "The size of " << name << " is " << fmc.size(name) << " bytes.\n";
            }
        }

        else if (option == 10) { // Search
            string mask;
            cout << "Enter the mask (regular expression) to search for elements: ";
            cin >> mask;
            bool isNum = false;
            for (char a : mask) {
                if (isdigit(a)) {
                    isNum = true;
                    break;
                }
                else {
                    isNum = false;
                }
            } 

            if (isNum) {
                cout << "Invalid name, try again!\n";
            }
            else {
                fmc.search(mask);
            }
        }
        else if (option == 0) { // Exit
            cout << "Thank you for using the file manager program.\n";
        }
        else {
            cerr << "Unknown option!\n";
        }

        // Pause and clear the screen before showing the menu again
        system("pause");
        system("cls");

    } while (option != 0);
}