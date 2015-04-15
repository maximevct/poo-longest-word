#include "Word.hh"

Word::Word(const std::string &word, std::map<char, int> &letterWeight,
  std::map<char, int> &scrabbleWeigth) : _word(word) {

  transformToOrdered(letterWeight);
  transformToUniqueLetters();
  transformToUniqueLettersOrdered(letterWeight);
}

Word::~Word() {}

void Word::transformToUniqueLetters() {
  for (size_t i = 0; i < _word.size(); ++i)
    if (_uniqueLetters.find(_word[i]) == std::string::npos)
      _uniqueLetters.push_back(_word[i]);
}

void Word::transformToUniqueLettersOrdered(std::map<char, int> &letterWeight) {
  _uniqueLettersOrdered = sortByWeight(_uniqueLetters, letterWeight);
  _firstLetters.push_back(_uniqueLettersOrdered[0]);
  if (_uniqueLettersOrdered.size() > 1)
    _firstLetters.push_back(_uniqueLettersOrdered[1]);
}

void Word::transformToOrdered(std::map<char, int> &letterWeight) {
  _wordOrdered = sortByWeight(_word, letterWeight);
}

bool Word::isComposedOf(const std::string &letters) const {
  size_t j = 0;
  for (size_t i = 0; i < _wordOrdered.size() && j < letters.size(); i++)
    if (letters[j] == _wordOrdered[i])
      j++;
  return j == letters.size();
}

std::string Word::sortByWeight(const std::string &src, std::map<char, int> &letterWeight) {
  std::string dest(src);

  size_t i = 0;
  while (i + 1 < dest.size()) {
    if (letterWeight[dest[i]] < letterWeight[dest[i + 1]]) {
      char tmp = dest[i];
      dest[i] = dest[i + 1];
      dest[i + 1] = tmp;
      i = 0;
    }
    else
      i++;
  }
  return dest;
}

void Word::displayFull() const {
  std::cout << std::setw(25) << "Mot"                    << " : " << _word << "\n"
            << std::setw(25) << "Lettres triees"         << " : " << _wordOrdered << "\n"
            << std::setw(25) << "Lettres uniques"        << " : " << _uniqueLetters << "\n"
            << std::setw(25) << "Lettres uniques triees" << " : " << _uniqueLettersOrdered
            << std::endl;
}

const std::string &Word::getWord() const { return _word; }

const std::string &Word::getWordOrdered() const { return _wordOrdered; }

const std::string &Word::getWordUniqueLetters() const { return _uniqueLetters; }

const std::string &Word::getWordUniqueLettersOrdered() const { return _uniqueLettersOrdered; }

const std::string &Word::getFirstLetters() const { return _firstLetters; }

