#ifndef __WORD_HH__
#define __WORD_HH__

#include <string>
#include <algorithm>
#include <iomanip>
#include <iostream>

class Word {
private:
  std::string _word;
  std::string _uniqueLetters;
  std::string _uniqueLettersOrdered;
  std::string _wordOrdered;

  void transformToUniqueLetters();
  void transformToUniqueLettersOrdered();
  void transformToOrdered();
public:
  Word(const std::string &);
  ~Word();

  const std::string &getWord() const;
  const std::string &getWordOrdered() const;
  const std::string &getWordUniqueLetters() const;
  const std::string &getWordUniqueLettersOrdered() const;

  void displayFull() const;
};

#endif
