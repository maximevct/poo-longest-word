#include "dictionnary.hh"

dictionnary::dictionnary(const std::string &filename) : _filename(filename) {

}

dictionnary::~dictionnary() {}

void dictionnary::load() {
  std::ifstream file(_filename);
  if (!file)
    throw "Unable to open file";
  while (file) {
    std::string line;
    if (getline(file, line))
      _wordlist.push_back(line);
  }
}

const std::vector<std::string> dictionnary::getWordList() const {
  return _wordlist;
}

std::ostream &operator<<(std::ostream &os, const dictionnary dict) {
  size_t i = 0;
  for (const auto &word : dict.getWordList()) {
    os << word << "\n";
    i++;
  }
  os << "\n" << i << " words";
  return os;
}
