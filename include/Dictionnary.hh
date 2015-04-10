#ifndef __Dictionnary_HH__
#define __Dictionnary_HH__

#include <iostream>
#include <fstream>
#include <vector>

class Dictionnary {
private:
  std::string               _filename;
  std::vector<std::string>  _wordlist;
  std::vector<int>         _statsByLetter;
  std::vector<int>         _statsByLength;

public:
  Dictionnary(const std::string &);
  ~Dictionnary();

  void load();
  const std::vector<std::string> getWordList() const;
  const std::vector<int> getStatsByLetter() const;
  const std::vector<int> getStatsByLength() const;

  friend std::ostream &operator<<(std::ostream &, const Dictionnary);

};

#endif
