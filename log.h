#ifndef LOG_H
#define LOG_H

#include <map>
#include <string>
#include <vector>

using namespace std;

class Log {
public:
  Log();
  void debug(const string message);
  string mapToString(map<string, int> m);
  string vectorToString(vector<map<string, int>> v);
};

#endif
