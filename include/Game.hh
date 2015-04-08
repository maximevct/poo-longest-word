#ifndef __GAME_HH__
#define __GAME_HH__

#include "Menu.hpp"

class Game {
private:
  Menu<void, Game> *_menu;
public:
  Game();
  ~Game();

  void launch();

  void enterLetters();
  void getLongestWord();
  void getScrabbleWord();
};

#endif
