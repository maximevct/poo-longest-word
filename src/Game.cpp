#include "Game.hh"

Game::Game(const std::string &filename) {
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
  std::cout << "Veuillez patientez, creation du dictionnaire en cours ... " << std::flush;
  _chrono.start();
  try {
    _dict->load();
    std::cout << "\r                                                          \r";
  }
  catch (std::string e) {
    std::cout << "\r                                                          \r";
    std::cout << e << std::endl;
  }
  _chrono.stop();
  std::cout << "Dictionnaire généré en : "
            << (_chrono.getMilliseconds() / 1000) << ","
            << (_chrono.getMilliseconds() % 1000) << " s"
            << std::endl;
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
  _chrono.start();
  if (getPossibilities()) {
    _dict->orderByLength(_possibilities);
    _chrono.stop();
    std::cout << "Resultat obtenu en : "
              << (_chrono.getMicroseconds() / 1000) << ","
              << (_chrono.getMicroseconds() % 1000) << " ms"
              << std::endl;
    displayList();
  }
}

void Game::getScrabbleWord() {
  _chrono.start();
  if (getPossibilities()) {
    _dict->orderByPoints(_possibilities);
    _chrono.stop();
    std::cout << "Resultat obtenu en : "
              << (_chrono.getMicroseconds() / 1000) << ","
              << (_chrono.getMicroseconds() % 1000) << " ms"
              << std::endl;
    displayList(true);
  }
}

bool Game::getPossibilities() {
  if (!_letters.size()) {
    std::cout << "Vous devez d'abord entrer des lettres" << std::endl;
    return false;
  }
  if (_possibilities.size() == 0)
    _possibilities = _dict->findPossibleWords(new Word(_letters));
  return true;
}

void Game::findWord() {
  std::string toFind = _menu->getString("Entrez le mot a chercher");
  if (toFind == "0")
    return;
  size_t size = toFind.size() - 1;
  if (size > 10 || size < 2) {
    std::cout << "Le nombre de lettres doit etre de 2 a 10, reessayez" << std::endl;
    return findWord();
  }
  Word *w = _dict->findWord(new Word(toFind));
  if (w) {
    w->displayFull();
    delete w;
  }
  else
    std::cout << "Aucun mot n'a ete trouve" << std::endl;
}

void Game::displayList(bool withPoints) {
  int i = 0;
  int col = 0;
  size_t old_sep = 999;
  for (Word *w : _possibilities) {
    size_t new_sep = withPoints ? w->getPoints() : w->getWord().size();
    if (new_sep == 0)
      break;
    if (new_sep != old_sep) {
      old_sep = new_sep;
      if (i != 0)
        std::cout << "\n";
      if (col % 5 != 0)
        std::cout << "\n";
      std::cout << (withPoints ? "Points" : " Taille") << " : " << new_sep << std::endl;
      col = 0;
    }
    std::cout << std::setw(10) << w->getWord() << " | ";
    i++;
    col++;
    if ((col % 5) == 0)
      std::cout << "\n";
  }
  std::cout << "\nNombre de mots testés  : " << _dict->getLastTestedNbrWords() << std::endl;
  std::cout << "Nombre de mots valides : " << i << std::endl;
}
