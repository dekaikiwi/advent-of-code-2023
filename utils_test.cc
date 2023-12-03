#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "utils.h"

using ::testing::ElementsAre;

TEST(Utils, SplitString) {
    ASSERT_THAT(split("foo bar bazz", " "), ElementsAre("foo", "bar", "bazz"));
}

TEST(Utils, TrimString) {
    ASSERT_EQ("foo", trim_string(" foo "));
    ASSERT_EQ("foo bar bazz", trim_string("foo bar bazz   "));
    ASSERT_EQ("foo", trim_string(" foo"));
    ASSERT_EQ("foo", trim_string("foo"));
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}


