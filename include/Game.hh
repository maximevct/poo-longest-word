#ifndef __GAME_HH__
#define __GAME_HH__

#include <iomanip>
#include <list>

#include "Menu.hpp"
#include "Dictionnary.hh"
#include "Word.hh"

class Game {
private:
  Menu<void, Game> *_menu;
  Dictionnary      *_dict;
  std::string       _letters;
  std::list<Word *> _possibilities;

  /**
   * Vérifie que des lettres de recherche sont bien entrées
   * Si la liste des mots compatibles est vide, créée une nouvelle liste avec la recherche
   * @return (bool) true si la liste a ete remplie et est a jour
   */
  bool getPossibilities();

  /**
   * Affiche la liste des mots par points ou par taille
   * (Si par points, les mots ayant 0 points ne seront pas affichés)
   * @param withPoints true si on veut afficher les points
   */
  void displayList(bool = false);
public:
  /**
   * Creation de l'objet dictionnaire
   * Creation du menu
   */
  Game(const std::string &);

  /**
   * Suppression du dictionnaire et du menu créés
   */
  ~Game();

  /**
   * Chargement du dictionnaire
   * Affichage du menu
   */
  void launch();

  /**
   * Demande à l'utilisateur d'entrer entre 1 et 10 lettres (converti les majuscules en minuscules)
   * Vide la liste des mots
   * Change le titre pour afficher les lettres de recherche courantes
   */
  void enterLetters();

  /**
   * Ordonne les mots par longueur puis les affiche
   */
  void getLongestWord();

  /**
   * Ordonne les mots par points puis les affiche
   */
  void getScrabbleWord();


  /**
   * Trouve un mot exact dans le dictionnaire puis affiche toutes ses informations
   */
  void findWord();
};

#endif
