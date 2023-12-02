#include <gtest/gtest.h>
#include "day1.h"

TEST(Day1Test, ReturnsNumbersFromWords) {
    EXPECT_EQ("12", createNumberFromFirstLastDigitInString("1abc2"));
    EXPECT_EQ("38", createNumberFromFirstLastDigitInString("pqr3stu8vwx"));
    EXPECT_EQ("15", createNumberFromFirstLastDigitInString("a1b2c3d4e5f"));
    EXPECT_EQ("77", createNumberFromFirstLastDigitInString("treb7uchet"));
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}


