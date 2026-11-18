#include <algorithm>
#include <cctype>
#include <cstdint>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

#ifndef __ROUND_ROBIN_HPP
#define __ROUND_ROBIN_HPP

enum HT { HEADS, TAILS };

enum RPS { ROCK, PAPER, SCISSORS };

struct Contestant {
  std::string name;
  uint8_t victories = 0;

  std::vector<Contestant>
  opponents(const std::vector<Contestant> &contestants) {
    std::vector<Contestant> _contestants;
    copy_if(contestants.begin(), contestants.end(), back_inserter(_contestants),
            [this](const Contestant &c) { return c.name != this->name; });
    return _contestants;
  }
};

std::string input(bool keepCase = false) {
  std::string val;
  while (val.empty() || val[0] == '#')
    getline(std::cin, val);
  if (!keepCase)
    for (char &c : val)
      c = tolower(c);
  return val;
}

#endif
