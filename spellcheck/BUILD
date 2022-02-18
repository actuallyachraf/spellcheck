load("@rules_cc//cc:defs.bzl", "cc_binary", "cc_library")

cc_library(
    name = "spell-check",
    srcs = [
        "spell-check.cc",
    ],
    hdrs = [
        "spell-check.h",
    ],
)

cc_library(
    name = "test",
    hdrs = ["test.h"],
)

cc_binary(
    name = "spellcheck-demo",
    srcs = ["main/main.cc"],
    deps = [
        ":spell-check",
        ":test",
    ],
)
