#ifndef __GAME_HH__
#define __GAME_HH__

#include <iomanip>

#include "Menu.hpp"
#include "Dictionnary.hh"
#include "Word.hh"

class Game {
private:
  Menu<void, Game> *_menu;
  Dictionnary      *_dict;
  std::string       _letters;
public:
  Game(const std::string &);
  ~Game();

  void launch();

  void enterLetters();
  void getLongestWord();
  void getScrabbleWord();
  void dispDictionnary();
};

#endif
