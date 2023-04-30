#include "cc/sort/heap-sort.h"

#include <vector>

namespace cc {
namespace sort {

namespace {
int Parent(int index) {
  if (index <= 0) {
    return 0;
  }
  return (index - 1) / 2;
}

int Left(int index) {
  return index * 2 + 1;
}

int Right(int index) {
  return index * 2 + 2;
}

void MaxHeapify(std::vector<int>& input, int index, int heap_size) {
  int left_index = Left(index);
  int right_index = Right(index);
  int largest_index = index;
  if (left_index < heap_size && input[left_index] > input[largest_index]) {
    largest_index = left_index;
  }
  if (right_index < heap_size && input[right_index] > input[largest_index]) {
    largest_index = right_index;
  }
  if (largest_index != index) {
    int temp = input[index];
    input[index] = input[largest_index];
    input[largest_index] = temp;
    MaxHeapify(input, largest_index, heap_size);
  }
}

void BuildMaxHeap(std::vector<int>& input) {
  int heap_size = input.size();
  for (int i = Parent(heap_size - 1); i >= 0; i--) {
    MaxHeapify(input, i, heap_size);
  }
}

void HeapSortImpl(std::vector<int>& input) {
  BuildMaxHeap(input);
  for (int i = input.size() - 1; i >= 1; i--) {
    int temp = input[0];
    input[0] = input[i];
    input[i] = temp;
    MaxHeapify(input, 0, i);
  }
}
}  // namespace

void HeapSorter::Sort(std::vector<int>& input) {
  HeapSortImpl(input);
}

}  // namespace sort
}  //  namespace cc
