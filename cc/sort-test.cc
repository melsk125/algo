#include <algorithm>
#include <iterator>
#include <vector>

#include "gmock/gmock.h"
#include "cc/sort.h"

using ::testing::ElementsAre;
using ::testing::ElementsAreArray;

struct SortInstance {
  const std::vector<int> input;
  const std::vector<int> expected;
};

void DoSortTest(SortInstance instance) {
  std::vector<int> input;
  std::copy(instance.input.begin(),
            instance.input.end(),
            std::back_inserter(input));

  cc::InsertionSort(input);
  EXPECT_THAT(input, ElementsAreArray(instance.expected));
}

TEST(SortTest, DoTest) {
  std::vector<SortInstance> instances = {
    {{5, 2, 4, 6, 1, 3}, {1, 2, 3, 4, 5, 6}},
    {{31, 41, 59, 26, 41, 58}, {26, 31, 41, 41, 58, 59}}
  };
}
