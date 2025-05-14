#include "PasswordAnalyzer.h"
#include <iostream>
#include <cmath>
#include <map>

void PasswordAnalyzer::analyzePassword(const std::string& password) {
    std::map<char, int> frequency;
    for (char ch : password) {
        frequency[ch]++;
    }

    std::cout << "\nCharacter Frequency:\n";
    for (const auto& pair : frequency) {
        std::cout << pair.first << ": " << pair.second << "\n";
    }

    std::cout << "Password Length: " << password.length() << "\n";
}

double PasswordAnalyzer::calculateEntropy(const std::string& password) {
    int charsetSize = 0;
    bool hasLower = false, hasUpper = false, hasDigit = false, hasSymbol = false;

    for (char ch : password) {
        if (islower(ch)) hasLower = true;
        else if (isupper(ch)) hasUpper = true;
        else if (isdigit(ch)) hasDigit = true;
        else hasSymbol = true;
    }

    if (hasLower) charsetSize += 26;
    if (hasUpper) charsetSize += 26;
    if (hasDigit) charsetSize += 10;
    if (hasSymbol) charsetSize += 32; // approximate special char set

    double entropy = password.length() * std::log2(charsetSize);
    std::cout << "Estimated Entropy: " << entropy << " bits\n";

    if (entropy < 28) std::cout << "Very Weak\n";
    else if (entropy < 36) std::cout << "Weak\n";
    else if (entropy < 60) std::cout << "Reasonable\n";
    else if (entropy < 128) std::cout << "Strong\n";
    else std::cout << "Very Strong\n";

    return entropy;
}
