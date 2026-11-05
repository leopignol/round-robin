#include <algorithm>
#include <cstdint>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string ordinal(int cardinal){
  return to_string(cardinal) +
    (cardinal == 1 ? "st" :
      (cardinal == 2 ? "nd" :
        (cardinal == 3 ? "rd" :
          "th"
        )
      )
    );
}

struct Contestant {
  uint8_t id;
  string name;
  int8_t score;

  vector<uint8_t> opponents(){
    vector<uint8_t> _opponents;
    for (uint8_t i = 0; i < 8; ++i)
      if (i != id) _opponents.push_back(i);
    return _opponents;
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

int main() {
  srand(0);

  Game game{{}};
  for (uint8_t i = 0; i < 8; ++i)
    game.contestants.push_back(Contestant{i, names[i]});

  for (Contestant &contestant : game.contestants){
    for (uint8_t &opponent : contestant.opponents()){
      bool victory = rand() % 2 == 0;

      contestant.score                 += victory ?  1 : -1;
      game.contestants[opponent].score += victory ? -1 :  1;
    }
  }

  sort(game.contestants.begin(), game.contestants.end(),
    [](const Contestant &left, const Contestant &right){
      return left.score > right.score;
    }
  );

  size_t i = 1;
  for (Contestant &contestant : game.contestants){
    cout << ordinal(i) << ": " << setw(13) << contestant.name << " (#"
         << (unsigned)contestant.id << ") with a score of "
         << (contestant.score > 0 ? " " : "") << (int)contestant.score << endl;
    ++i;
  }

  return 0;
}
