#ifndef CC_SORT_MERGE_SORT_H_
#define CC_SORT_MERGE_SORT_H_

#include <vector>

#include "cc/sort/sort.h"

namespace cc {
namespace sort {

class MergeSorter : public Sorter {
 public:
  void Sort(std::vector<int>& input) override;
};

}  // namespace sort
}  //  namespace cc

#endif
