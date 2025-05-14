#ifndef PASSWORD_RECORD_H
#define PASSWORD_RECORD_H

#include <string>

class PasswordRecord {
private:
    std::string password;
    double entropy;
    std::string timestamp;

public:
    PasswordRecord(std::string pwd, double ent, std::string time);
    void display() const;
    static std::string getCurrentTimestamp();
};

#endif
