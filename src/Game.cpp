#include "Game.hh"

Game::Game(const std::string &filename) {
  std::cout << "Veuillez patientez, creation du dictionnaire en cours ... ";
  _dict = new Dictionnary(filename);
  _menu = new Menu<void, Game>(this, "Menu principal");
  _menu->push_back("Entrer les lettres"                       , &Game::enterLetters);
  _menu->push_back("Obtenir le mot le plus long"              , &Game::getLongestWord);
  _menu->push_back("Obtenir le meilleur mot pour le scrabble" , &Game::getScrabbleWord);
  _menu->push_back("Chercher un mot"                          , &Game::findWord);
}

Game::~Game() {
  delete _menu;
  delete _dict;
}

void Game::launch() {
  _dict->load();
  _menu->show();
}

void Game::enterLetters() {
  std::string letters = _menu->getString("Entrez entre 1 et 10 lettres");
  if (letters == "0")
    return ;
  if (letters.size() > 10) {
    std::cout << "Erreur : Le nombre de lettres doit etre inférieur à 10" << std::endl;
    return enterLetters();
  }
  for (char &c : letters) {
    if (c >= 'A' && c <= 'Z')
      c += 32;
    if (c < 'a' || c > 'z') {
      std::cout << "Erreur : Utilisez uniquement des caractères alphabétiques" << std::endl;
      return enterLetters();
    }
  }
  _letters = letters;
  _possibilities.clear();
  _menu->setTitle("Menu principal (Lettres : " + letters + ")");
  std::cout << "Vous avez choisi les lettres : " << letters << std::endl;
}

void Game::getLongestWord() {
  if (!_letters.size()) {
    std::cout << "Vous devez d'abord entrer des lettres" << std::endl;
    return enterLetters();
  }
  if (_possibilities.size() == 0)
    _possibilities = _dict->findPossibleWords(new Word(_letters));
  _dict->orderByLength(_possibilities);
  displayList();
}

void Game::getScrabbleWord() {
  std::cout << "Non implémenté" << std::endl;
}

void Game::findWord() {
  std::string toFind = _menu->getString("Entrez le mot a chercher");
  size_t size = toFind.size() - 1;
  if (size > 10 || size < 2) {
    std::cout << "Le nombre de lettres doit etre de 2 a 10, reessayez" << std::endl;
    return findWord();
  }
  Word *w = _dict->findWord(new Word(toFind));
  if (w)
    w->displayFull();
  else
    std::cout << "Aucun mot n'a ete trouve" << std::endl;
}

void Game::displayList() {
  for (Word *w : _possibilities) {
    std::cout << w->getWord() << std::endl;
  }
}
