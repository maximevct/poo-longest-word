# poo-longest-word

## Environnement de développement

  - Système : Ubuntu 14.04 LTS (64 bits)
  - Editeur : Sublime Text 2
  - Compilateur : g++

## Fichiers
  - **src**
    - Dictionnary.cpp
    - Game.cpp
    - Word.cpp
    - main.cpp
  - **include**
    - Chrono.hpp
    - Dictionnary.hh
    - Game.hh
    - Menu.hpp
    - Word.hh
  - **dataset**
    - dictionnary.txt
  - Makefile
  - Readme.md
  - stats.js

### Comment l'utiliser :
```bash
  $ make
  $ ./longest_word dataset/dictionnary.txt
```

### Fonctionnalités :

#### Option 0 : Quitter
Quitte le programme

#### Option 1 : Entrer les lettres de recherches
Permet d'entrer de 2 à 10 lettres minuscules

#### Option 2 : Rechercher le mot le plus long avec les lettres entrées
Recherche et affiche tous les mots qu'il est possible de construire avec les lettres entrées
Les mots sont organisées par taille puis ordre alphabétique. La taille des mots est affichée comme séparateur
Au début de la liste est affiché le temps en millisecondes nécessaire pour la construction de la liste de mots
A la fin de la liste est affiché le nombre de mots qui ont étés entièrement testés ainsi que le nombre de mots dans la liste

#### Option 3 : Rechercher le mot le plus fort au scrabble avec les lettres entrées
Recherche et affiche tous les mots qu'il est possible de construire avec les lettres entrées
Les mots sont organisées par leur nombre de points au Scrabble puis par ordre alphabétique. Les points des mots sont affichés comme séparateurs. 
Au début de la liste est affiché le temps en millisecondes nécessaire pour la construction de la liste de mots
A la fin de la liste est affiché le nombre de mots qui ont étés entièrement testés ainsi que le nombre de mots dans la liste

#### Option 4 : Rechercher un mot exact
Recherche et affiche le mot entré. L'affichage permet de voir :
  - Les lettres du mot ordonnées par leur rareté
  - Les deux lettres les plus rares du mot
  - Le nombre de points rapportés par ce mot au scrabble

#### Stats.js
```bash
 $ node stats.js
```

Ce script affiche une liste de lettres ordonnée par le nombre d'occurences des lettres dans le dictionnaire. Il permet de voir quelles lettres sont les plus rares des plus communes

### Auteur 
Maxime VINCENT
