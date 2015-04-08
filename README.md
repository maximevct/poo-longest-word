# poo-longest-word

## Cours
  -

## Idées
  - Mettre tous les mots dans le meme ordre pour comparer les lettres directement
  - Ne pas avoir peur de mettre beaucoup de listes différentes
  - Filtre de bloom
  - Opérateurs binaire : & (et), | (ou), tilde (negation), ^ xor (ou exclusif)
  - std::vector<bool> stocke des tableaux de bits au lieu de tableau de booleens
  - a << 3
    - Décalage vers <-
    - a      = 10110111
    - a << 1 = 01101110
    - a << 3 = 10111000
    - Décale les bits
  - a >> 1, meme chose mais de l'autre coté (Décalage vers ->)
    - Si a est signé, on garde le bit de signe
    - Sinon, c'est un zéro qui rentre

  - Pour flipper le bit à la 4ème position : a ^= (1 << 4)
    - 1 = 00000001
    - 1 << 4 = 00010000
    - Le ou exlcusif modifie le bit désiré

  - Pour mettre à 1 le bit à la 4ème position : a = (a & ~(1 << 4)) | (1 << 3)
    - 1 = 00000001
    - 1 << 4 = 00010000
    - Le ou exlcusif modifie le bit désiré


### filtres
  - Premiere lettre -> vecteur de 27 booleens
  - Taille maximum du mot -> vecteur de 10 booleens

  - Réduire les mots (pas de repetition de lettres) et les classer dans l'ordre alpahbetique
  - Transformer les mots en binaire : APPLE = AELPP = 1, 5, 12, 16, 16



## Steps :
  - Load dictionnary DONE
  - Create main menu
  - Get letters
  - Display result
  - First brute force algorithm
  - Implements unit tests
  - Create bloom filters
  - Implement algorithm
