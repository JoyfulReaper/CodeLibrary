/**
* @file logger.cxx
* @author Kyle Givler
* 
* Provide logging mechanism
*/

#include "logger.hpp"

logger::logger(std::string name, Level level, std::ostream &initStream)
{
  this->name = name;
  this->logLevel = level;
  addStream(initStream);
}
  
void logger::log(std::string message)
{
  log(getLevel(), message);
}

void logger::log(Level level, std::string message)
{
  if (!(level >= logLevel)) // Not interested in this pirority message
    return;
  
  auto it = streams.begin();
  while(it != streams.end())
  {
    **it << message << std::endl;
    ++it;
  }
}

void logger::setLevel(Level level)
{
  this->logLevel = level;
}

Level logger::getLevel() const
{
  return logLevel;
}
  
std::string logger::getName() const
{
  return name;
}
  
bool logger::addStream(std::ostream &o)
{
  streams.push_back(&o);
  return true;
}

bool logger::removeStream(std::ostream &o)
{
  auto it = streams.begin();
  while (it != streams.end())
  {
    if (*it == &o)
    {
      streams.erase(it);
      return true;
    }
    ++it;
  }
  return false;
}

void logger::enable()
{
  enabled = true;
}

void logger::disable()
{
  enabled = false;
}

bool logger::isEnabled()
{
  return enabled;
}