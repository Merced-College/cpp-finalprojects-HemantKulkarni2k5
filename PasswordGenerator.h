#ifndef PASSWORD_GENERATOR_H
#define PASSWORD_GENERATOR_H

#include <string>

class PasswordGenerator {
private:
    int length;
    bool includeSpecial;

public:
    PasswordGenerator(int len, bool special);
    std::string generate();
};

#endif
