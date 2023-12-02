cc_binary(
    name = "day1",
    srcs = ["day1.cc"],
    data = ["day1.txt"],
    # hdrs = ["day1.h"],
)

cc_test(
    name = "day1_test",
    srcs =  ["day1_test.cc"],
    deps = [":day1", "@com_google_googletest//:gtest_main"],
)

