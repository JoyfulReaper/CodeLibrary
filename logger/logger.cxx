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
  setLevel(level);
  setIgnoreLevel(Level::CONFIG);
  addStream(initStream);
}
  
void logger::log(std::string message)
{
  log(getLevel(), message);
}

void logger::log(Level level, std::string message)
{
  if (level <= ignoreLevel) // Not interested in this pirority message
    return;
  
  std::string sLevel;
  
  switch (level)
  {
    case Level::FINE:
      sLevel = "FINE";
      break;
    case Level::CONFIG:
      sLevel = "CONFIG";
      break;
    case Level::INFO:
      sLevel = "INFO";
      break;
    case Level::WARNING:
      sLevel = "WARNING";
      break;
    case Level::ERROR:
      sLevel = "ERROR";
      break;
    case Level::SEVERE:
      sLevel = "SEVERE";
      break;
    default:
      sLevel = "INVALID";
  }
  
  auto it = streams.begin();
  while(it != streams.end())
  {
    **it << "LOGGER(" << name << ":" << sLevel << "): " << message << std::endl;
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

void logger::setIgnoreLevel(Level level)
{
  ignoreLevel = level;
}

Level logger::getIgnoreLevel()
{
  return ignoreLevel;
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