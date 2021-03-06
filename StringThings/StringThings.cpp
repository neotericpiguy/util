#include "StringThings.hpp"

#include <algorithm>
#include <regex>

namespace StringThings {
std::string fixed(double number, unsigned int decimals)
{
  std::stringstream ss;
  ss << std::fixed << std::setprecision(decimals) << number;
  return ss.str();
}

void replaceRegex(std::string& string, const std::string& search, const std::string& replace)
{
  std::regex searchRegex;

  try
  {
    searchRegex = std::regex(search, std::regex::ECMAScript);
  }
  catch (const std::exception& e)
  {
    return;
  }

  string = std::regex_replace(string, searchRegex, replace);
  return;
}

void replace(std::string& str, const std::string& from, const std::string& to)
{
  size_t start_pos = str.find(from);
  while (start_pos != std::string::npos)
  {
    str.replace(start_pos, from.length(), to);
    start_pos = str.find(from, start_pos);
  }
}

std::string rangify(std::vector<int>& vec)
{
  if (vec.size() == 1)
    return std::to_string(vec[0]);

  std::sort(vec.begin(), vec.end());

  std::vector<std::string> result;
  auto vecIter = vec.begin();
  int startRange = *vecIter;
  int rangeCounter = startRange;

  vecIter++;
  for (; vecIter != vec.end(); vecIter++)
  {
    if (*vecIter == rangeCounter + 1)
    {
      rangeCounter++;
      if (vecIter == vec.end() - 1)
      {
        if (startRange != rangeCounter)
          result.push_back(std::to_string(startRange) + "-" + std::to_string(rangeCounter));
        else
          result.push_back(std::to_string(startRange));
      }
    }
    else
    {
      if (startRange != rangeCounter)
        result.push_back(std::to_string(startRange) + "-" + std::to_string(rangeCounter));
      else
        result.push_back(std::to_string(startRange));

      startRange = *vecIter;
      rangeCounter = startRange;

      if (vecIter == vec.end() - 1)
      {
        result.push_back(std::to_string(*vecIter));
      }
    }
  }

  if (result.size())
    return vecToStr(result, ",");
  return "";
}

std::vector<std::string> strToVec(const std::string& vec, char seperator, bool skipEmpty)
{
  if (vec.size() == 0)
    return {};

  std::string tempVal;
  std::istringstream vecStream(vec);
  std::vector<std::string> result;

  while (std::getline(vecStream, tempVal, seperator))
  {
    if (!tempVal.empty() || !skipEmpty)
      result.push_back(tempVal);
  }

  return result;
}

std::vector<int> unrangify(const std::string& range)
{
  std::stringstream ss(range);
  std::vector<int> result;
  int temp;

  if (range == "-")
    return {};
  else if (range.find_first_of(",-") == std::string::npos)
  {
    ss >> temp;
    return {temp};
  }

  while (!ss.eof())
  {
    char c;
    ss >> temp;
    ss >> c;
    if (c == ',')
      result.push_back(temp);
    else if (c == '-')
    {
      int start = temp;
      int end;
      ss >> end;
      for (int i = start; i <= end; i++)
        result.push_back(i);
    }
  }

  return result;
}

bool isNumber(const std::string& string)
{
  if (string.length() == 0)
    return false;
  return string.find_first_not_of("0123456789,-+.") == std::string::npos;
}

void toLower(std::string& str)
{
  std::transform(str.begin(), str.end(), str.begin(),
                 [](unsigned char c) { return std::tolower(c); });
}

}  // namespace StringThings
