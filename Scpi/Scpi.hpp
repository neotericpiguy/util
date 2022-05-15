#ifndef SCPI_HPP
#define SCPI_HPP

#include <sstream>
#include <string>
#include <vector>

class Scpi
{
public:
  Scpi(const std::string& scpi);
  Scpi(const Scpi&) = delete;
  Scpi& operator=(const Scpi& env) = delete;
  ~Scpi();

  const std::string& getScpiStr() const;
  void setScpiStr(const std::string& val);

  const std::vector<std::string>& getParams() const;
  void setParams(const std::vector<std::string>& val);

  const std::string& getCommand() const;
  void setCommand(const std::string& val);

  const std::vector<std::string>& getSubsystems() const;
  void setSubSystem(const std::vector<std::string>& val);

  template <typename T>
  bool getParam(T& retval, unsigned int index) const
  {
    if (index >= getParams().size())
      return false;

    auto tempStr = getParams().at(index);
    std::istringstream iss(tempStr);

    iss >> retval;
    if (iss.fail())
      return false;
    return true;
  }

private:
  std::string mScpiStr;
  std::vector<std::string> mParams;
  std::string mCommand;
  std::vector<std::string> mSubsystem;
};

#endif
