// main.cpp
#include <iostream>
#include "PasswordAnalyzer.h"
#include "PasswordGenerator.h"
#include "PasswordRecord.h"
#include <queue>

int main() {
    std::queue<PasswordRecord> history;

    while (true) {
        std::cout << "\n--- Password Analyzer & Generator ---\n";
        std::cout << "1. Analyze Password Strength\n";
        std::cout << "2. Generate Strong Password\n";
        std::cout << "3. View History\n";
        std::cout << "4. Exit\n";
        std::cout << "Select an option: ";

        int choice;
        std::cin >> choice;
        std::cin.ignore();

        if (choice == 1) {
            std::string pwd;
            std::cout << "Enter your password: ";
            std::getline(std::cin, pwd);
            double entropy = PasswordAnalyzer::calculateEntropy(pwd);
            PasswordAnalyzer::analyzePassword(pwd);

            std::string timestamp = PasswordRecord::getCurrentTimestamp();
            history.push(PasswordRecord(pwd, entropy, timestamp));

        } else if (choice == 2) {
            int len;
            char special;
            std::cout << "Enter desired password length: ";
            std::cin >> len;
            std::cout << "Include special characters? (y/n): ";
            std::cin >> special;
            bool useSpecial = (special == 'y' || special == 'Y');

            PasswordGenerator generator(len, useSpecial);
            std::string newPwd = generator.generate();
            std::cout << "Generated Password: " << newPwd << "\n";

        } else if (choice == 3) {
            std::queue<PasswordRecord> temp = history;
            std::cout << "\n--- Password History ---\n";
            while (!temp.empty()) {
                temp.front().display();
                temp.pop();
            }

        } else if (choice == 4) {
            std::cout << "Exiting. Goodbye!\n";
            break;

        } else {
            std::cout << "Invalid choice. Try again.\n";
        }
    }
    return 0;
}
