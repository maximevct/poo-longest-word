#include "Dictionnary.hh"

Dictionnary::Dictionnary(const std::string &filename) : _filename(filename) {
  _statsByLetter.resize(26);
  _statsByLength.resize(10);
}

Dictionnary::~Dictionnary() {}

void Dictionnary::load() {
  std::ifstream file(_filename);
  if (!file)
    throw "Unable to open file";
  while (file) {
    std::string line;
    if (getline(file, line)) {
      _statsByLetter[line[0] - 'a']++;
      _statsByLength[line.size() - 1]++;
      _wordlist.push_back(line);
    }
  }
}

const std::vector<int> Dictionnary::getStatsByLetter() const {
  return _statsByLetter;
}

const std::vector<int> Dictionnary::getStatsByLength() const {
  return _statsByLength;
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
