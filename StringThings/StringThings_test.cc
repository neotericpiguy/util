#include "StringThings.hpp"

#include <gtest/gtest.h>

TEST(TestStringThings, fixed)
{
  EXPECT_EQ("1.0", StringThings::fixed(1, 1));
  EXPECT_EQ("1.12", StringThings::fixed(1.123, 2));
}

TEST(TestStringThings, replaceRegex)
{
  std::string test = "how now brown cow";

  StringThings::replaceRegex(test, "n.w", "asd");
  EXPECT_EQ(test, "how asd brown cow");

  StringThings::replaceRegex(test, "brown.*", "");
  EXPECT_EQ(test, "how asd ");
}

TEST(TestStringThings, replace)
{
  std::string test = "how now brown cow";

  StringThings::replace(test, "now", "asd");
  EXPECT_EQ(test, "how asd brown cow");

  StringThings::replace(test, "brown", "");
  EXPECT_EQ(test, "how asd  cow");
}

TEST(TestStringThings, rangify)
{
  std::vector<int> test = {1, 2, 3, 4, 5};
  EXPECT_EQ("1-5", StringThings::rangify(test));

  test = {1, 2, 3, 5};
  EXPECT_EQ("1-3,5", StringThings::rangify(test));

  test = {8, 1, 2, 3, 5};
  EXPECT_EQ("1-3,5,8", StringThings::rangify(test));
}

TEST(TestStringThings, strToVec)
{
  std::string test = "1,2,3,4,5";
  std::vector<std::string> result = {"1", "2", "3", "4", "5"};
  EXPECT_EQ(result, StringThings::strToVec(test, ','));
}

TEST(TestStringThings, vecToStr)
{
  std::vector<std::string> test = {"1", "2", "3", "4", "5"};
  std::string result = "1,2,3,4,5";
  EXPECT_EQ(result, StringThings::vecToStr(test, ","));
}

TEST(TestStringThings, strTo)
{
  int result;
  StringThings::strTo(result, "1");
  EXPECT_EQ(result, 1);

  EXPECT_FALSE(StringThings::strTo(result, "asdf"));
}

TEST(TestStringThings, isNumber)
{
  EXPECT_FALSE(StringThings::isNumber("asdf"));
  EXPECT_TRUE(StringThings::isNumber("1"));
  EXPECT_TRUE(StringThings::isNumber("-1"));
  EXPECT_TRUE(StringThings::isNumber("-1.0"));
}

TEST(TestStringThings, toLower)
{
  std::string test = "ASDF";
  StringThings::toLower(test);
  EXPECT_EQ(test, "asdf");

  test = "ASDF123";
  StringThings::toLower(test);
  EXPECT_EQ(test, "asdf123");
}
