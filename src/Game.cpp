#include "Game.hh"

Game::Game() {
  _menu = new Menu<void, Game>(this, "Menu principal");
  _menu->push_back("Entrer les lettres"                       , &Game::enterLetters);
  _menu->push_back("Obtenir le mot le plus long"              , &Game::getLongestWord);
  _menu->push_back("Obtenir le meilleur mot pour le scrabble" , &Game::getScrabbleWord);
}

Game::~Game() {}

void Game::launch() {
  _menu->show();
}

void Game::enterLetters() {
  std::cout << "Non implémenté" << std::endl;
}

void Game::getLongestWord() {
  std::cout << "Non implémenté" << std::endl;
}

void Game::getScrabbleWord() {
  std::cout << "Non implémenté" << std::endl;
}
