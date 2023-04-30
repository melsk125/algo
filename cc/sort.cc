#include <iostream>
#include <vector>

#include "cc/sort.h"

namespace cc {

void InsertionSort(std::vector<int>& input) {
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

// Utils for MergeSort
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

void MergeSort(std::vector<int>& input) {
  if (input.size() <= 1) {
    return;
  }
  MergeSortIter(input, 0, input.size());
}

// Utils for HeapSort
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

void HeapSort(std::vector<int>& input) {
  HeapSortImpl(input);
}

}  // namespace cc
