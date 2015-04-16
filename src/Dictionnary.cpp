#include "Dictionnary.hh"

Dictionnary::Dictionnary(const std::string &filename) : _filename(filename) {
  _wordlistBySize.resize(10);
  _lastTestedNbrWords = 0;
}

Dictionnary::~Dictionnary() {
  for (auto &v : _wordlistBySize)
    for (auto &w : v)
      delete w;
}

void Dictionnary::load() {
  std::ifstream file(_filename);
  if (!file)
    throw "Impossible d'ouvrir le fichier : " + _filename;
  while (file) {
    std::string line;
    if (getline(file, line))
      _wordlistBySize[line.size() - 1].push_back(new Word(line));
  }
}

Word *Dictionnary::findWord(Word *toFind) {
  std::string toFindStr = toFind->getWord();
  for (Word *w : _wordlistBySize[toFind->getWord().size() - 1]) {
    if (w->getWord() == toFindStr)
      return w;
  }
  return NULL;
}

std::list<Word *> Dictionnary::findPossibleWords(Word *toFind) {
  std::string _firstLettersToFind = toFind->getFirstLetters();
  std::list<Word *> possibilities;
  _lastTestedNbrWords = 0;
  for (size_t size = toFind->getWord().size(); size > 1; size--) {
    std::list<Word *> res = findWordBeginWith(toFind, size);
    _lastTestedNbrWords += res.size();
    if (res.size())
      possibilities.splice(possibilities.end(), compareWords(res, toFind));
  }
  delete toFind;
  return possibilities;
}

std::list<Word *> Dictionnary::compareWords(std::list<Word *> &words, Word *toFind) {
  std::list<Word *> founded;
  for (Word *w : words)
    if (toFind->isComposedOf(w->getWordOrdered()))
      founded.push_back(w);
  return founded;
 }

std::list<Word *> Dictionnary::findWordBeginWith(Word *letters, size_t size) {
  std::list<Word *> possibilities;
  for (Word *w : _wordlistBySize[size - 1]) {
    if (letters->isComposedOf(w->getFirstLetters()))
      possibilities.push_back(w);
  }
  return possibilities;
}

void Dictionnary::orderByLength(std::list<Word *> &l) {
  l.sort([](Word *a, Word *b) -> bool {
    return a->getWord().size() > b->getWord().size();
  });
}

void Dictionnary::orderByPoints(std::list<Word *> &l) {
  l.sort([](Word *a, Word *b) -> bool {
    return a->getPoints() > b->getPoints();
  });
}

int Dictionnary::getLastTestedNbrWords() const {
  return _lastTestedNbrWords;
}
