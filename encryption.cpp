#include "encryption.h"
#include <fstream>

std::string encryptText(std::string text, int shift) {
    std::string result;
    for (char c : text) {
        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            result += (c - base + shift) % 26 + base;
        }
        else {
            result += c;
        }
    }
    return result;
}

void encryptFile(const std::string& inputFilePath, const std::string& outputFilePath, int shift) {
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
        outputFile << encryptText(line, shift) << "\n";
    }

    inputFile.close();
    outputFile.close();
}
