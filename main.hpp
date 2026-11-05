#include <algorithm>
#include <cctype>
#include <cstdint>
#include <cstdlib>
#include <string>
#include <vector>

#pragma once

using namespace std;

enum GameType {
  HEADS_OR_TAILS,
  ROCK_PAPER_SCISSORS
};

enum HT {
  HEADS, TAILS
};

enum RPS {
  ROCK, PAPER, SCISSORS
};

struct Contestant {
  string name;
  int8_t score = 0;

  vector<Contestant> opponents(const vector<Contestant> &contestants){
    vector<Contestant> _contestants;
    copy_if(
      contestants.begin(),
      contestants.end(),
      back_inserter(_contestants),
      [this](const Contestant &c){
        return c.name != name;
      }
    );
    return _contestants;
  }
};

string input();
