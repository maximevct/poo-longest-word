#ifndef __SORT_HH__
#define __SORT_HH__

#include <map>

class Sort {
private:
public:
  static std::map<char, int> letterWeight;
  Sort() {}
  ~Sort() {}

  bool operator()(const char a, const char b) {
    return Sort::letterWeight[a] > Sort::letterWeight[b];
  }

};

#endif
