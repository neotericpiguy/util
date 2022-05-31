#include "Scpi.hpp"

#include <gtest/gtest.h>

TEST(TestScpi, getScpiStr)
{
  std::string test = "SYSTEM:TEST";

  Scpi scpi(test);
  EXPECT_EQ(test, scpi.getScpiStr());

  test = "SYSTEM:TEST2";
  scpi.setScpiStr(test);
  EXPECT_EQ(test, scpi.getScpiStr());
}

TEST(TestScpi, getParams)
{
  std::string test = "SYSTEM:TEST 1 2 3 4";
  std::vector<std::string> result = {"1", "2", "3", "4"};

  Scpi scpi(test);
  EXPECT_EQ(result, scpi.getParams());

  std::vector<std::string> result2 = {"4", "3", "2", "1"};
  scpi.setParams(result2);
  EXPECT_EQ(result2, scpi.getParams());
}

TEST(TestScpi, getCommand)
{
  std::string test = "SYSTEM:TEST 1 2 3 4";
  std::string result = "TEST";

  Scpi scpi(test);
  EXPECT_EQ(result, scpi.getCommand());

  result = "TEST2";
  scpi.setCommand(result);
  EXPECT_EQ(result, scpi.getCommand());
}

TEST(TestScpi, getSubsystems)
{
  std::string test = "SYSTEM:SUBSYSTEM:TEST 1 2 3 4";
  std::vector<std::string> result = {"SYSTEM", "SUBSYSTEM"};

  Scpi scpi(test);
  EXPECT_EQ(result, scpi.getSubsystems());

  result = {"SYSTEM", "SUBSYSTEM", "SUBSUBSYSTEM"};
  scpi.setSubSystems(result);
  EXPECT_EQ(result, scpi.getSubsystems());
}

TEST(TestScpi, getParam)
{
  std::string test = "SYSTEM:SUBSYSTEM:TEST 1 2 3 4 asdf";

  Scpi scpi(test);

  int result;
  scpi.getParam(result, 0);
  EXPECT_EQ(result, 1);
  scpi.getParam(result, 1);
  EXPECT_EQ(result, 2);
  EXPECT_FALSE(scpi.getParam(result, 4));

  std::string resultStr;
  scpi.getParam(resultStr, 1);
  EXPECT_EQ(resultStr, "2");
}
