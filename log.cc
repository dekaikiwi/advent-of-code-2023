#include "log.h"
#include <iostream>
#include <map>
#include <string>
#include <type_traits>
#include <vector>

using namespace std;

Log::Log() {}

void Log::debug(const string message) { std::cout << message << std::endl; }

string Log::mapToString(map<string, int> m) {
  string result = "{";

  for (auto &[key, value] : m) {
    result += key + ": " + to_string(value) + ", ";
  }

  result += "}";

  return result;
}

string Log::vectorToString(vector<map<string, int>> v) {
  string result = "[";

  for (map<string, int> m : v) {
    result += mapToString(m) + ", ";
  }

  result += "]";

  return result;
}
