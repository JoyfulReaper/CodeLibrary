#include "greedyWrap.hpp"

std::string GreedyWrap::lineWrap(std::stringstream &ss)
{
  size_t lineWidth = getLineWidth();
  int spaceLeft = lineWidth;
  
  std::string word;
  while(getWord(ss, word))
  {
    std::cout << word;
  }
  
  
  return "blah";
}

bool GreedyWrap::getWord(std::stringstream &ss, std::string &outWord)
{
  std::string word = "";
  char letter;
  while(ss.good())
  {
    letter = ss.get();
    
    if (letter == ' ')
    {
      outWord = word;
      return true;
    }
    
    word += letter;
  }
  return false;
}