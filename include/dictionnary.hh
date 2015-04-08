#ifndef __DICTIONNARY_HH__
#define __DICTIONNARY_HH__

#include <iostream>
#include <fstream>
#include <vector>

class dictionnary {
private:
  std::string               _filename;
  std::vector<std::string>  _wordlist;
public:
  dictionnary(const std::string &);
  ~dictionnary();

  void load();
  const std::vector<std::string> getWordList() const;

  friend std::ostream &operator<<(std::ostream &, const dictionnary);

};

#endif
