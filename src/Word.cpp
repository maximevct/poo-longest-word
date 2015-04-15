#include "Word.hh"

std::map<char, int> Word::_scrabbleWeigth = {
  {'a', 1 }, {'e', 1 }, {'i', 1 }, {'l', 1 }, {'n', 1 }, {'o', 1 }, {'r', 1 }, {'s', 1 }, {'t', 1 }, {'u', 1 },
  {'d', 2 }, {'g', 2 }, {'m', 2 },
  {'b', 3 }, {'c', 3 }, {'p', 3 },
  {'f', 4 }, {'h', 4 }, {'v', 4 },
  {'j', 8 }, {'q', 8 },
  {'k', 10}, {'w', 10}, {'x', 10}, {'y', 10}, {'z', 10}
};

Word::Word(const std::string &word) : _word(word) {
  transformToOrdered();
}

Word::~Word() {}

void Word::transformToOrdered() {
  _wordOrdered = sortByWeight(_word);
}

bool Word::isComposedOf(const std::string &letters) const {
  size_t j = 0;
  for (size_t i = 0; i < _wordOrdered.size() && j < letters.size(); i++)
    if (letters[j] == _wordOrdered[i])
      j++;
  return j == letters.size();
}

std::string Word::sortByWeight(const std::string &src) {
  std::string dest(src);
  std::sort(dest.begin(), dest.end(), Sort());
  _firstLetters = dest.substr(0, 2);
  return dest;
}

void Word::displayFull() const {
  std::cout << std::setw(25) << "Mot"                    << " : " << _word          << "\n"
            << std::setw(25) << "Lettres triees"         << " : " << _wordOrdered   << "\n"
            << std::setw(25) << "Premieres lettres"      << " : " << _firstLetters  << "\n"
            << std::endl;
}

const std::string &Word::getWord() const { return _word; }

const std::string &Word::getWordOrdered() const { return _wordOrdered; }

const std::string &Word::getFirstLetters() const { return _firstLetters; }

