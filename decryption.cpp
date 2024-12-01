#include "decryption.h"
#include "encryption.h"
#include <fstream>

std::string decryptText(std::string text, int shift) {
    return encryptText(text, 26 - shift);
}

void decryptFile(const std::string& inputFilePath, const std::string& outputFilePath, int shift) {
    std::ifstream inputFile(inputFilePath);
    if (!inputFile.is_open()) {
        throw std::runtime_error("Error opening input file.");
    }

    std::ofstream outputFile(outputFilePath);
    if (!outputFile.is_open()) {
        throw std::runtime_error("Error creating output file.");
    }

    std::string line;
    while (std::getline(inputFile, line)) {
        outputFile << decryptText(line, shift) << "\n";
    }

    inputFile.close();
    outputFile.close();
}
