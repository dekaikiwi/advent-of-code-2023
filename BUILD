cc_library(
    name = "day1_lib",
    srcs = ["day1.cc"],
    data = ["day1.txt"],
    hdrs = ["day1.h"],
)

cc_binary(
    name = "day1",
    deps = [":day1_lib"],
)

cc_test(
    name = "day1_test",
    srcs =  ["day1_test.cc"],
    deps = [":day1_lib", "@com_google_googletest//:gtest_main"],
)

