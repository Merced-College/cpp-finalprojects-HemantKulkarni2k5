#include "PasswordGenerator.h"
#include <cstdlib>
#include <ctime>
#include <string>

PasswordGenerator::PasswordGenerator(int len, bool special)
    : length(len), includeSpecial(special) {
    std::srand(std::time(nullptr));
}

std::string PasswordGenerator::generate() {
    std::string charset = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    if (includeSpecial)
        charset += "!@#$%^&*()-_=+[{]}\\|;:'\",<.>/?`~";

    std::string result;
    for (int i = 0; i < length; ++i) {
        result += charset[std::rand() % charset.size()];
    }
    return result;
}
