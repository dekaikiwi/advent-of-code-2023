#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "day2.h"

using ::testing::ElementsAre;
using ::testing::UnorderedElementsAre;
using ::testing::Pair;

TEST(Day2Test, parseGameFromString) {
    string game1 = "Game 1: 3 blue, 4 red; 1 red, 2 green, 6 blue; 2 green";

    EXPECT_EQ(1, get<0>(parseGameFromString(game1)));
    ASSERT_THAT(get<1>(parseGameFromString(game1)), 
            UnorderedElementsAre(UnorderedElementsAre(
                    Pair("blue", 3), Pair("red", 4)
            ), UnorderedElementsAre(
                    Pair("red", 1), Pair("green", 2), Pair("blue", 6)
            ), UnorderedElementsAre(
                    Pair("green", 2), Pair("blue", 6), Pair("red", 1))));
}

TEST(Day2Test, LowestRequiredSetOfBlocks) {
    ASSERT_THAT(lowestRequiredSetOfBlocks(
                get<1>(
                    parseGameFromString(
                        "Game 1: 3 blue, 4 red; 1 red, 2 green, 6 blue; 2 green"
                ))), UnorderedElementsAre(
                    Pair("blue", 6), Pair("red", 4), Pair("green", 2)
                ));
    
    ASSERT_THAT(lowestRequiredSetOfBlocks(
                get<1>(
                    parseGameFromString(
                        "Game 2: 1 blue, 2 green; 3 green, 4 blue, 1 red; 1 green, 1 blue"
                ))), UnorderedElementsAre(
                    Pair("blue", 4), Pair("red", 1), Pair("green", 3)
                ));
}

TEST(Day2Test, isGamePossible) {
    map<string, int> blocks = {
        {"blue", 14},
        {"red", 12},
        {"green", 13}
    };

    EXPECT_TRUE(isGamePossible(
                get<1>(
                    parseGameFromString(
                        "Game 1: 3 blue, 4 red; 1 red, 2 green, 6 blue; 2 green"
                )), blocks));
    
    EXPECT_TRUE(isGamePossible(
                get<1>(
                    parseGameFromString(
                        "Game 2: 1 blue, 2 green; 3 green, 4 blue, 1 red; 1 green, 1 blue"
                )), blocks));

    EXPECT_FALSE(isGamePossible(
                get<1>(
                    parseGameFromString(
                        "Game 3: 8 green, 6 blue, 20 red; 5 blue, 4 red, 13 green; 5 green, 1 red"
                )), blocks));

    EXPECT_FALSE(isGamePossible(
                get<1>(
                    parseGameFromString(
                        "Game 4: 1 green, 3 red, 6 blue; 3 green, 6 red; 3 green, 15 blue, 14 red"
                )), blocks));

    EXPECT_TRUE(isGamePossible(
                get<1>(
                    parseGameFromString(
                        "Game 5: 6 red, 1 blue, 3 green; 2 blue, 1 red, 2 green"
                )), blocks));
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}


