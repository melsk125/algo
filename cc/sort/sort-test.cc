#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

#include "gmock/gmock.h"
#include "cc/sort/heap-sort.h"
#include "cc/sort/insertion-sort.h"
#include "cc/sort/merge-sort.h"
#include "cc/string-utils.h"

using ::testing::ElementsAre;
using ::testing::ElementsAreArray;

struct SortInstance {
  const std::vector<int> input;
  const std::vector<int> expected;
};

// const std::vector<::cc::sort::Sorter> SORT_FUNCTIONS =
//     {::cc::sort::InsertionSorter};

void DoSortTest(SortInstance instance, ::cc::sort::Sorter* sorter) {
  std::vector<int> input;
  std::copy(instance.input.begin(),
            instance.input.end(),
            std::back_inserter(input));

  sorter->Sort(input);
  std::cout << "   input: " << cc::string_utils::PrintVector(instance.input)
      << std::endl;
  std::cout << "  output: " << cc::string_utils::PrintVector(input)
      << std::endl;
  std::cout << "expected: " << cc::string_utils::PrintVector(instance.expected)
      << std::endl;
  EXPECT_THAT(input, ElementsAreArray(instance.expected));
}

void DoAllSortTests(SortInstance instance,
                    std::vector<::cc::sort::Sorter*>& sorters) {
  for (auto sorter : sorters) {
    DoSortTest(instance, sorter);
  }
}

TEST(SortTest, DoTest) {
  std::vector<::cc::sort::Sorter*> sorters;
  ::cc::sort::InsertionSorter insertion_sorter;
  ::cc::sort::MergeSorter merge_sorter;
  ::cc::sort::HeapSorter heap_sorter;
  sorters.push_back(&insertion_sorter);
  sorters.push_back(&merge_sorter);
  sorters.push_back(&heap_sorter);
  std::vector<SortInstance> instances = {
    {{}, {}},
    {{2}, {2}},
    {{0, 2}, {0, 2}},
    {{5, 2, 4, 6, 1, 3}, {1, 2, 3, 4, 5, 6}},
    {{31, 41, 59, 26, 41, 58}, {26, 31, 41, 41, 58, 59}},
  };
  for (auto instance : instances) {
    DoAllSortTests(instance, sorters);
  }
}
