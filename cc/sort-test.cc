#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

#include "absl/strings/str_cat.h"
#include "absl/strings/str_join.h"
#include "gmock/gmock.h"
#include "cc/sort.h"

using ::testing::ElementsAre;
using ::testing::ElementsAreArray;

struct SortInstance {
  const std::vector<int> input;
  const std::vector<int> expected;
};

const std::vector<std::function<void(std::vector<int>&)>> SORT_FUNCTIONS =
    {cc::InsertionSort, cc::MergeSort};

std::string PrintVector(const std::vector<int>& input) {
  return absl::StrCat("{", absl::StrJoin(input, ","), "}");
}

void DoSortTest(SortInstance instance,
                std::function<void(std::vector<int>&)> sort) {
  std::vector<int> input;
  std::copy(instance.input.begin(),
            instance.input.end(),
            std::back_inserter(input));

  sort(input);
  std::cout << "   input: " << PrintVector(instance.input) << std::endl;
  std::cout << "  output: " << PrintVector(input) << std::endl;
  std::cout << "expected: " << PrintVector(instance.expected) << std::endl;
  EXPECT_THAT(input, ElementsAreArray(instance.expected));
}

void DoAllSortTests(SortInstance instance) {
  for (auto sort : SORT_FUNCTIONS) {
    DoSortTest(instance, sort);
  }
}

TEST(SortTest, DoTest) {
  std::vector<SortInstance> instances = {
    {{}, {}},
    {{2}, {2}},
    {{0, 2}, {0, 2}},
    {{5, 2, 4, 6, 1, 3}, {1, 2, 3, 4, 5, 6}},
    {{31, 41, 59, 26, 41, 58}, {26, 31, 41, 41, 58, 59}},
  };
  for (auto instance : instances) {
    DoAllSortTests(instance);
  }
}
