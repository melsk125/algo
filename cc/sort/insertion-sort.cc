#include "cc/sort/insertion-sort.h"

#include <vector>

namespace cc {
namespace sort {

void InsertionSorter::Sort(std::vector<int>& input) {
  for (int key_index = 1; key_index < input.size(); key_index++) {
    int key = input.at(key_index);
    int insert_location = key_index - 1;
    while (insert_location >= 0 && input.at(insert_location) > key) {
      input[insert_location + 1] = input[insert_location];
      insert_location--;
    }
    input[insert_location + 1] = key;
  }
}

}  // namespace sort
}  //  namespace cc
