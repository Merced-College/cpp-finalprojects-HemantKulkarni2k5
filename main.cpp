// Displays the user menu for available password utility options
void displayMenu() {
    cout << "\nPassword Utility Menu:\n";
    cout << "1. Analyze Password Strength\n";
    cout << "2. Generate Secure Password\n";
    cout << "3. Show Recent Passwords\n";
    cout << "4. Exit\n";
    cout << "Enter choice: ";
}

// Calculates password entropy based on character set size and length
double calculateEntropy(const string& password) {
    int pool = 0;
    bool hasLower = false, hasUpper = false, hasDigit = false, hasSpecial = false;

    // Determine which character types are used in the password
    for (char c : password) {
        if (islower(c)) hasLower = true;
        else if (isupper(c)) hasUpper = true;
        else if (isdigit(c)) hasDigit = true;
        else hasSpecial = true;
    }

    // Add to the pool size based on character types found
    if (hasLower) pool += 26;
    if (hasUpper) pool += 26;
    if (hasDigit) pool += 10;
    if (hasSpecial) pool += 32; // Approximate number of special characters

    // Entropy formula: length * log2(pool of possible characters)
    return password.length() * log2(pool);
}

// Builds a frequency map of each character in the password
map<char, int> frequencyAnalysis(const string& password) {
    map<char, int> freq;
    for (char c : password) {
        freq[c]++;  // Increment count for each character
    }
    return freq;
}

// Generates a secure password with optional special characters
string generatePassword(int length, bool includeSpecial) {
    string charset = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    if (includeSpecial) charset += "!@#$%^&*()-_=+[]{}|;:',.<>?/`~";

    string password;
    // Randomly select characters from the character set
    for (int i = 0; i < length; ++i) {
        password += charset[rand() % charset.length()];
    }
    return password;
}
