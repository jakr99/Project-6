#include "MyMap.h"
#include "test_utils.hpp"
#include <ctime>
#include <map>
#include <stdlib.h>

int main(const int argc, const char **argv) {
  return test_wrapper(argc, argv, []() {
    time_t seed;
    srand(time(&seed));

    std::map<std::string, int> test_map;
    MyMap<std::string, int> your_map;

    // Bracket op adds new elements
    int r = rand() % 50;
    your_map["a"] = r;
    try {
      if (your_map.at("a") != r)
        return false;
    } catch (...) {
      return false;
    }

    // Bracket op doesn't create duplicates
    your_map["a"] = r + 1;
    if (your_map.size() != 1)
      return false;
    int test_val = your_map["a"];
    if (test_val != r + 1)
      return false;

    // TODO: multiple (~5) bracket ins test

    return true;
  });
}
