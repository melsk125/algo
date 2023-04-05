#include "gmock/gmock.h"
#include "cc/sort.h"

using ::testing::ElementsAre;

TEST(SortTest, InsertionSort) {
  std::vector<int> input = {5, 2, 4, 6, 1, 3};
  cc::InsertionSort(input);
  EXPECT_THAT(input, ElementsAre(1, 2, 3, 4, 5, 6));
}
