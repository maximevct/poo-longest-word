#include "Word.hh"

Word::Word(const std::string &word) : _word(word) {
  _letterWeight = {
    {'a', 1 }, {'e', 1 }, {'i', 1 }, {'l', 1 }, {'n', 1 }, {'o', 1 }, {'r', 1 }, {'s', 1 }, {'t', 1 }, {'u', 1 },
    {'d', 2 }, {'g', 2 }, {'m', 2 },
    {'b', 3 }, {'c', 3 }, {'p', 3 },
    {'f', 4 }, {'h', 4 }, {'v', 4 },
    {'j', 8 }, {'q', 8 },
    {'k', 10}, {'w', 10}, {'x', 10}, {'y', 10}, {'z', 10}
  };
  transformToOrdered();
  transformToUniqueLetters();
  transformToUniqueLettersOrdered();
}

Word::~Word() {}

void Word::transformToUniqueLetters() {
  for (size_t i = 0; i < _word.size(); ++i)
    if (_uniqueLetters.find(_word[i]) == std::string::npos)
      _uniqueLetters.push_back(_word[i]);
}

void Word::transformToUniqueLettersOrdered() {
  _uniqueLettersOrdered = _uniqueLetters;
  std::sort(_uniqueLettersOrdered.begin(), _uniqueLettersOrdered.end());
}

void Word::transformToOrdered() {
  _wordOrdered = _word;
  // std::sort(_wordOrdered.begin(), _wordOrdered.end());
  size_t i = 0;
  while (i + 1 < _wordOrdered.size()) {
    if (_letterWeight[_wordOrdered[i]] < _letterWeight[_wordOrdered[i + 1]]) {
      _wordOrdered[i] = _wordOrdered[i + 1];
      i = 0;
    }
    else
      i++;
  }
}

std::string &

void Word::displayFull() const {
  std::cout << std::setw(25) << "Mot"                    << " : " << _word << "\n"
            << std::setw(25) << "Lettres triees"         << " : " << _wordOrdered << "\n"
            << std::setw(25) << "Lettres uniques"        << " : " << _uniqueLetters << "\n"
            << std::setw(25) << "Lettres uniques triees" << " : " << _uniqueLettersOrdered
            << std::endl;
}

const std::string &Word::getWord() const { return _word; }

const std::string &Word::getWordOrdered() const { return _uniqueLetters; }

const std::string &Word::getWordUniqueLetters() const { return _uniqueLettersOrdered; }

const std::string &Word::getWordUniqueLettersOrdered() const { return _wordOrdered; }

