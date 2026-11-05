#include "main.hpp"

#include <algorithm>
#include <cctype>
#include <cstdint>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string input(){
  string val;
  while (val.empty() || val[0] == '#')
    getline(cin, val);
  for (char &c : val)
    c = tolower(c);
  return val;
}

int main() {
  string game = input();

  GameType gameType;
  if (game == "heads or tails")
    gameType = GameType::HEADS_OR_TAILS;
  else if (game == "rock paper scissors")
    gameType = GameType::ROCK_PAPER_SCISSORS;
  else {
    cerr << "Unknown game type" << endl;
    exit(1);
  }

  size_t longestName = 0;
  // Initialize game with contestants
  vector<Contestant> contestants;
  for (uint8_t i = 0; i < 8; ++i){
    string name;
    while (name.empty() || name[0] == '#')
      getline(cin, name);
    longestName = max(name.size(), longestName);
    contestants.push_back(Contestant{name});
  }

  // Each contestant plays against all 7 others
  for (Contestant &contestant : contestants){
    for (Contestant &opponent : contestant.opponents(contestants)){
      switch (gameType) {
      case HEADS_OR_TAILS: {
        // Contestant guess, opponent takes opposite
        string inputGuess = input();
        HT guess;
        if      (inputGuess == "heads") guess = HT::HEADS;
        else if (inputGuess == "tails") guess = HT::TAILS;
        else {
          cerr << "Expected \"heads\" or \"tails\", got \"" << inputGuess << "\"." << endl;
          exit(1);
        }

        // Result
        string inputResult = input();
        HT result;
        if      (inputResult == "heads") result = HT::HEADS;
        else if (inputResult == "tails") result = HT::TAILS;
        else {
          cerr << "Expected \"heads\" or \"tails\", got \"" << inputGuess << "\"." << endl;
          exit(1);
        }

        bool victory = (guess == result);
        if (inputGuess == "edge") victory = false;

        // Modify scores
        contestant.score += victory ?  1 : -1;
        opponent.score   += victory ? -1 :  1;
        break;
      }
      case ROCK_PAPER_SCISSORS: {
        string inputGuessC = input();
        string inputGuessO = input();

        // Contestant move
        RPS guessC;
        if      (inputGuessC == "rock")     guessC = RPS::ROCK;
        else if (inputGuessC == "paper")    guessC = RPS::PAPER;
        else if (inputGuessC == "scissors") guessC = RPS::SCISSORS;
        else {
          cerr << "Expected \"rock\", \"paper\" or \"scissors\", got \""
               << inputGuessC << "\"." << endl;
          exit(1);
        }

        // Opponent move
        RPS guessO;
        if      (inputGuessO == "rock")     guessO = RPS::ROCK;
        else if (inputGuessO == "paper")    guessO = RPS::PAPER;
        else if (inputGuessO == "scissors") guessO = RPS::SCISSORS;
        else {
          cerr
            << "Expected \"rock\", \"paper\" or \"scissors\", got \""
            << inputGuessC << "\"." << endl;
          exit(1);
        }

        // Tie doesn't do anything
        if (guessC == guessO) break;
        bool victory = false;
        if      (guessC == RPS::ROCK     && guessO == RPS::SCISSORS) victory = true;
        else if (guessC == RPS::PAPER    && guessO == RPS::ROCK    ) victory = true;
        else if (guessC == RPS::SCISSORS && guessO == RPS::PAPER   ) victory = true;

        // Modify scores
        contestant.score += victory ?  1 : -1;
        opponent.score   += victory ? -1 :  1;
        break;
      }
      }
    }
  }

  // Sort contestants based on score
  sort(contestants.begin(), contestants.end(),
    [](const Contestant &left, const Contestant &right){
      return left.score > right.score;
    }
  );

  // Display results
  size_t placement = 0;
  for (const Contestant &contestant : contestants)
    cout << setw(longestName) << contestant.name << ": " << ++placement << endl;

  return 0;
}
