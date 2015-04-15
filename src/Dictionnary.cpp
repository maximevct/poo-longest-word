#include "Dictionnary.hh"

Dictionnary::Dictionnary(const std::string &filename) : _filename(filename) {
  _letterWeight = {
    {'e', 1  },  {'a', 2  },  {'s', 3  },  {'i', 4  },  {'r', 5  },  {'t', 6  },
    {'n', 7  },  {'o', 8  },  {'u', 9  },  {'l', 10 },  {'c', 11 },  {'m', 12 },
    {'p', 13 },  {'d', 14 },  {'g', 15 },  {'b', 16 },  {'f', 17 },  {'h', 18 },
    {'z', 19 },  {'v', 20 },  {'q', 21 },  {'y', 22 },  {'x', 23 },  {'j', 24 },
    {'k', 25 },  {'w', 26 }
  };
  _scrabbleWeigth = {
    {'a', 1 }, {'e', 1 }, {'i', 1 }, {'l', 1 }, {'n', 1 }, {'o', 1 }, {'r', 1 }, {'s', 1 }, {'t', 1 }, {'u', 1 },
    {'d', 2 }, {'g', 2 }, {'m', 2 },
    {'b', 3 }, {'c', 3 }, {'p', 3 },
    {'f', 4 }, {'h', 4 }, {'v', 4 },
    {'j', 8 }, {'q', 8 },
    {'k', 10}, {'w', 10}, {'x', 10}, {'y', 10}, {'z', 10}
  };
  _statsByLetter.resize(26);
  _wordlistBySize.resize(10);
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
  int i = 0;
  while (file) {
    std::string line;
    if (getline(file, line)) {
      std::cout << std::setw(3) << ((++i * 100) / 215024) <<  "%\b\b\b\b";
      _statsByLetter[line[0] - 'a']++;
      _totalWords++;
      _wordlist.push_back(line);
      _wordlistBySize[line.size() - 1].push_back(new Word(line, _letterWeight, _scrabbleWeigth));
    }
  }
  std::cout << "Termine" << std::endl;
}

void Dictionnary::menu() {
  _menu->show();
}

void Dictionnary::findWord() {
  std::string toFind = _menu->getString("Entrez le mot a chercher");
  size_t size = toFind.size() - 1;
  if (size > _wordlistBySize.size() || size < 2) {
    std::cout << "Le nombre de lettres doit etre de 2 a 10, reessayez" << std::endl;
    return findWord();
  }
  for (size_t i = 0; i < _wordlistBySize[size].size(); ++i) {
    if (_wordlistBySize[size][i]->getWord() == toFind) {
      _wordlistBySize[size][i]->displayFull();
      return;
    }
  }
  std::cout << "Aucun mot n'a ete trouve" << std::endl;
}

void Dictionnary::findLongestWord(const std::string &letters) {
  Word *toFind = new Word(letters, _letterWeight, _scrabbleWeigth);
  std::string _firstLettersToFind = toFind->getFirstLetters();
  std::vector<Word *> possibilities;
  for (size_t size = toFind->getWord().size(); size > 1; size--) {
    possibilities = findWordBeginWith(toFind, size);
    if (possibilities.size())
      compareWords(possibilities, toFind);
  }
}

int Dictionnary::compareWords(std::vector<Word *> &words, Word *toFind) {
  int i = 0;
  std::string letters = toFind->getWordOrdered();
  for (Word *w : words) {
    if (toFind->isComposedOf(w->getWordOrdered())) {
      i++;
      std::cout << w->getWord() << std::endl;
    }
  }
  return i;
 }

std::vector<Word *> Dictionnary::findWordBeginWith(Word *letters, size_t size) {
  std::vector<Word *> possibilities;
  for (Word *w : _wordlistBySize[size - 1]) {
    if (letters->isComposedOf(w->getFirstLetters()))
      possibilities.push_back(w);
  }
  return possibilities;
}

void Dictionnary::dispStats() {
  std::cout << "Nombre de mots par lettre" << std::endl;
  int offset = 0;
  while (dispLetterStats(offset, 10))
    offset += 10;
  std::cout << std::endl;
  std::cout << "Nombre de mots par longueur" << std::endl;
  for (size_t i = 0; i < _wordlistBySize.size(); i++)
    std::cout << std::setw(4) << std::setfill('_') << i + 1 << "___|" << std::setfill(' ');
  std::cout << std::endl;
  for (auto &list : _wordlistBySize)
    std::cout << std::setw(6) << list.size() << " |";
  std::cout << "\nTotal : " << _totalWords << std::endl;
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
  for (; i < limit && i + offset < _totalWords; i++) {
    std::cout << std::setw(11) << _wordlist[i + offset] << " |";
    if ((i + 1) % 5 == 0)
      std::cout << "\n";
  }
  std::cout << std::endl;
  return i + offset < _wordlist.size();
}
