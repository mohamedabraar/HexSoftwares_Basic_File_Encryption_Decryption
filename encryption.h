#ifndef ENCRYPTION_H
#define ENCRYPTION_H

#include <string>

std::string encryptText(std::string text, int shift);
void encryptFile(const std::string& inputFilePath, const std::string& outputFilePath, int shift);

#endif
