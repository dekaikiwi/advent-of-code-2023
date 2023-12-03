#include "day1.h"
#include <gtest/gtest.h>

TEST(Day1Test, ReturnsNumbersFromWords) {
  EXPECT_EQ("12", createNumberFromFirstLastDigitInString("1abc2"));
  EXPECT_EQ("38", createNumberFromFirstLastDigitInString("pqr3stu8vwx"));
  EXPECT_EQ("15", createNumberFromFirstLastDigitInString("a1b2c3d4e5f"));
  EXPECT_EQ("77", createNumberFromFirstLastDigitInString("treb7uchet"));
}

TEST(Day1Test, ReturnsNumberFromWordsWithNumberWords) {
  EXPECT_EQ("29", createNumberFromFirstLastDigitInString("two1nine"));
  EXPECT_EQ("83", createNumberFromFirstLastDigitInString("eightwothree"));
  EXPECT_EQ("13", createNumberFromFirstLastDigitInString("abcone2threexyz"));
  EXPECT_EQ("24", createNumberFromFirstLastDigitInString("xtwone3four"));
  EXPECT_EQ("42", createNumberFromFirstLastDigitInString("4nineeightseven2"));
  EXPECT_EQ("14", createNumberFromFirstLastDigitInString("zoneight234"));
  EXPECT_EQ("76", createNumberFromFirstLastDigitInString("7pqrstsixteen"));
  EXPECT_EQ("21", createNumberFromFirstLastDigitInString("twone"));
  EXPECT_EQ("47", createNumberFromFirstLastDigitInString(
                      "fourseven8fkjdsfgjskfourseven"));
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
