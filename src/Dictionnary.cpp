#include "Dictionnary.hh"

Dictionnary::Dictionnary(const std::string &filename) : _filename(filename) {

}

Dictionnary::~Dictionnary() {}

void Dictionnary::load() {
  std::ifstream file(_filename);
  if (!file)
    throw "Unable to open file";
  while (file) {
    std::string line;
    if (getline(file, line))
      _wordlist.push_back(line);
  }
}

const std::vector<std::string> Dictionnary::getWordList() const {
  return _wordlist;
}

std::ostream &operator<<(std::ostream &os, const Dictionnary dict) {
  size_t i = 0;
  for (const auto &word : dict.getWordList()) {
    os << word << "\n";
    i++;
  }
  os << "\n" << i << " words";
  return os;
}
