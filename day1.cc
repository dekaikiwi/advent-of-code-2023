#include <iostream>
#include <string>
#include "ctype.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <tuple>
#include <bits/stdc++.h>



using namespace std;

string createNumberFromFirstLastDigitInString(string s) {
   char firstNumber = '\0'; 
   char lastNumber = '\0'; 
   string result = "";

    for (size_t i = 0; i < s.length(); i++) {
        if (isdigit(s[i])) {
            firstNumber = s[i];
            cout << "first: " << firstNumber << endl;
            break;
        }
    }

    if (firstNumber == '\0') {
        throw runtime_error("No first number found for: " + s);
    }

    for (size_t i = s.length() - 1; i >= 0; i--) {
        if (isdigit(s[i])) {
            lastNumber = s[i];
            cout << "last: " << lastNumber << endl;
            break;
        }
    }

    if (lastNumber == '\0') {
        throw runtime_error("No last number found for: " + s);
    }

    result += firstNumber;
    result += lastNumber;

    cout << s << " = " << result << endl;

    return result;
}

int main() {
    std::ifstream Data("day1.txt");
    std::string line;
    int total = 0;

    if (!Data.is_open()) {
        std::cout << "unable to open file" << std::endl;
        exit(1);
    }

    while (std::getline (Data, line)) {
        if (line.empty()) {
            continue;
        }

        string number = createNumberFromFirstLastDigitInString(line);

        total += stoi(number);

        cout << "total: " << total << endl;
    }

    cout << "total: " << total << endl;

    return 0;
}
