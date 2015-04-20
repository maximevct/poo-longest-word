#include "Word.hh"

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
  static const int scrabbleWeigth[] = { 1, 3, 3, 2, 1, 4, 2, 4, 1, 8,10, 1, 2, 1, 1, 3, 8, 1, 1, 1, 1, 4,10,10,10,10};
  static const int letterWeigth[]   = { 2,16,11,14, 1,17,15,18, 4,24,25,10,12, 7, 8,13,21, 5, 3, 6, 9,20,26,23,22,19};
  for (const char &c : _word) {
    int l = c - 'a';
    int lPoint = letterWeigth[l];
    _points += lPoint;
    _scrabblePoints += scrabbleWeigth[l];
    _wordOrdered.insert(std::find_if(_wordOrdered.begin(), _wordOrdered.end(), [&](char &c) {
      return letterWeigth[c - 'a'] < lPoint;
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

