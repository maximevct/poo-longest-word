#ifndef __WORD_HH__
#define __WORD_HH__

#include <string>
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <map>

class Word {
  private:
  std::string _word;
  std::string _uniqueLetters;
  std::string _uniqueLettersOrdered;
  std::string _wordOrdered;
  std::string _firstLetters;

  void transformToUniqueLetters();
  void transformToUniqueLettersOrdered(std::map<char, int> &);
  void transformToOrdered(std::map<char, int> &);

  std::string sortByWeight(const std::string &, std::map<char, int> &);
public:
  Word(const std::string &, std::map<char, int> &, std::map<char, int> &);
  ~Word();

  const std::string &getWord() const;
  const std::string &getWordOrdered() const;
  const std::string &getWordUniqueLetters() const;
  const std::string &getWordUniqueLettersOrdered() const;
  const std::string &getFirstLetters() const;


  void displayFull() const;
  bool isComposedOf(const std::string &) const;
};

#endif
