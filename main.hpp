#ifndef __ROUND_ROBIN_HPP
#define __ROUND_ROBIN_HPP

#include <cctype>
#include <cstdint>
#include <cstdlib>
#include <functional>
#include <iostream>
#include <string>
#include <vector>

enum HT { HEADS, TAILS };

enum RPS { ROCK, PAPER, SCISSORS };

struct Contestant {
  std::string name;
  uint8_t victories = 0;

  std::vector<std::reference_wrapper<Contestant>>
  opponents(std::vector<Contestant> &contestants) {
    std::vector<std::reference_wrapper<Contestant>> _contestants;
    for (Contestant &c : contestants)
      if (&c != this)
        _contestants.push_back(std::ref(c));
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
