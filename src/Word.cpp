#include "Word.hh"

Word::Word(const std::string &word) : _word(word) {
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
  std::sort(_wordOrdered.begin(), _wordOrdered.end());
}

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

