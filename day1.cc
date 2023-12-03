#include "ctype.h"
#include <fstream>
#include <iostream>
#include <map>
#include <string>

using namespace std;

const map<string, int> wordNumbers = {{"one", 1},   {"two", 2},   {"three", 3},
                                      {"four", 4},  {"five", 5},  {"six", 6},
                                      {"seven", 7}, {"eight", 8}, {"nine", 9}};

string createNumberFromFirstLastDigitInString(string s) {
  char firstNumber = '\0';
  char lastNumber = '\0';
  string result = "";
  map<int, string> numberPositions = {};

  cout << "===== " << s << " =====" << endl;

  // Find instances of words that are written as numbers in the string.
  // make note of the location off these words such that the actual
  // number can be inserted at that location.
  for (auto const &[word, number] : wordNumbers) {
    int searchPosition = 0;

    while (true) {
      size_t pos = s.find(word, searchPosition);
      if (pos == string::npos) {
        break;
      }

      numberPositions.insert({pos, to_string(number)});
      searchPosition = pos + word.length();
    }
  }

  int offset = 0;

  for (auto const &[position, number] : numberPositions) {
    s = s.insert(position + offset, number);
    offset += 1;
  }

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

  while (std::getline(Data, line)) {
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
