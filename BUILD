cc_library(name = "day1_lib", srcs = ["day1.cc"], hdrs = ["day1.h"], )

    cc_library(name = "day2_lib", srcs = ["day2.cc"],
               deps = [ ":utils_lib", ":log_lib" ], hdrs = ["day2.h"], )

        cc_library(name = "utils_lib", srcs = ["utils.cc"],
                   hdrs = ["utils.h"], )

            cc_library(name = "log_lib", srcs = ["log.cc"], hdrs = ["log.h"], )

                cc_binary(name = "day1", deps = [":day1_lib"],
                          data = ["day1.txt"], )

                    cc_binary(name = "day2", deps = [":day2_lib"],
                              data = ["day2.txt"], )

                        cc_test(name = "day1_test", srcs = ["day1_test.cc"],
                                deps =
                                    [
                                      ":day1_lib",
                                      "@com_google_googletest//:gtest_main"
                                    ], )

                            cc_test(name = "day2_test", srcs = ["day2_test.cc"],
                                    deps =
                                        [
                                          ":day2_lib",
                                          "@com_google_googletest//:gtest_main"
                                        ], )

                                cc_test(name = "utils_test",
                                        srcs = ["utils_test.cc"], deps = [
                                          ":utils_lib",
                                          "@com_google_googletest//:gtest_main"
                                        ], )
