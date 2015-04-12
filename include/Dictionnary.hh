#ifndef __Dictionnary_HH__
#define __Dictionnary_HH__

#include <iostream>
#include <fstream>
#include <vector>

#include "Word.hh"
#include "Menu.hpp"

class Dictionnary {
private:
  Menu<void, Dictionnary> *_menu;
  std::string              _filename;
  std::vector<Word *>      _wordlist;
  std::vector<int>         _statsByLetter;
  std::vector<int>         _statsByLength;

public:
  Dictionnary(const std::string &);
  ~Dictionnary();

  void load();
  void menu();

  void findWord();
  void dispStats();
  void dispListWordByLimit();
  void dispListWordFull();
  bool dispListWord(size_t, size_t);
  bool dispLetterStats(size_t, size_t);

  const std::vector<Word *> getWordList() const;
  const std::vector<int> getStatsByLetter() const;
  const std::vector<int> getStatsByLength() const;

  friend std::ostream &operator<<(std::ostream &, const Dictionnary);

};

#endif
