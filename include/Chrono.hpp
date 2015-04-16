#ifndef __CHRONO_HPP__
#define __CHRONO_HPP__

#include <chrono>

class Chrono {
public:
  std::chrono::high_resolution_clock::time_point t1;
  std::chrono::high_resolution_clock::time_point t2;
  Chrono() {}
  ~Chrono() {}

  void start() {
    t1 = std::chrono::high_resolution_clock::now();
  }

  void stop() {
    t2 = std::chrono::high_resolution_clock::now();
  }

  int getMilliseconds() {
    return std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count();
  }

  int getMicroseconds() {
    return std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
  }
};

#endif
