#include <iostream>
#include <fstream>
#include <string>
#include "encryption.h"
#include "decryption.h"
#include "../../../Downloads/tinyfiledialogs.h"
#include <thread>
#include <chrono>

// ANSI Escape Codes for Colors
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define CYAN    "\033[36m"
#define BOLD    "\033[1m"

using namespace std;

// Function to display the program banner
void displayBanner() {
    cout << BOLD << RED << R"(
    
 (      (                                        )                          
 )\ )   )\ )                       (          ( /(         *   )       (    
(()/(  (()/(       (   (    (      )\   (     )\())      ` )  /( (     )\   
 /(_))  /(_))  (   )\  )\  ))\   (((_)  )(   ((_)\  `  )  ( )(_)))\  (((_)  
(_))   (_))    )\ ((_)((_)/((_)  )\___ (()\ __ ((_) /(/( (_(_())((_) )\___  
|_ _|  | |    ((_)\ \ / /(_))   ((/ __| ((_)\ \ / /((_)_\|_   _| (_)((/ __| 
 | |   | |__ / _ \ \ V / / -_)   | (__ | '_| \ V / | '_ \) | |   | | | (__  
|___|  |____|\___/  \_/  \___|    \___||_|    |_|  | .__/  |_|   |_|  \___| 
                                                   |_|                      

    Secure your files with ease!
    )" << endl;
}

// Function to display the menu
void displayMenu() {
    cout << BOLD << GREEN;
    cout << "\n====================\n";
    cout << "  Encryption Tool\n";
    cout << "====================\n";
    cout << RESET;
    cout << "1. Encrypt a file\n";
    cout << "2. Decrypt a file\n";
    cout << "3. Exit\n";
    cout << "Enter your choice: ";
}

// Function to show success messages
void showSuccessMessage(const string& message) {
    cout << GREEN << message << RESET << endl;
}

// Function to show error messages
void showErrorMessage(const string& message) {
    cout << RED << message << RESET << endl;
}

// Function to show a loading effect
void showLoadingEffect() {
    const char* loadingChars = "|/-\\";
    for (int i = 0; i < 10; ++i) {
        cout << "\rProcessing " << loadingChars[i % 4] << flush;
        this_thread::sleep_for(chrono::milliseconds(200));
    }
    cout << "\rProcessing done!   \n";
}

// Function to process a file (encrypt or decrypt)
void processFile(const string& operation) {
    // Open file dialog for input file selection
    const char* inputFilePath = tinyfd_openFileDialog(
        ("Select a file to " + operation).c_str(),
        "",
        0,
        nullptr,
        nullptr,
        0
    );

    if (!inputFilePath) {
        showErrorMessage("No file selected. Returning to main menu...");
        return;
    }

    // Read the content of the input file
    ifstream inputFile(inputFilePath);
    if (!inputFile.is_open()) {
        showErrorMessage("Error: Could not open input file.");
        return;
    }

    string content((istreambuf_iterator<char>(inputFile)), istreambuf_iterator<char>());
    inputFile.close();

    // Prompt for shift value with validation
    int shift;
    do {
        cout << "Enter shift value (1-25): ";
        cin >> shift;
        if (shift < 1 || shift > 25) {
            showErrorMessage("Invalid shift value. Please enter a value between 1 and 25.");
        }
    } while (shift < 1 || shift > 25);
    cin.ignore();

    // Perform encryption or decryption
    string result;
    if (operation == "encrypt") {
        result = encryptText(content, shift);
    }
    else if (operation == "decrypt") {
        result = decryptText(content, shift);
    }

    // Save the result to a new file
    string defaultOutputName = (operation == "encrypt") ? "encrypted_output.txt" : "decrypted_output.txt";
    const char* outputFilePath = tinyfd_saveFileDialog(
        ("Save " + operation + "ed file").c_str(),
        defaultOutputName.c_str(),
        0,
        nullptr,
        nullptr
    );

    if (!outputFilePath) {
        showErrorMessage("No file selected for saving. Returning to main menu...");
        return;
    }

    ofstream outputFile(outputFilePath);
    if (!outputFile.is_open()) {
        showErrorMessage("Error: Could not create output file.");
        return;
    }

    outputFile << result;
    outputFile.close();

    showSuccessMessage("The " + operation + "ed file was successfully saved to: " + outputFilePath);
}

int main() {
    int choice;

    // Display the program banner
    displayBanner();

    do {
        displayMenu();
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1:
            processFile("encrypt");
            break;

        case 2:
            processFile("decrypt");
            break;

        case 3:
            showSuccessMessage("Exiting program...");
            break;

        default:
            showErrorMessage("Invalid choice. Try again.");
        }
    } while (choice != 3);

    return 0;
}
