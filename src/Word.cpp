#include "Word.hh"

std::map<char, int> Word::_scrabbleWeigth = {
  {'a', 1 }, {'e', 1 }, {'i', 1 }, {'l', 1 }, {'n', 1 }, {'o', 1 }, {'r', 1 }, {'s', 1 }, {'t', 1 }, {'u', 1 },
  {'d', 2 }, {'g', 2 }, {'m', 2 },
  {'b', 3 }, {'c', 3 }, {'p', 3 },
  {'f', 4 }, {'h', 4 }, {'v', 4 },
  {'j', 8 }, {'q', 8 },
  {'k', 10}, {'w', 10}, {'x', 10}, {'y', 10}, {'z', 10}
};

std::map<char, int> Word::_letterWeigth = {
  {'e', 1  },  {'a', 2  },  {'s', 3  },  {'i', 4  },  {'r', 5  },  {'t', 6  },
  {'n', 7  },  {'o', 8  },  {'u', 9  },  {'l', 10 },  {'c', 11 },  {'m', 12 },
  {'p', 13 },  {'d', 14 },  {'g', 15 },  {'b', 16 },  {'f', 17 },  {'h', 18 },
  {'z', 19 },  {'v', 20 },  {'q', 21 },  {'y', 22 },  {'x', 23 },  {'j', 24 },
  {'k', 25 },  {'w', 26 }
};

Word::Word(const std::string &word) : _word(word) {
  _points = 0;
  _scrabblePoints = (_word.size() >= 7 ? 50 : 0);
  sortByWeight();
  _firstLetters = _wordOrdered.substr(0, 2);
}

Word::~Word() {}

bool Word::isComposedOf(const std::string &letters) const {
  size_t j = 0;
  size_t sizeW = _wordOrdered.size();
  size_t sizeL = letters.size();
  for (size_t i = 0; i < sizeW && j < sizeL; i++)
    if (letters[j] == _wordOrdered[i])
      j++;
  return j == sizeL;
}

void Word::sortByWeight() {
  for (const char &c : _word) {
    int lPoint = Word::_letterWeigth[c];
    _points += lPoint;
    _scrabblePoints += _scrabbleWeigth[c];
    _wordOrdered.insert(std::find_if(_wordOrdered.begin(), _wordOrdered.end(), [&](char &c) {
      return Word::_letterWeigth[c] < lPoint;
    }), c);
  }
}

void Word::displayFull() const {
  std::cout << std::setw(25) << "Mot"                    << " : " << _word                     << "\n"
            << std::setw(25) << "Lettres triees"         << " : " << _wordOrdered              << "\n"
            << std::setw(25) << "Premieres lettres"      << " : " << _wordOrdered.substr(0, 2) << "\n"
            << std::setw(25) << "Points"                 << " : " << _points                   << "\n"
            << std::setw(25) << "Points Scrabble"        << " : " << _scrabblePoints           << "\n"
            << std::endl;
}

const std::string &Word::getWord()            const { return _word;           }
const size_t      &Word::getPoints()          const { return _points;         }
const size_t      &Word::getScrabblePoints()  const { return _scrabblePoints; }
const std::string &Word::getWordOrdered()     const { return _wordOrdered;    }
const std::string &Word::getFirstLetters()    const { return _firstLetters;   }

