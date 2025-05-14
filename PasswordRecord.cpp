#include "PasswordRecord.h"
#include <iostream>
#include <ctime>

PasswordRecord::PasswordRecord(std::string pwd, double ent, std::string time)
    : password(pwd), entropy(ent), timestamp(time) {}

void PasswordRecord::display() const {
    std::cout << "Password: " << password << "\n";
    std::cout << "Entropy: " << entropy << "\n";
    std::cout << "Time: " << timestamp << "\n\n";
}

std::string PasswordRecord::getCurrentTimestamp() {
    time_t now = time(0);
    char* dt = ctime(&now);
    return std::string(dt);
}
