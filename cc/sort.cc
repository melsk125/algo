#include <iostream>
#include <vector>

#include "cc/sort.h"

namespace cc {

void InsertionSort(std::vector<int>& input) {
  for (int i = 1; i < input.size(); i++) {
    int key = input.at(i);
    int j = i - 1;
    while (j >= 0 && input.at(j) > key) {
      input[j + 1] = input[j];
      j--;
    }
    input[j + 1] = key;
  }
}

}  // namespace cc
