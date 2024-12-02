## HexSoftwares Basic File Encryption and Decryption

## Introduction

HexSoftwares Basic File Encryption and Decryption is a lightweight and user-friendly tool designed to safeguard sensitive data. Inspired by the seamless and intuitive workflows of **I Love PDF**, this project aims to bring similar ease of use and functionality to the realm of file security. 

Whether you're encrypting a private document or decrypting an important file, this tool ensures your files are processed securely and efficiently. Its simple interface, combined with robust functionality, makes it a perfect choice for anyone looking to add an extra layer of security to their data.

---

## Features

- **File Encryption**: Protect files with a Caesar Cipher-based encryption method.
- **File Decryption**: Restore encrypted files using the correct shift value.
- **Intuitive UI**: Inspired by **I Love PDF**, the program offers a clean, menu-driven interface.
- **File Selection Dialogs**: Powered by TinyFileDialogs for user convenience.
- **Customizable Shift Values**: Choose a numeric key for added encryption variability.
- **Error Handling and Feedback**: Receive informative success or error messages throughout the process.
- **Loading Animation**: Visual feedback during file processing.

---

## Algorithms Used

The program employs a **Caesar Cipher**, a simple yet effective substitution cipher named after Julius Caesar. Here's a breakdown:

### 1. **Encryption Algorithm**
The Caesar Cipher encrypts text by shifting each character by a fixed number of places (the shift value) in the alphabet. 

For example:
- Plaintext: `HELLO`
- Shift Value: `3`
- Encrypted Text: `KHOOR`

Each character is shifted forward by 3 positions. Non-alphabetic characters are not altered, ensuring compatibility with various file types.


### 2. **Decryption Algorithm**
Decryption reverses the encryption process by shifting characters backward by the same shift value. Using the example above:
- Encrypted Text: `KHOOR`
- Shift Value: `3`
- Decrypted Text: `HELLO`


These algorithms are computationally efficient and work seamlessly for large text-based files.

---

## Inspiration

The inspiration for this project came from **I Love PDF**, a versatile and user-friendly online tool that simplifies PDF management. The goal was to replicate its approachable design philosophy and user-centric approach in a desktop application for encryption and decryption.

This project embodies the principles of simplicity, accessibility, and efficiency. It serves as a stepping stone toward creating more sophisticated file-processing tools with an intuitive design.

---

## Requirements

- C++ Compiler: The program is written in C++ and requires a modern C++ compiler.
- TinyFileDialogs Library: For file selection dialogs.
- Windows OS: Currently supported on Windows.

---

## Installation

1. Clone the Repository:
   ```bash
   git clone https://github.com/mohamedabraar/HexSoftwares_Basic_File_Encryption_Decryption.git
2. Set Up TinyFileDialogs:
   Download and include the TinyFileDialogs library in your project.
   
3. Open in Visual Studio:
   Open the .sln file in Visual Studio 2022.
   
4. Build the Project:
   Ensure all dependencies are properly linked, and then build the project.

---

## Usage

Step 1: Start the Program
   Run the application, and you'll see a menu with the following options:
   Encrypt a File
   Decrypt a File
   Exit
   
Step 2: Choose an Option
   Encrypt a File:

   Select a file to encrypt using the file dialog.
   Enter a shift value (1-25).
   Save the encrypted file with a new name.
   Decrypt a File:

   Select the encrypted file.
   Enter the shift value used for encryption.
   Save the decrypted file with a new name.
   
Step 3: Process Feedback
   The program provides a progress animation while processing and displays a success message upon completion.

Step 4: Exit the Program
   Select Option 3 to exit.


## Future Enhancements

Support for multiple encryption algorithms (AES, RSA).
Cross-platform compatibility (macOS and Linux).
Enhanced UI with a graphical interface.
Batch processing of files.
User authentication for added security.



