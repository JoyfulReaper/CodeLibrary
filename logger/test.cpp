#include <iostream>
#include <fstream>
#include "logger.hpp"

int main()
{
  logger log("test");
  
  log.addStream(std::cout);
  log.log("test.cpp");
  
  log.removeStream(std::cout);
  log.log("test2");
  
  log.removeStream(std::cout);
  std::cout << std::endl;
  
  ///////////////////////////////////////////////////
  
  logger log2("log2");
  log2.log(Level::INFO, "INFO");
  log2.log("NOTINFO");
  
  ///////////////////////////////////////////////////
  
  std::ofstream fout;
  fout.open("test.file", std::ofstream::out | std::ofstream::app);
  logger flog("flog", Level::WARNING, fout);
  flog.log("file log");
  return 0;
}