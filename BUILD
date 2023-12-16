load("@com_github_bazelbuild_buildtools//buildifier:def.bzl", "buildifier")

buildifier(
    name = "buildifier",
)

cc_library(
    name = "day1_lib",
    srcs = ["day1.cc"],
    hdrs = ["day1.h"],
)

cc_library(
    name = "day2_lib",
    srcs = ["day2.cc"],
    hdrs = ["day2.h"],
    deps = [
        ":log_lib",
        ":utils_lib",
    ],
)

cc_library(
    name = "utils_lib",
    srcs = ["utils.cc"],
    hdrs = ["utils.h"],
)

cc_library(
    name = "log_lib",
    srcs = ["log.cc"],
    hdrs = ["log.h"],
)

cc_binary(
    name = "day1",
    data = ["day1.txt"],
    deps = [":day1_lib"],
)

cc_binary(
    name = "day2",
    data = ["day2.txt"],
    deps = [":day2_lib"],
)

cc_test(
    name = "day1_test",
    srcs = ["day1_test.cc"],
    deps =
        [
            ":day1_lib",
            "@com_google_googletest//:gtest_main",
        ],
)

cc_test(
    name = "day2_test",
    srcs = ["day2_test.cc"],
    deps =
        [
            ":day2_lib",
            "@com_google_googletest//:gtest_main",
        ],
)

cc_test(
    name = "utils_test",
    srcs = ["utils_test.cc"],
    deps = [
        ":utils_lib",
        "@com_google_googletest//:gtest_main",
    ],
)
