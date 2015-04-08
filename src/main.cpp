#include <iostream>

#include "Dictionnary.hh"

int error_usage(const char *binary) {
  std::cerr << "Usage : " << binary << " Dictionnary" << std::endl;
  return 1;
}

int main(int ac, char **av) {
  if (ac != 2)
    return error_usage(av[0]);
  Dictionnary dict(av[1]);
  dict.load();
  std::cout << "Dictionnary : " << dict <<std::endl;
  return 0;
}
