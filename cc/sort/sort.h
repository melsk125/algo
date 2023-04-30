#ifndef CC_SORT_SORT_H_
#define CC_SORT_SORT_H_

#include <vector>

namespace cc {
namespace sort {

class Sorter {
 public:
  virtual void Sort(std::vector<int>& input) = 0;
};

}  // namespace sort
}  //  namespace cc

#endif