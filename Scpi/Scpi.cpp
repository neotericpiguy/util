#include "Scpi.hpp"

#include "StringThings.hpp"

Scpi::Scpi(const std::string& scpi) :
    mScpiStr(scpi),
    mParams(),
    mCommand(),
    mSubsystem()

{
  auto vec = StringThings::strToVec(mScpiStr, ' ');
  mParams = std::vector(vec.begin() + 1, vec.end());
  mCommand = vec.front();

  vec = StringThings::strToVec(mCommand, ':');
  mSubsystem = std::vector(vec.begin(), vec.end() - 1);
  mCommand = vec.back();
}

Scpi::~Scpi()
{
}

const std::string& Scpi::getScpiStr() const
{
  return mScpiStr;
}
void Scpi::setScpiStr(const std::string& val)
{
  mScpiStr = val;
}

const std::vector<std::string>& Scpi::getParams() const
{
  return mParams;
}
void Scpi::setParams(const std::vector<std::string>& val)
{
  mParams = val;
}

const std::string& Scpi::getCommand() const
{
  return mCommand;
}
void Scpi::setCommand(const std::string& val)
{
  mCommand = val;
}

const std::vector<std::string>& Scpi::getSubsystems() const
{
  return mSubsystem;
}
void Scpi::setSubSystems(const std::vector<std::string>& val)
{
  mSubsystem = val;
}

