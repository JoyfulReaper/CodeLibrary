#ifndef _GREEDY_WRAP_H
#define _GREEDY_WRAP_H

#include <string>
#include <sstream>
#include <iostream>

class GreedyWrap
{
public:
  GreedyWrap(size_t lineWidth = 80) : lineWidth(lineWidth) {}
  
  void setLineWidth(size_t width) { lineWidth = width; }
  size_t getLineWidth() { return lineWidth; }
  
  std::string lineWrap(std::stringstream &ss);
  
  bool getWord(std::stringstream &ss, std::string &outWord);
  
private:
  size_t lineWidth;
};

#endif