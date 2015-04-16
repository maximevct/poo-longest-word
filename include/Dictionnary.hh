#ifndef __Dictionnary_HH__
#define __Dictionnary_HH__

#include <iostream>
#include <fstream>
#include <vector>
#include <list>

#include "Word.hh"
#include "Menu.hpp"

class Dictionnary {
private:
  Menu<void, Dictionnary>         *_menu;
  std::string                     _filename;
  std::vector<std::list<Word *> > _wordlistBySize;

  /**
   * Crée une liste avec tous les mots qui commencent par les lettres de recherche
   */
  std::list<Word *> findWordBeginWith(Word *, size_t);

  /**
   * Crée une liste des mots qu'il est possible de créer en comparant une liste de
   * mots possibles et les lettres d'origine
   */
  std::list<Word *> compareWords(std::list<Word *> &, Word *);

public:
  /**
   * Créer un vector de taille 10 pour chaque taille de mot
   */
  Dictionnary(const std::string &);
  ~Dictionnary();

  /**
   * Charge les mots du dictionnaire par leur taille
   */
  void load();

  /**
   * Trouve le mot exact entré en paramètre en parcourant la liste des mots de la meme taille
   * @param  toFind Mot a trouver
   * @return        Mot trouve ou NULL si aucun n'est trouve
   */
  Word *findWord(Word *);

  /**
   * Crée une liste des mots qu'il est possible de créer avec les lettres entrées
   */
  std::list<Word *> findPossibleWords(Word *);

  /**
   * Ordonne la liste de mots donnée par leur taille
   * @param l Liste de mots a ordonner
   */
  void orderByLength(std::list<Word *> &);

  /**
   * Ordonne la liste de mots donnée par leurs points
   * @param l Liste de mots a ordonner
   */
  void orderByPoints(std::list<Word *> &);
};

#endif
