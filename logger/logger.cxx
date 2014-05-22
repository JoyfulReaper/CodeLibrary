/**
* @file logger.cxx
* @author Kyle Givler
* 
* Provide logging mechanism
*/

#include <iostream>
#include "logger.hpp"

logger::logger(std::string name, size_t maxStreams, std::ostream &initStream)
{
  this->name = name;
  this->maxStreams = maxStreams;
  addStream(initStream);
}
  
void logger::log(std::string message)
{
}

void logger::log(Level level, std::string message)
{
}
  
void logger::setLevel(Level level)
{
}

Level logger::getLevel()
{
}
  
Level logger::ignoreLevel(Level level)
{
}
  
std::string logger::getName()
{
  return name;
}
  
bool logger::addStream(std::ostream &o)
{
  return false;
}

bool logger::removeStream(std::ostream &o)
{
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