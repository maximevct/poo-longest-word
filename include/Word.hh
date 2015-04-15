#ifndef __WORD_HH__
#define __WORD_HH__

#include <string>
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <map>

class Word {
  private:
  std::string  _word;
  std::string  _uniqueLetters;
  std::string  _wordOrdered;
  std::string  _firstLetters;
  static std::map<char, int> _scrabbleWeigth;
  static std::map<char, int> _letterWeigth;

  void transformToOrdered();

  std::string sortByWeight(const std::string &);
public:
  Word(const std::string &);
  ~Word();

  const std::string &getWord() const;
  const std::string &getWordOrdered() const;
  const std::string &getFirstLetters() const;


  void displayFull() const;
  bool isComposedOf(const std::string &) const;
};

#endif
