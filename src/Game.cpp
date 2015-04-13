#include "Game.hh"

Game::Game(const std::string &filename) {
  std::cout << "Veuillez patientez, creation du dictionnaire en cours ... " << std::flush;
  _dict = new Dictionnary(filename);
  std::cout << "\r               ";
  _menu = new Menu<void, Game>(this, "Menu principal");
  _menu->push_back("Entrer les lettres"                       , &Game::enterLetters);
  _menu->push_back("Obtenir le mot le plus long"              , &Game::getLongestWord);
  _menu->push_back("Obtenir le meilleur mot pour le scrabble" , &Game::getScrabbleWord);
  _menu->push_back("Entrer dans le dictionnaire"              , &Game::dispDictionnary);
}

Game::~Game() {}

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
  _menu->setTitle("Menu principal (Lettres : " + _letters + ")");
  std::cout << "Vous avez choisi les lettres : " << letters << std::endl;
}

void Game::getLongestWord() {
  std::cout << "Non implémenté" << std::endl;
}

void Game::getScrabbleWord() {
  std::cout << "Non implémenté" << std::endl;
}

void Game::dispDictionnary() {
  _dict->menu();
}
