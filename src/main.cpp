#include <iostream>

#include "Game.hh"

int error_usage(const char *binary) {
  std::cerr << "Usage : " << binary << " DictionnaryFile" << std::endl;
  return 1;
}

int main(int ac, char **av) {
  if (ac != 2)
    return error_usage(av[0]);
  Game g;
  g.launch();
  return 0;
}
