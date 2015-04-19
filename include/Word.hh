#ifndef __WORD_HH__
#define __WORD_HH__

#include <string>
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <map>

class Word {
  private:
  std::string  _word;
  std::string  _wordOrdered;
  std::string  _firstLetters;
  size_t       _points;
  size_t       _scrabblePoints;

  /**
   * Point par lettre du scrabble
   */
  static std::map<char, int> _scrabbleWeigth;

  /**
   * Point d'une lettre calculé par rapport à son occurence dans la totalité des mots
   * Généré par `node stats.js`
   */
  static std::map<char, int> _letterWeigth;

  /**
   * Crée un mot ordonné par le nombre d'occurences de lettres (_letterWeigth)
   * Si le mot est composé de 7 lettres ou plus, il gagne 50 points au scrabble
   */
  void sortByWeight();
public:
  /**
   * Initialise les points à zéro puis ordonne le mot
   */
  Word(const std::string &);
  ~Word();

  /**
   * Getters
   */
  const std::string &getWord()            const;
  const size_t      &getPoints()          const;
  const size_t      &getScrabblePoints()  const;
  const std::string &getWordOrdered()     const;
  const std::string &getFirstLetters()    const;

  /**
   * Affiche toutes les informations disponnibles pour un mot
   */
  void displayFull() const;

  /**
   * Vérifie que le mot est bien composé des lettres données en paramètre
   * @param  letters Lettres dont il faut tester la présence
   * @return         True si toutes les lettres sont bien présentes une fois dans le mot
   */
  bool isComposedOf(const std::string &) const;
};

#endif
