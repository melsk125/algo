load("@rules_cc//cc:defs.bzl", "cc_library", "cc_test")

cc_library(
  name = "sort",
  hdrs = ["sort.h"],
  visibility = ["//cc:__pkg__"],
)

cc_library(
  name = "insertion-sort",
  hdrs = ["insertion-sort.h"],
  srcs = ["insertion-sort.cc"],
  visibility = ["//cc:__pkg__"],
  deps = [
    ":sort"
  ],
)

cc_library(
  name = "merge-sort",
  hdrs = ["merge-sort.h"],
  srcs = ["merge-sort.cc"],
  visibility = ["//cc:__pkg__"],
  deps = [
    ":sort"
  ],
)

cc_library(
  name = "heap-sort",
  hdrs = ["heap-sort.h"],
  srcs = ["heap-sort.cc"],
  visibility = ["//cc:__pkg__"],
  deps = [
    ":sort"
  ],
)

cc_test(
  name = "sort-test",
  srcs = ["sort-test.cc"],
  copts = ["-Iexternal/gtest/include"],
  deps = [
    ":heap-sort",
    ":insertion-sort",
    ":merge-sort",
    ":sort",
    "@gtest//:gtest_main",
    "//cc:string-utils",
  ],
  size = "small",
)
