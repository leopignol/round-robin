#include "main.hpp"

#include <algorithm>
#include <cctype>
#include <cstdint>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
#define RAND 0

using namespace std;

string ordinal(int cardinal){
  return to_string(cardinal) +
    (cardinal % 10 == 1 ? "st" :
    (cardinal % 10 == 2 ? "nd" :
    (cardinal % 10 == 3 ? "rd" :
      "th"
    )));
}

int main() {
  // Initialize random on fixed value
  srand(RAND);

  // Initialize game with contestants
  Game game;
  for (uint8_t i = 0; i < 8; ++i)
    game.contestants.push_back(Contestant{i, names[i]});

  for (Contestant &contestant : game.contestants){
    // Each contestant plays against all 7 others
    for (const uint8_t &oid : contestant.opponents){
      Contestant &opponent = game.contestants[oid];

      string strGuess;
      cin >> strGuess;
      for (char &c : strGuess)
        c = tolower(c);

      bool guess;
      if      (strGuess == "heads") guess = true;
      else if (strGuess == "tails") guess = false;
      else {
        cerr << "Expected \"heads\" or \"tails\", got \"" << strGuess << "\"." << endl;
        exit(1);
      }

      // Heads or tails
      bool victory = (guess == (rand() % 2 == 0));

      // Easter egg
      if (strGuess == "edge") victory = false;

      // Modify scores
      contestant.score += victory ?  1 : -1;
      opponent.score   += victory ? -1 :  1;
    }
  }

  // Sort contestants based on score
  sort(game.contestants.begin(), game.contestants.end(),
    [](const Contestant &left, const Contestant &right){
      return left.score > right.score;
    }
  );

  // Display results with ordinal position
  size_t i = 1;
  for (const Contestant &contestant : game.contestants){
    cout
      << ordinal(i) << ":" << setw(14) << contestant.name << " (#"
      << (unsigned)contestant.id << ") with a score of "
      << (contestant.score >= 0 ? " " : "") << (int)contestant.score << endl;
    ++i;
  }

  return 0;
}
