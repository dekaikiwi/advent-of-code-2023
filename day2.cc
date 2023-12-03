#include "log.h"
#include "utils.h"
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <tuple>
#include <vector>

using namespace std;

map<int, map<string, int>> games = {};
Log logger = Log();

bool isGamePossible(vector<map<string, int>> games, map<string, int> blocks) {
  for (map<string, int> game : games) {
    for (auto &[color, count] : game) {
      if (blocks[color] < count) {
        logger.debug("NOT POSSIBLE: " + color + " " + to_string(count) +
                     " exceeds " + to_string(blocks[color]));
        return false;
      }
    }
  }

  return true;
}

map<string, int> lowestRequiredSetOfBlocks(vector<map<string, int>> games) {
  map<string, int> lowest = {};

  for (map<string, int> game : games) {
    for (auto &[color, count] : game) {
      if (lowest[color] < count) {
        lowest[color] = count;
      }
    }
  }

  return lowest;
}

tuple<int, vector<map<string, int>>> parseGameFromString(string s) {
  int game_number;
  map<string, int> game = {};
  vector<map<string, int>> game_draws = {};

  vector<string> number_and_game = split(s, ":");

  game_number = stoi(split(number_and_game[0], " ")[1]);

  vector<string> game_segments = split(number_and_game[1], ";");

  for (string game_segment : game_segments) {
    game_segment = trim_string(game_segment);

    vector<string> game_draws_split = split(game_segment, ", ");

    for (string &draw : game_draws_split) {
      vector<string> count_and_color = split(draw, " ");
      game[count_and_color[1]] = stoi(count_and_color[0]);
      ;
    }

    game_draws.push_back(game);
  }

  return {game_number, game_draws};
}

int main() {
  std::ifstream Data("day2.txt");
  std::string line;
  int total = 0;
  int total_power = 0;

  map<string, int> blocks = {{"red", 12}, {"green", 13}, {"blue", 14}};

  if (!Data.is_open()) {
    std::cout << "unable to open file" << std::endl;
    exit(1);
  }

  while (std::getline(Data, line)) {
    if (line.empty()) {
      continue;
    }

    logger.debug(line);
    auto [game_number, game] = parseGameFromString(line);

    logger.debug("game: " + to_string(game_number) + " " +
                 logger.vectorToString(game));

    if (isGamePossible(game, blocks)) {
      logger.debug("POSSIBLE");
      total += game_number;
    }

    map<string, int> lowest = lowestRequiredSetOfBlocks(game);
    int power = 1;

    for (auto &[color, count] : lowest) {
      power *= count;
    }

    total_power += power;
  }

  cout << "total: " << total << endl;
  cout << "total power: " << total_power << endl;

  return 0;
}
