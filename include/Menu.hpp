#ifndef MENU_HH
#define MENU_HH

#include <vector>
#include <string>
#include <iostream>
#include <iomanip>

/**
 * Menu template
 */
template<typename T, typename U>
class Menu {
  std::vector<std::string> _listChoices;
  std::vector<T (U::*)()>  _listFunctions;
  U                        *_context;
  std::string              _title;
public:
  /**
   * Met le contexte
   * Ajoute le choix retour corespondant à NULL
   */
  Menu(U *context, const std::string &title)
    : _title(title) {
    _context = context;
    _listChoices.push_back("Retour");
    _listFunctions.push_back(NULL);
  }
  ~Menu() {}

  /**
   * Ajoute un choix au menu
   *   - Un texte
   *   - Une fonction
   */
  void push_back(const std::string &choice, T (U::*func)()) {
    _listChoices.push_back(choice);
    _listFunctions.push_back(func);
  }

  /**
   * Modifie le titre du menu
   */
  void setTitle(const std::string &title) {
    _title = title;
  }

  /**
   * Récupere une chaine de caractère entré par l'utilisateur
   * L'utilisateur peut entrer 0 pour quitter
   * La chaine ne peut etre vide (recommence sinon)
   * @param  txt   Texte à afficher
   * @param  verif True si la chaine peut etre vide
   * @return       Chaine entrée
   */
  std::string getString(const std::string &txt, bool verif = true) {
    std::cout << txt << " (0 pour quitter): ";
    std::string in;
    std::getline(std::cin, in);
    if (verif && in.length() == 0) {
      std::cout << "Erreur : Ne peut etre vide, reessayez" << std::endl;
      return getString(txt);
    }
    return in;
  }

  /**
   * Récupère un entier entré par l'utilisateur
   * @param  txt texte à afficher
   * @return     Entier entré par l'utilisateur
   */
  int getInt(const std::string &txt) {
    std::cout << txt << " (0 pour quitter): ";
    std::string in;
    std::getline(std::cin, in);
    if (in.length() == 0) {
      std::cout << "Erreur : Ne peut etre vide, reessayez" << std::endl;
      return getInt(txt);
    }
    try {
      int value = std::stoi(in);
      return value;
    }
    catch (...) {
      std::cout << "Erreur : Entree invalide, reessayez" << std::endl;
      return getInt(txt);
    }
  }

  /**
   * Affiche le menu
   * Récupère le choix de l'utilsiateur
   * Exécute la fonction associée à l'entrée
   */
  void show() {
    int entry = -1;
    while (entry != 0) {
      int i = 0;
      std::cout << "\n|------" << _title << std::setfill('-') << std::setw(50 - _title.length()) << "|" << std::setfill(' ') << std::endl;
      for (auto choice : _listChoices) {
        std::cout << "|" << std::setw(4) << i++ << "] " << choice << std::setw(50 - choice.length()) << "|" << std::endl;
      }
      std::cout << "|" << std::setfill('-') << std::setw(56) << "|" << std::setfill(' ') << std::endl;
      std::cout << "Entrez votre choix : ";
      std::string entryStr;
      std::getline(std::cin, entryStr);
      try {
        entry = std::stoi(entryStr);
        if (entry >= (int)_listChoices.size()) {
          throw -1;
        }
        else if (entry) {
          std::cout << std::endl;
          (_context->*_listFunctions[entry])();
        }
      }
      catch (...) {
        std::cout << "Choix invalide" << std::endl;
        entry = -1;
      }
    }
  }
};

#endif // MENU_HH
