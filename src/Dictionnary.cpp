#include "Dictionnary.hh"

Dictionnary::Dictionnary(const std::string &filename) : _filename(filename) {
  _wordlistBySize.resize(10);
}

Dictionnary::~Dictionnary() {}

void Dictionnary::load() {
  std::ifstream file(_filename);
  if (!file)
    throw "Unable to open file";
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
  for (size_t size = toFind->getWord().size(); size > 1; size--) {
    std::list<Word *> res = findWordBeginWith(toFind, size);
    if (res.size())
      possibilities.splice(possibilities.end(), compareWords(res, toFind));
  }
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
