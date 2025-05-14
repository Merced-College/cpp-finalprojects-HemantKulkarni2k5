#ifndef PASSWORD_ANALYZER_H
#define PASSWORD_ANALYZER_H

#include <string>

class PasswordAnalyzer {
public:
    static void analyzePassword(const std::string& password);
    static double calculateEntropy(const std::string& password);
};

#endif
