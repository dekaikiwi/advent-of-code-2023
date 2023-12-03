#include <map>
#include <string>
#include <tuple>
#include <vector>

using namespace std;

bool isGamePossible(vector<map<string, int>> game,
                    const map<string, int> blocks);
tuple<int, vector<map<string, int>>> parseGameFromString(string s);
map<string, int> lowestRequiredSetOfBlocks(vector<map<string, int>> games);
