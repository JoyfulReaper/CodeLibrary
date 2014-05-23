#include <iostream>
#include "logger.hpp"

int main()
{
  logger log("test");
  
  log.addStream(std::cout);
  log.log("test.cpp");
  
  log.removeStream(std::cout);
  log.log("test2");
  
  log.removeStream(std::cout);
  
  
  ///////////////////////////////////////////////////
  
  
  return 0;
}