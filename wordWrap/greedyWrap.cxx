#include "greedyWrap.hpp"

// TODO: Probably need to strip tabs (/t) maybe others
// FIXME: The last word is not processed

static const size_t SPACE_WIDTH = 1;

std::string GreedyWrap::lineWrap(std::stringstream &ss)
{
  size_t lineWidth = getLineWidth();
  int spaceLeft = lineWidth;
  
  std::string output;
  std::string word;
  while(getWord(ss, word))
  {
    if( (word.length() + SPACE_WIDTH) > spaceLeft)
    {
      output += "\n";
      output += word;
      output += " ";
      spaceLeft = (lineWidth - word.length());
    } else {
      spaceLeft -= (word.length() + SPACE_WIDTH);
      output += word;
      output += " ";
    }
  }
  
  
  return output;
}

bool GreedyWrap::getWord(std::stringstream &ss, std::string &outWord)
{
  std::string word = "";
  char letter;
  while( ss.good() )
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