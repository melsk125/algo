load("@rules_cc//cc:defs.bzl", "cc_library", "cc_test")

cc_library(
    name = "sort",
    hdrs = ["sort.h"],
    srcs = ["sort.cc"],
    visibility = ["//cc:__pkg__"],
)

cc_test(
    name = "sort-test",
    srcs = ["sort-test.cc"],
    copts = ["-Iexternal/gtest/include"],
    deps = [
        "@com_google_absl//absl/strings",
        "@gtest//:gtest_main",
        ":sort",
    ],
    size = "small",
)
