#ifndef __Dictionnary_HH__
#define __Dictionnary_HH__

#include <iostream>
#include <fstream>
#include <vector>

#include "Word.hh"
#include "Menu.hpp"

class Dictionnary {
private:
  Menu<void, Dictionnary>           *_menu;
  std::string                        _filename;
  std::vector<std::vector<Word *> >  _wordlistBySize;
  std::vector<std::string>           _wordlist;
  std::vector<int>                   _statsByLetter;
  size_t                             _totalWords;

  std::map<char, int> _letterWeight;
  std::map<char, int> _scrabbleWeigth;


  std::vector<Word *> findWordBeginWith(Word *, size_t);
  int compareWords(std::vector<Word *> &, Word *);
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

  void findLongestWord(const std::string &);
};

#endif
