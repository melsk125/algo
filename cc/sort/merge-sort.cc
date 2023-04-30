#include "cc/sort/merge-sort.h"

#include <vector>

namespace cc {
namespace sort {

namespace {

void Merge(std::vector<int>& input, int begin, int mid, int end) {
  std::vector<int> left_array(mid - begin, 0);
  std::vector<int> right_array(end - mid, 0);
  for (int index = 0; index < left_array.size(); index ++) {
    left_array[index] = input[begin + index];
  }
  for (int index = 0; index < right_array.size(); index ++) {
    right_array[index] = input[mid + index];
  }
  int left_index = 0;
  int right_index = 0;
  int input_index = begin;
  while (left_index < left_array.size() && right_index < right_array.size()) {
    if (left_array[left_index] <= right_array[right_index]) {
      input[input_index] = left_array[left_index];
      left_index ++;
    } else {
      input[input_index] = right_array[right_index];
      right_index ++;
    }
    input_index ++;
  }
  while (left_index < left_array.size()) {
    input[input_index] = left_array[left_index];
    left_index ++;
    input_index ++;
  }
  while (right_index < right_array.size()) {
    input[input_index] = right_array[right_index];
    right_index ++;
    input_index ++;
  }
}

void MergeSortIter(std::vector<int>& input, int begin, int end) {
  if (end - begin <= 1) {
    return;
  }
  int mid = (begin + end) / 2;
  MergeSortIter(input, begin, mid);
  MergeSortIter(input, mid, end);
  Merge(input, begin, mid, end);
}

}  // namespace

void MergeSorter::Sort(std::vector<int>& input) {
  if (input.size() <= 1) {
    return;
  }
  MergeSortIter(input, 0, input.size());
}

}  // namespace sort
}  //  namespace cc
