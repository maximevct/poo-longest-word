#include "Dictionnary.hh"

Dictionnary::Dictionnary(const std::string &filename) : _filename(filename) {
  _statsByLetter.resize(26);
  _statsByLength.resize(10);
  _menu = new Menu<void, Dictionnary>(this, "Menu du dictionnaire");
  _menu->push_back("Chercher un mot"          , &Dictionnary::findWord);
  _menu->push_back("Statistiques"             , &Dictionnary::dispStats);
  _menu->push_back("Lister les mots (par X)"  , &Dictionnary::dispListWordByLimit);
  _menu->push_back("Lister les mots (tous)"   , &Dictionnary::dispListWordFull);

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
      _wordlist.push_back(new Word(line));
    }
  }
}

void Dictionnary::menu() {
  _menu->show();
}

void Dictionnary::findWord() {
  std::string toFind = _menu->getString("Entrez le mot à chercher");
  for (size_t i = 0; i < _wordlist.size(); ++i) {
    if (_wordlist[i]->getWord() == toFind) {
      _wordlist[i]->displayFull();
      return;
    }
  }
}

void Dictionnary::dispStats() {
  int total = 0;
  std::cout << "Nombre de mots par lettre" << std::endl;
  int offset = 0;
  while (dispLetterStats(offset, 10))
    offset += 10;
  std::cout << std::endl;
  std::cout << "Nombre de mots par longueur" << std::endl;
  for (size_t i = 0; i < _statsByLength.size(); i++)
    std::cout << std::setw(4) << std::setfill('_') << i << "___|" << std::setfill(' ');
  std::cout << std::endl;
  for (auto &nbr : _statsByLength) {
    std::cout << std::setw(6) << nbr << " |";
    total += nbr;
  }
  std::cout << "\nTotal : " << total << std::endl;
}

bool Dictionnary::dispLetterStats(size_t offset, size_t limit) {
  unsigned char of = 'a' + offset;
  for (unsigned char c = of; c <= 'z' && c < of + limit; c++)
    std::cout << std::setw(4) << std::setfill('_') << c << "___|" << std::setfill(' ');
  std::cout << std::endl;
  size_t i = 0;
  for (; i < limit && i + offset < _statsByLetter.size(); i++)
    std::cout << std::setw(6) << _statsByLetter[i + offset] << " |";
  std::cout << std::endl;
  for (size_t j = 0; j < limit && j + offset < _statsByLetter.size(); j++)
    std::cout << std::setw(8) << std::setfill('-') << "|" << std::setfill(' ');
  std::cout << std::endl;
  return i + offset < _statsByLetter.size();
}

void Dictionnary::dispListWordByLimit() {
  int limit = _menu->getInt("Nombre de mots a afficher");
  int offset = 0;
  if (limit == 0)
    return;
  if (limit < 0) {
    std::cout << "Le nombre de mots doit etre positif, reessayez" << std::endl;
    return dispListWordByLimit();
  }
  while(dispListWord(offset, limit)) {
    offset += limit;
    std::string entry = _menu->getString("Continuer (y/n)", false);
    if (entry == "n" || entry == "0")
      return ;
  }
}

void Dictionnary::dispListWordFull() {
  dispListWord(0, _wordlist.size());
}

bool Dictionnary::dispListWord(size_t offset, size_t limit) {
  size_t i = 0;
  for (; i < limit && i + offset < _wordlist.size(); i++) {
    std::cout << std::setw(11) << _wordlist[i + offset]->getWord() << " |";
    if ((i + 1) % 5 == 0)
      std::cout << "\n";
  }
  std::cout << std::endl;
  return i + offset < _wordlist.size();
}

const std::vector<int> Dictionnary::getStatsByLetter() const {
  return _statsByLetter;
}

const std::vector<int> Dictionnary::getStatsByLength() const {
  return _statsByLength;
}

const std::vector<Word *> Dictionnary::getWordList() const {
  return _wordlist;
}

std::ostream &operator<<(std::ostream &os, const Dictionnary dict) {
  size_t i = 0;
  for (const auto &elem : dict.getWordList()) {
    os << elem->getWord() << "\n";
    i++;
  }
  os << "\n" << i << " words";
  return os;
}
