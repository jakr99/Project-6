#include "MyMap.h"
#include "test_utils.hpp"
#include <ctime>
#include <map>
#include <stdlib.h>
#include <string>

int main(const int argc, const char **argv) {
  return test_wrapper(argc, argv, []() {
    time_t seed;
    srand(time(&seed));

    std::map<std::string, int> test_map;
    MyMap<std::string, int> your_map;

    // new map is empty
    if (your_map.empty() == false)
      return false;

    // maps with elements are non-empty
    your_map.begin() = new TreeNode<std::string, int>("a", 1);
    if (your_map.empty() == true)
      return false;

    return true;
  });
}
