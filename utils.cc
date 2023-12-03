#include <string>
#include <vector>

using namespace std;

vector<string> split(string s, const string delimeter) {
  size_t from_pos = 0;
  size_t to_pos;
  string token;
  vector<string> tokens;

  while (true) {
    to_pos = s.find(delimeter, from_pos);

    if (to_pos == string::npos) {
      tokens.push_back(s.substr(from_pos));
      break;
    }

    token = s.substr(from_pos, to_pos - from_pos);

    tokens.push_back(token);
    from_pos = to_pos + delimeter.length();
  }

  return tokens;
}

string trim_string(string s) {
  size_t first = s.find_first_not_of(' ');
  size_t last = s.find_last_not_of(' ');

  return s.substr(first, (last - first + 1));
}
