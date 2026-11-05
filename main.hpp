#include <algorithm>
#include <cctype>
#include <cstdint>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

#pragma once

using namespace std;

string ordinal(int cardinal);

struct Contestant {
  uint8_t id;
  string name;
  int8_t score;
  vector<uint8_t> opponents = this->_opponents();

  private:
  vector<uint8_t> _opponents(){
    vector<uint8_t> __opponents;
    for (uint8_t i = 0; i < 8; ++i)
      if (i != id) __opponents.push_back(i);
    return __opponents;
  }
};

struct Game {
  vector<Contestant> contestants;
};

const vector<string> names = {
  "Abdelkader", "Alain",
  "Mickael", "Nassim",
  "Laurence", "Laurent",
  "Pierre-Alexis", "Pierrick"
};
