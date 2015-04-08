#include <cstdlib> // pour rand
#include <iostream>
#include <iomanip>


//////////////////////////////
//
// Fonction qui va écrire un bit
// dans un tableau (sans faire de
// vérifications de bornes)
//
inline void set_bit(char tableau[], size_t position, int valeur)
 {
  // le position-ème bit est dans l'octet numéro position/8
  // et à la (position%8) place dans cet octet.
  size_t position_octet = position / 8;
  size_t position_bit   = position % 8;

  valeur&=1; // pour être certain de n'avoir une valeur qu'à exactement 0 ou 1

  // on met le bit à écrire à zéro
  tableau[position_octet] &= ~(1 << position_bit);

  // puis on met la valeur à écrire
  tableau[position_octet] |= (valeur << position_bit); // 1 -> 00....0001
 }


//////////////////////////////
//
// Fonction qui va lire un bit
// dans un tableau (sans faire de
// vérifications de bornes)
//
inline int get_bit(char tableau[], size_t position )
 {
  // même raisonnement que pour set_bit
  size_t position_octet = position / 8;
  size_t position_bit   = position % 8;

  // et on retourne le bit, masqué par 1,
  // pour être certain de ne retourner qu'exactement
  // 0 ou 1.
  return (tableau[position_octet] >> position_bit) & 1;
 }


void show_tab(char tableau[], size_t size_tableau)
{
  std::cout << std::hex << std::setfill('0');
  for (int i=0;i<size_tableau;i++)
   // ici le 0xff est nécessaire pour
   // 1) transformer le char en int et
   // 2) s'assurer qu'il ne soit que sur
   // 8 bits.
   std::cout << std::setw(2) << (tableau[i] & 0xff);
  std::cout<< std::endl;
}

int main()
 {
  const size_t size_tableau=10;
  char tableau[size_tableau]={0};

  show_tab(tableau,size_tableau);

  // faisons des tests sur set_bit et get_bit

  // test écriture pleine
  for (int i=0;i<size_tableau*8;i++) set_bit(tableau,i,1);
  for (int i=0;i<size_tableau*8;i++)
   if (!get_bit(tableau,i))
    {
     std::cerr << "erreur test 1!" << std::endl;
     return 1; // fail sur test 1
    }
  show_tab(tableau,size_tableau);

  // test écriture pair/impair
  for (int i=0;i<size_tableau*8;i++) set_bit(tableau,i,i & 1);
  for (int i=0;i<size_tableau*8;i++)
   if (get_bit(tableau,i)!=(i & 1))
    {
     std::cerr << "erreur test 2!" << std::endl;
     return 2; // fail sur test 2
    }
  show_tab(tableau,size_tableau);

  // test écriture "random"
  std::srand(0);
  for (int i=0;i<size_tableau*8;i++) set_bit(tableau,i, std::rand() & 1);

  std::srand(0);
  for (int i=0;i<size_tableau*8;i++)
   if (get_bit(tableau,i)!=(rand() & 1))
    {
     std::cerr << "erreur test 3!" << std::endl;
     return 3; // fail sur test 3
    }
  show_tab(tableau,size_tableau);

  return 0; // yay! success!
 }
