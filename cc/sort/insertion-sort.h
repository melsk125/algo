#ifndef CC_SORT_INSERTION_SORT_H_
#define CC_SORT_INSERTION_SORT_H_

#include <vector>

#include "cc/sort/sort.h"

namespace cc {
namespace sort {

class InsertionSorter : public Sorter {
 public:
  void Sort(std::vector<int>& input) override;
};

}  // namespace sort
}  //  namespace cc

#endif
