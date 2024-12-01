#ifndef DECRYPTION_H
#define DECRYPTION_H

#include <string>

std::string decryptText(std::string text, int shift);
void decryptFile(const std::string& inputFilePath, const std::string& outputFilePath, int shift);

#endif
