#ifndef __Dictionnary_HH__
#define __Dictionnary_HH__

#include <iostream>
#include <fstream>
#include <vector>
#include <list>

#include "Word.hh"
#include "Menu.hpp"

class Dictionnary {
private:
  Menu<void, Dictionnary>         *_menu;
  std::string                     _filename;
  std::vector<std::list<Word *> > _wordlistBySize;

  std::list<Word *> findWordBeginWith(Word *, size_t);
  std::list<Word *> compareWords(std::list<Word *> &, Word *);

public:
  Dictionnary(const std::string &);
  ~Dictionnary();

  void load();

  Word *findWord(Word *);
  std::list<Word *> findPossibleWords(Word *);
  void orderByLength(std::list<Word *> &);
};

#endif
