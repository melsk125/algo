load("@rules_cc//cc:defs.bzl", "cc_library", "cc_test")

cc_library(
    name = "string-utils",
    hdrs = ["string-utils.h"],
    srcs = ["string-utils.cc"],
    visibility = ["//cc:__pkg__"],
    deps = [
        "@com_google_absl//absl/strings",
    ],
)

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
        "@gtest//:gtest_main",
        ":sort",
        ":string-utils",
    ],
    size = "small",
)
