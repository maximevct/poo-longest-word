#ifndef __Dictionnary_HH__
#define __Dictionnary_HH__

#include <iostream>
#include <fstream>
#include <vector>

class Dictionnary {
private:
  std::string               _filename;
  std::vector<std::string>  _wordlist;
public:
  Dictionnary(const std::string &);
  ~Dictionnary();

  void load();
  const std::vector<std::string> getWordList() const;

  friend std::ostream &operator<<(std::ostream &, const Dictionnary);

};

#endif
