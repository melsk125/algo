#include "cc/string-utils.h"

#include "absl/strings/str_cat.h"
#include "absl/strings/str_join.h"

namespace cc {

namespace string_utils {

std::string PrintVector(const std::vector<int>& input) {
  return absl::StrCat("{", absl::StrJoin(input, ","), "}");
}

}  // namespace string_utils

}  // namespace cc
