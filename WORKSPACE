load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

http_archive(
  name = "gtest",
  urls = ["https://github.com/google/googletest/archive/refs/tags/v1.13.0.zip"],
  strip_prefix = "googletest-1.13.0",
)

http_archive(
  name = "com_google_absl",
  urls = ["https://github.com/abseil/abseil-cpp/archive/refs/tags/20230125.2.zip"],
  strip_prefix = "abseil-cpp-20230125.2",
  sha256 = "2d40102022a01c6f3dddd23ec9ddafff49697a2e4bd09af68bccb74d26ecf64a",
)

http_archive(
  name = "bazel_skylib",
  urls = ["https://github.com/bazelbuild/bazel-skylib/releases/download/1.4.1/bazel-skylib-1.4.1.tar.gz"],
)
