load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
    name = "libs",
    srcs = glob(["*.cpp"]),
    hdrs = glob(["*.h"]),
    visibility = ["//visibility:public"],
    deps = ["//libs/std"],
)
